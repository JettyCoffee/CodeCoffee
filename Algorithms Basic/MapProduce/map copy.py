import tkinter as tk
from tkinter import filedialog
import matplotlib.pyplot as plt
import os

# 从文件中读取数据
def read_data(filename):
    data = {}
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split()
            x = float(parts[0])
            y = float(parts[1])
            if x not in data:
                data[x] = []
            data[x].append(y)
    return data

# 计算平均值
def calculate_average(data):
    averaged_data = {}
    for x, y_values in data.items():
        averaged_data[x] = sum(y_values) / len(y_values)
    return averaged_data

# 画折线图
def plot_graph(data, title):
    sorted_data = dict(sorted(data.items()))
    x_values = [x / list(sorted_data.keys())[0] for x in sorted_data.keys()]
    y_values = sorted_data.values()
    plt.plot(x_values, y_values)
    plt.xlabel('X Axis')
    plt.ylabel('Y Axis')
    plt.title(title)
    plt.show()

# 主函数
def main():
    root = tk.Tk()
    root.withdraw()  # 隐藏主窗口

    # 打开文件选择对话框
    filename = filedialog.askopenfilename(title="选择数据文件")

    if filename:
        data = read_data(filename)
        averaged_data = calculate_average(data)
        title = os.path.basename(filename)  # 使用文件名作为标题
        plot_graph(averaged_data, title)

if __name__ == "__main__":
    main()
