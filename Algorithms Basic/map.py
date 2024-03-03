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

# 打开文件对话框并获取文件名
filename = filedialog.askopenfilename(title="选择数据文件", filetypes=(("Text files", "*.txt"), ("All files", "*.*")))

if filename:
    # 读取数据
    title = os.path.basename(filename)
    x, y = read_data(filename)

    # 绘制折线图和数据点
    plt.plot(x, y, marker='o', linestyle='-')
    plt.scatter(x, y, color='red')
    plt.xlabel('N')
    plt.ylabel('Time Cost')
    plt.title(title)
    plt.show()
else:
    print("没有选择文件。")
