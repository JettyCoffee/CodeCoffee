import math
import matplotlib.pyplot as plt
import numpy as np
# 设置中文字体
plt.rcParams['font.sans-serif'] = ['HarmonyOS Sans SC']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

map_redirection = ["成都","都江堰","映秀","汶川","理县","马尔康","壤塘","翁达","色达",
                    "甘孜","马尼干戈","新路海","德格","江达","白玉","巴塘","理塘","新龙",
                    "炉霍","道孚","雅江","八美","塔公","新都桥","丹巴","金川","康定",
                    "泸定","小金","日隆","天全","雅安"]

# 城市索引映射
f = {city: index for index, city in enumerate(map_redirection)}

# 初始化距离矩阵
dist = [[math.inf for _ in range(len(map_redirection))] for _ in range(len(map_redirection))]
for i in range(len(map_redirection)):
    dist[i][i] = 0

dist[f["成都"]][f["都江堰"]] = 50;
dist[f["都江堰"]][f["成都"]] = 50;
dist[f["成都"]][f["雅安"]] = 140;
dist[f["雅安"]][f["成都"]] = 140;
dist[f["都江堰"]][f["映秀"]] = 42;
dist[f["映秀"]][f["都江堰"]] = 42;
dist[f["映秀"]][f["汶川"]] = 57;
dist[f["汶川"]][f["映秀"]] = 57;
dist[f["汶川"]][f["理县"]] = 57;
dist[f["理县"]][f["汶川"]] = 57;
dist[f["理县"]][f["马尔康"]] = 144;
dist[f["马尔康"]][f["理县"]] = 144;
dist[f["映秀"]][f["日隆"]] = 140;
dist[f["日隆"]][f["映秀"]] = 140;
dist[f["日隆"]][f["小金"]] = 52;
dist[f["小金"]][f["日隆"]] = 52;
dist[f["小金"]][f["丹巴"]] = 58;
dist[f["丹巴"]][f["小金"]] = 58;
dist[f["丹巴"]][f["金川"]] = 92;
dist[f["金川"]][f["丹巴"]] = 92;
dist[f["马尔康"]][f["金川"]] = 90;
dist[f["金川"]][f["马尔康"]] = 90;
dist[f["马尔康"]][f["壤塘"]] = 194;
dist[f["壤塘"]][f["马尔康"]] = 194;
dist[f["马尔康"]][f["翁达"]] = 194;
dist[f["翁达"]][f["马尔康"]] = 194;
dist[f["翁达"]][f["壤塘"]] = 79;
dist[f["壤塘"]][f["翁达"]] = 79;
dist[f["金川"]][f["翁达"]] = 202;
dist[f["翁达"]][f["金川"]] = 202;
dist[f["雅安"]][f["天全"]] = 40;
dist[f["天全"]][f["雅安"]] = 40;
dist[f["天全"]][f["泸定"]] = 168;
dist[f["泸定"]][f["天全"]] = 168;
dist[f["丹巴"]][f["泸定"]] = 133;
dist[f["泸定"]][f["丹巴"]] = 133;
dist[f["丹巴"]][f["康定"]] = 112;
dist[f["康定"]][f["丹巴"]] = 112;
dist[f["泸定"]][f["康定"]] = 49;
dist[f["康定"]][f["泸定"]] = 49;
dist[f["康定"]][f["新都桥"]] = 75;
dist[f["新都桥"]][f["康定"]] = 75;
dist[f["新都桥"]][f["塔公"]] = 35;
dist[f["塔公"]][f["新都桥"]] = 35;
dist[f["塔公"]][f["八美"]] = 28;
dist[f["八美"]][f["塔公"]] = 28;
dist[f["八美"]][f["丹巴"]] = 83;
dist[f["丹巴"]][f["八美"]] = 83;
dist[f["八美"]][f["道孚"]] = 83;
dist[f["道孚"]][f["八美"]] = 83;
dist[f["道孚"]][f["炉霍"]] = 78;
dist[f["炉霍"]][f["道孚"]] = 78;
dist[f["翁达"]][f["色达"]] = 83;
dist[f["色达"]][f["翁达"]] = 83;
dist[f["甘孜"]][f["色达"]] = 158;
dist[f["色达"]][f["甘孜"]] = 158;
dist[f["甘孜"]][f["炉霍"]] = 97;
dist[f["炉霍"]][f["甘孜"]] = 97;
dist[f["甘孜"]][f["新龙"]] = 107;
dist[f["新龙"]][f["甘孜"]] = 107;
dist[f["道孚"]][f["雅江"]] = 202;
dist[f["雅江"]][f["道孚"]] = 202;
dist[f["雅江"]][f["新都桥"]] = 71;
dist[f["新都桥"]][f["雅江"]] = 71;
dist[f["雅江"]][f["理塘"]] = 135;
dist[f["理塘"]][f["雅江"]] = 135;
dist[f["理塘"]][f["新龙"]] = 153;
dist[f["新龙"]][f["理塘"]] = 153;
dist[f["甘孜"]][f["马尼干戈"]] = 95;
dist[f["马尼干戈"]][f["甘孜"]] = 95;
dist[f["马尼干戈"]][f["新路海"]] = 9;
dist[f["新路海"]][f["马尼干戈"]] = 9;
dist[f["新路海"]][f["德格"]] = 115;
dist[f["德格"]][f["新路海"]] = 115;
dist[f["德格"]][f["江达"]] = 93;
dist[f["江达"]][f["德格"]] = 93;
dist[f["白玉"]][f["德格"]] = 99;
dist[f["德格"]][f["白玉"]] = 99;
dist[f["巴塘"]][f["白玉"]] = 195;
dist[f["白玉"]][f["巴塘"]] = 195;
dist[f["白玉"]][f["甘孜"]] = 242;
dist[f["甘孜"]][f["白玉"]] = 242;
dist[f["巴塘"]][f["理塘"]] = 180;
dist[f["理塘"]][f["巴塘"]] = 180;

# Dijkstra算法实现
def find_min_dis_dijkstra(site_matrix, start):
    n = len(site_matrix)
    visited = [False] * n
    pre = [-1] * n
    dis = [math.inf] * n
    dis[start] = 0

    for _ in range(n):
        u = -1
        min_dis = math.inf
        for i in range(n):
            if not visited[i] and dis[i] < min_dis:
                u = i
                min_dis = dis[i]
        if u == -1: break
        visited[u] = True
        for v in range(n):
            if not visited[v] and site_matrix[u][v] != math.inf and dis[u] + site_matrix[u][v] < dis[v]:
                dis[v] = dis[u] + site_matrix[u][v]
                pre[v] = u
    return dis, pre

# 从成都到江达的最短路径
dis, pre = find_min_dis_dijkstra(dist, f["成都"])
print("成都到江达的最短距离是：", dis[f["江达"]])

# 打印路径函数
def print_path(pre, start, end):
    path = []
    while end != start: # 从终点开始回溯
        path.append(map_redirection[end]) # 将城市加入路径
        end = pre[end] # 更新终点
    path.append(map_redirection[start])
    path.reverse()
    return '->'.join(path)

# 打印成都到江达的最短路径
print("成都到江达的最短路径是：", print_path(pre, f["成都"], f["江达"]))

# 问题2：张三把理塘列为必游之地。怎么规划路线，使得总行程最短？
# 首先找到成都到理塘的最短路径，然后找到理塘到江达的最短路径
dis_from_litang, pre_from_litang = find_min_dis_dijkstra(dist, f["理塘"]) 
dis_to_litang, pre_to_litang = find_min_dis_dijkstra(dist, f["成都"])
total_distance = dis_to_litang[f["理塘"]] + dis_from_litang[f["江达"]]
print("通过理塘的最短距离是：", total_distance)
print("成都到理塘再到江达的最短路径是：", print_path(pre_to_litang, f["成都"], f["理塘"]) + "->" + print_path(pre_from_litang, f["理塘"], f["江达"]))

# 问题3：张三觉得理塘风景很美，道孚也不错，两个地方如果能够去一个地方的话就心满意足了。应该怎么安排行程使得总行程最短？
# 分别计算通过理塘和道孚的总距离，然后比较哪个更短
dis_from_daofu, pre_from_daofu = find_min_dis_dijkstra(dist, f["道孚"])
total_distance_litang = dis_to_litang[f["理塘"]] + dis_from_litang[f["江达"]]
total_distance_daofu = dis_to_litang[f["道孚"]] + dis_from_daofu[f["江达"]]
if total_distance_litang < total_distance_daofu:
    print("通过理塘的路线更短。")
    print("成都到理塘到江达的最短路径是：", print_path(pre_to_litang, f["成都"], f["理塘"]) + "->" + print_path(pre_from_litang, f["理塘"], f["江达"]))
else:
    print("通过道孚的路线更短。")
    print("成都到道孚到江达的最短路径是：", print_path(pre_to_litang, f["成都"], f["道孚"]) + "->" + print_path(pre_from_daofu, f["道孚"], f["江达"]))

# 问题4：用时最短的路径是哪一条？
# 假设粗路径平均时速80公里/小时，细路径平均时速60公里/小时
# 需要将距离转换为时间，然后使用Dijkstra算法计算最短时间
time_matrix = [[math.inf for _ in range(len(map_redirection))] for _ in range(len(map_redirection))]
for i in range(len(map_redirection)):
    for j in range(len(map_redirection)):
        if dist[i][j] != math.inf:
            # 假设所有路径初始为粗路径
            time_matrix[i][j] = dist[i][j] / 80.0

time_matrix[f["道孚"]][f["雅江"]] = dist[f["道孚"]][f["雅江"]] / 60.0
time_matrix[f["理塘"]][f["新龙"]] = dist[f["理塘"]][f["新龙"]] / 60.0
time_matrix[f["甘孜"]][f["新龙"]] = dist[f["甘孜"]][f["新龙"]] / 60.0
time_matrix[f["色达"]][f["甘孜"]] = dist[f["色达"]][f["甘孜"]] / 60.0
time_matrix[f["白玉"]][f["甘孜"]] = dist[f["白玉"]][f["甘孜"]] / 60.0
time_matrix[f["巴塘"]][f["白玉"]] = dist[f["巴塘"]][f["白玉"]] / 60.0
time_matrix[f["白玉"]][f["德格"]] = dist[f["白玉"]][f["德格"]] / 60.0

# 使用Dijkstra算法找到用时最短的路径
dis_time, pre_time = find_min_dis_dijkstra(time_matrix, f["成都"])
print("成都到江达用时最短的距离是：", dis_time[f["江达"]], "小时")
print("成都到江达用时最短的路径是：", print_path(pre_time, f["成都"], f["江达"]))


# 双向Dijkstra算法实现
def bidirectional_dijkstra(site_matrix, start, end):
    n = len(site_matrix)
    # 初始化
    visited_start = [False] * n
    visited_end = [False] * n
    dis_start = [math.inf] * n
    dis_end = [math.inf] * n
    dis_start[start] = 0
    dis_end[end] = 0
    pre_start = [-1] * n
    pre_end = [-1] * n

    while True:
        # 从起点开始的搜索
        u_start = -1
        min_dis_start = math.inf
        for i in range(n):
            if not visited_start[i] and dis_start[i] < min_dis_start:
                u_start = i
                min_dis_start = dis_start[i]
        if u_start == -1: break
        visited_start[u_start] = True

        # 从终点开始的搜索
        u_end = -1
        min_dis_end = math.inf
        for i in range(n):
            if not visited_end[i] and dis_end[i] < min_dis_end:
                u_end = i
                min_dis_end = dis_end[i]
        if u_end == -1: break
        visited_end[u_end] = True

        # 更新距离
        for v in range(n):
            if not visited_start[v] and site_matrix[u_start][v] != math.inf and dis_start[u_start] + site_matrix[u_start][v] < dis_start[v]:
                dis_start[v] = dis_start[u_start] + site_matrix[u_start][v]
                pre_start[v] = u_start
            if not visited_end[v] and site_matrix[u_end][v] != math.inf and dis_end[u_end] + site_matrix[u_end][v] < dis_end[v]:
                dis_end[v] = dis_end[u_end] + site_matrix[u_end][v]
                pre_end[v] = u_end

        # 检查是否相遇
        if visited_start[u_end] or visited_end[u_start]:
            break

    # 找到相遇点
    meet_point = None
    for i in range(n):
        if visited_start[i] and visited_end[i]:
            meet_point = i
            break

    # 如果没有相遇点，返回无穷大
    if meet_point is None:
        return math.inf, []

    # 构建最短路径
    path_start = print_path(pre_start, start, meet_point)
    path_end = print_path(pre_end, end, meet_point)
    # 因为两个路径都包含相遇点，所以需要去掉一个
    path = path_start + path_end.split('->', 1)[1]
    return dis_start[meet_point] + dis_end[meet_point], path

# 使用双向Dijkstra算法找到成都到江达的最短路径
dis, path = bidirectional_dijkstra(dist, f["成都"], f["江达"])
print("成都到江达的最短距离是：", dis)
print("成都到江达的最短路径是：", path)
