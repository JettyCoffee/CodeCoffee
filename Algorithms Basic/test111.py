import pandas as pd
import folium
import networkx as nx
from geopy.distance import geodesic
import sys
import random
import colorsys

# 增加递归深度限制
sys.setrecursionlimit(10000)

# 读取基站位置文件
base_stations = pd.read_csv('E:/CodeCoffee/Algorithms Basic/station.csv')
devices = pd.read_csv('E:/CodeCoffee/Algorithms Basic/devices.csv')

# 初始化图
G = nx.Graph()
device_count = 0

# 添加设备节点
for index, info in devices.iterrows():
    G.add_node(index, pos=(info['latitude'], info['longitude']), type='device')
    device_count += 1

# 添加基站节点
for index, info in base_stations.iterrows():
    G.add_node(index+device_count, pos=(info['latitude'], info['longitude']), type='base_station')

# 定义最大通信距离
MAX_DISTANCE = 10.0

# 连接设备与可通信基站
for device_index, device_info in devices.iterrows():
    for base_index, base_info in base_stations.iterrows():
        distance = geodesic((device_info['latitude'], device_info['longitude']),
                            (base_info['latitude'], base_info['longitude'])).km
        if distance <= MAX_DISTANCE:
            G.add_edge(device_index, base_index + device_count)
            # 给添加的设备添加已连接的属性
            G.nodes[device_index]['connected'] = True
    if 'connected' not in G.nodes[device_index]:
        # 如果设备没有连接到任何基站，则连接到距离最近的基站
        min_distance = float('inf')
        nearest_base = None
        for base_index, base_info in base_stations.iterrows():
            distance = geodesic((device_info['latitude'], device_info['longitude']),
                                (base_info['latitude'], base_info['longitude'])).km
            if distance < min_distance:
                min_distance = distance
                nearest_base = base_index
        G.add_edge(device_index, nearest_base + device_count)

# 遍历所有基站，如果两个设备连接到同一个基站，则为这两个设备之间添加边
for base_index, base_info in base_stations.iterrows():
    connected_devices = [n for n in G.neighbors(base_index + device_count) if G.nodes[n]['type'] == 'device']
    for i, device1 in enumerate(connected_devices):
        for device2 in connected_devices[i+1:]:
            G.add_edge(device1, device2)

cliques = []
# 定义深度优先搜索最大团函数
def dfs_max_clique(graph, nodes):
    max_clique = []
    stack = [(nodes, [])] # 用栈来保存搜索状态
    
    while stack:
        remaining, current_clique = stack.pop() # 弹出栈顶元素
        if not remaining:
            if len(current_clique) > len(max_clique):
                max_clique = current_clique
        else:
            n = remaining[0]
            neighbors = set(graph.neighbors(n))
            new_remaining = [m for m in remaining if m in neighbors]
            stack.append((new_remaining, current_clique + [n]))
            stack.append((remaining[1:], current_clique))
    
    return max_clique


# 遍历所有基站，找到最大团
for base_index, base_info in base_stations.iterrows():
    connected_devices = [n for n in G.neighbors(base_index + device_count) if G.nodes[n]['type'] == 'device']
    # 把基站也加入到子图中
    connected_devices.append(base_index + device_count)
    subgraph = G.subgraph(connected_devices)  # 生成子图
    max_clique = dfs_max_clique(subgraph, connected_devices)
    cliques.append(max_clique)

# 可视化
m = folium.Map(location=[devices['latitude'].mean(), devices['longitude'].mean()], zoom_start=12)

def generate_random_color():
    h = random.random()
    s = 0.9  # 高饱和度
    l = 0.5  # 中等亮度
    rgb = colorsys.hls_to_rgb(h, l, s)
    return f'#{int(rgb[0]*255):02x}{int(rgb[1]*255):02x}{int(rgb[2]*255):02x}'

# 将不同的团用不同颜色标记
for i, clique in enumerate(cliques):
    if not clique:  # 如果当前基站没有形成团，则跳过
        continue
    node_color = generate_random_color()
    folium.CircleMarker(location=(G.nodes[i+device_count]['pos'][0], G.nodes[i+device_count]['pos'][1]), radius=5, color='black', fill=False).add_to(m)
    for node in clique:
        folium.CircleMarker(location=(G.nodes[node]['pos'][0], G.nodes[node]['pos'][1]), radius=5, color=node_color, fill=True).add_to(m)
        # 当前选择的设备连接到基站
        folium.PolyLine(locations=[(G.nodes[node]['pos'][0], G.nodes[node]['pos'][1]),
                                    (G.nodes[i+device_count]['pos'][0], G.nodes[i+device_count]['pos'][1])], color=node_color).add_to(m)

m.save('E:/CodeCoffee/Algorithms Basic/map_cliques.html')