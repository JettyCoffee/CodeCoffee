import tkinter as tk
from tkinter import filedialog
import matplotlib.pyplot as plt
from collections import defaultdict
import os

def read_data(filename):
    # 读取txt文件
    with open(filename, 'r') as file:
        data = file.readlines()

    # 提取x和y的值
    xy_dict = defaultdict(list)
    for line in data:
        values = line.split()
        x_val = float(values[0])
        y_val = float(values[1])
        xy_dict[x_val].append(y_val)

    # 计算每个x值对应的平均y值
    x_values = []
    y_values = []
    for x_val, y_list in xy_dict.items():
        x_values.append(x_val)
        y_values.append(sum(y_list) / len(y_list))

    # 确保x轴递增排序
    sorted_data = sorted(zip(x_values, y_values))
    x_values = [item[0] for item in sorted_data]
    y_values = [item[1] for item in sorted_data]

    return x_values, y_values

# 创建tkinter窗口
root = tk.Tk()
root.withdraw()  # 隐藏主窗口

# 打开第一个文件对话框并获取文件名
filename1 = filedialog.askopenfilename(title="选择第一个数据文件", filetypes=(("Text files", "*.txt"), ("All files", "*.*")))

# 打开第二个文件对话框并获取文件名
#filename2 = filedialog.askopenfilename(title="选择第二个数据文件", filetypes=(("Text files", "*.txt"), ("All files", "*.*")))


    # 读取数据
title1 = os.path.basename(filename1)
#title2 = os.path.basename(filename2)
x1, y1 = read_data(filename1)
#x2, y2 = read_data(filename2)

    # 绘制折线图和数据点
plt.plot(x1, y1, marker='o', linestyle='-', label=title1)
#plt.plot(x2, y2, marker='o', linestyle='-', label=title2)
plt.xlabel('Size')
plt.ylabel('Time Cost(s)')
#plt.title("Comparison of Two Algorithms Time Cost")
plt.title("HeapSort Time Cost - Size")
plt.legend()
plt.show()
