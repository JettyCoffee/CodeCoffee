location = ([1,"沈阳市",123.429092,41.796768],
            [2,"长春市",125.324501,43.886841],
            [3,"哈尔滨市",126.642464,45.756966],
            [4,"北京市",116.405289,39.904987],
            [5,"天津市",117.190186,39.125595],
            [6,"呼和浩特市",111.751990,40.841490],
            [7,"银川市",106.232480,38.486440],
            [8,"太原市",112.549248,37.857014],
            [9,"石家庄市",114.502464,38.045475],
            [10,"济南市",117.000923,36.675808],
            [11,"郑州市",113.665413,34.757977],
            [12,"西安市",108.948021,34.263161],
            [13,"乌鲁木齐市",87.616880,43.826630],
            [14,"西宁市",101.777820,36.617290],
            [15,"兰州市",103.834170,36.061380],

            [16,"南京市",118.76741,32.041546],
            [17,"合肥市",117.283043,31.861191],
            [18,"上海市",121.472641,31.231707],
            [19,"长沙市",112.982277,28.19409],
            [20,"南昌市",115.892151,28.676493],
            [21,"杭州市",120.15358,30.287458],
            [22,"福州市",119.306236,26.075302],
            [23,"广州市",113.28064,23.125177],
            [24,"台北市",121.5200760,25.0307240],
            [25,"海口市",110.199890,20.044220],
            [26,"南宁市",108.320007,22.82402],
            [27,"重庆市",106.504959,29.533155],
            [28,"昆明市",102.71225,25.040609],
            [29,"贵阳市",106.713478,26.578342],
            [28,"成都市",104.065735,30.659462],
            [31,"拉萨市",91.11450,29.644150],
            [32,"武汉市",114.298569,30.584354],
            [33,"香港",114.165460,22.275340],
            [34,"澳门",113.549130,22.198750] )
import math
import matplotlib.pyplot as plt
import numpy as np
# 设置中文字体
plt.rcParams['font.sans-serif'] = ['HarmonyOS Sans SC']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

def haversine(location1, location2):
    # 
    lon1, lat1, lon2, lat2 = map(math.radians, [location1[2], location1[3], location2[2], location2[3]])
    d_lon = lon2 - lon1 
    d_lat = lat2 - lat1 
    a = math.sin(d_lat/2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(d_lon/2)**2
    c = 2 * math.asin(math.sqrt(a)) 
    r = 6371 
    distance = c * r
    return distance

distance_matrix = [[0]*len(location) for i in range(len(location))] # 生成一个二维数组
for i in range(len(location)):
    for j in range(len(location)):
        distance_matrix[i][j] = haversine(location[i], location[j])

def prim_distance(distance_matrix, location): 
    n = len(distance_matrix)
    cost = [99999]*n
    closest = [0]*n
    cost[0] = 0
    for i in range(1, n):
        cost[i] = distance_matrix[0][i] # 记录V0到Vi的权值
        closest[i] = 0 # 记录V0到Vi的最小权值边的另一端点
    sum = 0
    min_spanning_tree_edges = []  # 记录最小生成树的边
    for i in range(1, n): # 生成n-1条边
        min = 99999
        j = 1 # j记录最小权值的边
        k = 0 # k记录最小权值的边的另一端点
        while j < n: 
            # 遍历以找到最小权值的边
            if cost[j] != 0 and cost[j] < min: 
                min = cost[j]
                k = j 
            j += 1
        min_spanning_tree_edges.append((closest[k], k))  # 记录当前选择的边
        sum += distance_matrix[closest[k]][k] # 累加权值
        cost[k] = 0 # 顶点k加入生成树，去除顶点j与k之间的边，数据置0
        for j in range(1, n):
            if cost[j] != 0 and distance_matrix[k][j] < cost[j]: # 更新cost和closest
                cost[j] = distance_matrix[k][j] # 更新最小权值
                closest[j] = k # 更新最小权值边的另一端点
    return min_spanning_tree_edges,sum

# 调用 prim_distance 函数
min_spanning_tree_edges,sum = prim_distance(distance_matrix, location)

# 可视化电网拓扑结构以及最小生成树的边
plt.figure(figsize=(10, 8))
for i, loc in enumerate(location):
    plt.scatter(loc[2], loc[3], color='b')
    plt.text(loc[2], loc[3], loc[1], fontsize=8, ha='right')
for edge in min_spanning_tree_edges:
    city1 = location[edge[0]][1]
    city2 = location[edge[1]][1]
    distance = distance_matrix[edge[0]][edge[1]]
    plt.plot([location[edge[0]][2], location[edge[1]][2]], [location[edge[0]][3], location[edge[1]][3]], 'r--')
plt.title(f'国家电网超高压网络规划电网数据图\n最小总长度: {sum:.2f} km')
plt.xlabel('经度')
plt.ylabel('纬度')
plt.legend()
plt.grid(True)
plt.show()