# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
plt.rcParams['font.family'] = 'HarmonyOS Sans SC'


# 生成示例数据
x1 = [1000, 2000, 3000, 4000, 4600]
y1 = [0.002427,0.002521,0.002645,0.003797,0.002425]
y2 = [0.005300,0.005631,0.005007,0.005511,0.004015]
y3 = [0.024758,0.031260,0.023234,0.025208,0.023365]

# 创建图形并设置标题
plt.figure()
plt.title('Three Data Sets')

# 绘制三个数据集的折线图
plt.plot(x1, y1, label='Random_Select', marker='o')
plt.plot(x1, y2, label='Select_Result', marker='s')
plt.plot(x1, y3, label='QuickSort_Result', marker='d')

# 添加图例
plt.legend()

# 添加坐标轴标签
plt.xlabel("寻找第x小的元素(n)")
plt.ylabel("时间消耗(s)")

# 显示图形
plt.grid(True)
plt.show()
