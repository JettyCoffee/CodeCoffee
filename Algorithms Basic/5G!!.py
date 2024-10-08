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



# 定义DFS算法找到所有最大团
def dfs_cliques(current_clique, candidates, excluded, cliques):
    if not candidates and not excluded:
        cliques.append(current_clique[:])
        return
    for node in candidates[:]:
        new_candidates = [n for n in candidates if G.has_edge(node, n)] # 只保留与当前节点相连的节点
        new_excluded = [n for n in excluded if G.has_edge(node, n)] 
        current_clique.append(node) # 将当前节点添加到团中
        dfs_cliques(current_clique, new_candidates, new_excluded, cliques) # 递归
        current_clique.pop() # 回溯
        candidates.remove(node) # 将当前节点从候选节点中移除
        excluded.append(node) # 将当前节点添加到排除节点中

# 找到所有最大团
cliques = []
dfs_cliques([], list(G.nodes), [], cliques)

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
    station_index = clique[len(clique)-1]
    folium.CircleMarker(location=(G.nodes[station_index]['pos'][0], G.nodes[station_index]['pos'][1]), radius=5, color='black', fill=False).add_to(m)
    for node in clique:
        folium.CircleMarker(location=(G.nodes[node]['pos'][0], G.nodes[node]['pos'][1]), radius=5, color=node_color, fill=True).add_to(m)
        # 当前选择的设备连接到基站
        folium.PolyLine(locations=[(G.nodes[node]['pos'][0], G.nodes[node]['pos'][1]),
                                    (G.nodes[station_index]['pos'][0], G.nodes[station_index]['pos'][1])], color=node_color).add_to(m)

m.save('E:/CodeCoffee/Algorithms Basic/map_cliques.html')