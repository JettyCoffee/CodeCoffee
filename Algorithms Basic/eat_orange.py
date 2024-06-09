def max_eat_oranges(orange):
    days = len(orange)
    total_eaten = 0
    eaten_orange = 0
    for day in range(0, days):
        orange[day][1] += day # 记录橙子的过期时间
    orange.sort(key=lambda x: x[1]) # 按照过期时间排序
    for day in range(0, orange[days-1][1]+1):
        for check_day in range(eaten_orange, day):
            if orange[check_day][0] >= 0 and orange[check_day][1] >= day: # 如果橙子还没过期
                total_eaten += 1 # 吃掉一个橙子
                orange[check_day][0] -= 1 # 橙子减少一个
                eaten_orange = check_day
                break
    return total_eaten


with open("E:\CodeCoffee\Algorithms Basic\oranges.txt", 'r') as file:
        lines = file.readlines() # 读取文件中的所有行
        group = len(lines)-1 # 一共有多少组
        for i in range(group): # 遍历每一组
            group_size = (int)(lines[i].strip().split()[0])
            good_day_matrix = [[0] * 2 for _ in range(group_size)]
            for j in range(0, group_size):
                good_day_matrix[j][0] = list(map(int, lines[i].strip().split()))[j+1]
                good_day_matrix[j][1] = list(map(int, lines[i].strip().split()))[j+1+group_size]
            print(f"MaxOrange(Group{i+1}) : {max_eat_oranges(good_day_matrix)}") # 输出最大吃橙子数