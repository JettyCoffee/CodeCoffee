import pandas as pd
import folium
import networkx as nx
from geopy.distance import geodesic
import sys

# 增加递归深度限制
sys.setrecursionlimit(10000)

# 读取基站位置文件
base_stations = pd.read_csv('E:/CodeCoffee/Algorithms Basic/station.csv')
devices = pd.read_csv('E:/CodeCoffee/Algorithms Basic/devices.csv')

# 初始化图
G = nx.Graph()

# 添加设备节点
for index, info in devices.iterrows():
    G.add_node(info['id'], pos=(info['latitude'], info['longitude']), type='device')

# 添加基站节点
for index, info in base_stations.iterrows():
    G.add_node(info['id'], pos=(info['latitude'], info['longitude']), type='base_station')

# 定义最大通信距离
MAX_DISTANCE = 10.0

m_original = folium.Map(location=[devices['latitude'].mean(), devices['longitude'].mean()], zoom_start=12)
for index, info in devices.iterrows():
    folium.CircleMarker(location=(info['latitude'], info['longitude']), radius=5, color='blue', fill=True).add_to(m_original)
for index, info in base_stations.iterrows():
    folium.CircleMarker(location=(info['latitude'], info['longitude']), radius=5, color='black', fill=True).add_to(m_original)
for device_index, device_info in devices.iterrows():
    for base_index, base_info in base_stations.iterrows():
        distance = geodesic((device_info['latitude'], device_info['longitude']),
                            (base_info['latitude'], base_info['longitude'])).km
        if distance <= MAX_DISTANCE:
            folium.PolyLine(locations=[(device_info['latitude'], device_info['longitude']),
                                       (base_info['latitude'], base_info['longitude'])], color='blue').add_to(m_original)
m_original.save('E:/CodeCoffee/Algorithms Basic/map_original.html')

# 连接设备与可通信基站
for device_index, device_info in devices.iterrows():
    for base_index, base_info in base_stations.iterrows():
        distance = geodesic((device_info['latitude'], device_info['longitude']),
                            (base_info['latitude'], base_info['longitude'])).km
        if distance <= MAX_DISTANCE:
            G.add_edge(device_info['id'], base_info['id'])

# 为没有连接任何一个基站的设备添加距离最近的基站
for device_index, device_info in devices.iterrows():
    if not list(G.neighbors(device_info['id'])): #
        min_distance = float('inf')
        nearest_base_station = None
        for base_index, base_info in base_stations.iterrows():
            distance = geodesic((device_info['latitude'], device_info['longitude']),
                                (base_info['latitude'], base_info['longitude'])).km
            if distance < min_distance:
                min_distance = distance
                nearest_base_station = base_info['id']
        G.add_edge(device_info['id'], nearest_base_station)

# 如果两个设备连接到同一个基站，则它们之间也是相互连接的
for base_index, base_info in base_stations.iterrows():
    # 获取连接到当前基站的设备
    connected_devices = [node for node in G.neighbors(base_info['id']) if G.nodes[node]['type'] == 'device']
    for i in range(len(connected_devices)):
        for j in range(i + 1, len(connected_devices)):
            G.add_edge(connected_devices[i], connected_devices[j])





# 使用DFS算法找最大团
def dfs(graph, node, visited, clique):
    visited.add(node)
    clique.append(node)
    for neighbor in graph.neighbors(node):
        if neighbor not in visited:
            dfs(graph, neighbor, visited, clique)

def find_max_clique(graph):
    max_clique = []
    nodes = list(graph.nodes)
    for node in nodes:
        visited = set()
        clique = []
        dfs(graph, node, visited, clique)
        if len(clique) > len(max_clique):
            max_clique = clique
    return max_clique

# 找到所有基站节点的最大团
max_cliques = []
for base_node in base_stations['id']:
    if G.has_node(base_node):
        max_clique = find_max_clique(G.subgraph([base_node] + list(G.neighbors(base_node))))
        max_cliques.append(max_clique)

# 在地图上可视化
m = folium.Map(location=[devices['latitude'].mean(), devices['longitude'].mean()], zoom_start=12)

colors = ['red', 'blue', 'green', 'purple', 'orange', 'darkred', 'lightred', 'beige', 'darkblue',
          'darkgreen', 'cadetblue', 'darkpurple', 'white', 'pink', 'lightblue', 'lightgreen',
          'gray', 'black', 'lightgray']

for i, clique in enumerate(max_cliques):
    color = colors[i % len(colors)]
    # 筛选出设备和基站节点
    device_nodes = [node for node in clique if G.nodes[node]['type'] == 'device']
    base_station_nodes = [node for node in clique if G.nodes[node]['type'] == 'base_station']
    
    # 画设备节点
    for device in device_nodes:
        node_data = G.nodes[device]
        folium.CircleMarker(location=node_data['pos'], radius=5, color=color, fill=True).add_to(m)
    
    # 画基站节点
    for base_station in base_station_nodes:
        base_station_data = G.nodes[base_station]
        folium.CircleMarker(location=base_station_data['pos'], radius=5, color='black', fill=True).add_to(m)

    # 画设备和基站之间的连线
    for device in device_nodes:
        node_data = G.nodes[device]
        for base_station in base_station_nodes:
            if G.has_edge(device, base_station):
                base_station_data = G.nodes[base_station]
                folium.PolyLine(locations=[node_data['pos'], base_station_data['pos']], color=color).add_to(m)

# 保存地图
m.save('E:/CodeCoffee/Algorithms Basic/map.html')
