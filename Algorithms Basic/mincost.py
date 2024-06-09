def greedy(cost_matrix):
    number = len(cost_matrix) # 一共有多少人
    cost_city1 = 0 # 城市1的总费用
    delta = [0] * number # 城市2的费用减去城市1的费用
    for i in range(number):
        cost_city1 += cost_matrix[i][0] # 去a地的费用
        delta[i] = cost_matrix[i][1] - cost_matrix[i][0] # 去b地的费用减去去a地的费用
    delta.sort() # 对delta进行排序
    for i in range(number//2):
        cost_city1 += delta[i] # 依次分配
    return cost_city1

with open("E:\CodeCoffee\Algorithms Basic\costs.txt", 'r') as file:
        lines = file.readlines() # 读取文件中的所有行
        group = len(lines)-1 # 一共有多少组
        for i in range(group): # 遍历每一组
            group_size = len(lines[i].strip().split()) # 每组有多少人
            cost_matrix = [[0] * 2 for _ in range(group_size//2)] # 初始化费用矩阵
            for j in range(0, (group_size//2)): # 遍历每个人
                cost_matrix[j] = list(map(int, lines[i].strip().split()))[j*2:j*2+2]
            print(f"MinCost(Group{i+1}) : {greedy(cost_matrix)}") # 输出最小费用