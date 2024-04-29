'''
Author: JettyCoffee jetty_coffee@outlook.com
Date: 2024-03-30 23:00:17
LastEditors: JettyCoffee jetty_coffee@outlook.com
LastEditTime: 2024-04-13 16:26:16
FilePath: \CodeCoffee\Algorithms Basic\figure.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
plt.rcParams['font.family'] = 'HarmonyOS Sans SC'


# 生成示例数据
x1 = [5,10,50,100,500,1000,2500,5000]
y1 = [0.01150,0.02891,0.105148,0.26766,1.012399,2.28971,5.2015,10.17384]
#y2 = [0.0000981,0.0001237,0.0001510,0.0001487]
#y3 = [0.0001136,0.0001305,0.0001787,0.0001801]
#for i in range(0,2):
#    y1[i] = (y1[i] + y2[i] + y3[i])/3

# 创建图形并设置标题
plt.figure()
plt.title('Time Cost of Finding LCS(NEW)')

# 绘制三个数据集的折线图
plt.plot(x1, y1, marker='o')
#plt.plot(x1, y2, label='Select_Result', marker='s')
#plt.plot(x1, y3, label='QuickSort_Result', marker='d')

# 添加图例
plt.legend()

# 添加坐标轴标签
plt.xlabel("随机字符串的长度（26个大写字母）")
plt.ylabel("时间消耗(s)")

# 显示图形
plt.grid(True)
plt.show()
