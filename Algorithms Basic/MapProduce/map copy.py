import tkinter as tk
from tkinter import filedialog
import os

import matplotlib.pyplot as plt

# 读取数据
def read_data():
    data = {}
    add_times = [0.000008, 0.000185, 0.000833, 0.001643, 0.002969]  # Example addTime values
    remove_times = [0.000008, 0.000185, 0.000833, 0.001643, 0.002969]  # Example removeTime values
    data_size = [50, 250, 500, 750, 1000]  # Example Data Quantity values

    for i in range(len(data_size)):
        x = data_size[i]
        y_add = float(add_times[i])
        y_remove = float(remove_times[i])

        if x not in data:
            data[x] = {"addTime": [], "removeTime": []}
        data[x]["addTime"].append(y_add)
        data[x]["removeTime"].append(y_remove)


    return data

# 计算平均值
def calculate_average(data):
    averaged_data = {}
    for x, times in data.items():
        averaged_data[x] = {
            "addTime": sum(times["addTime"]) / len(times["addTime"]),
            "removeTime": sum(times["removeTime"]) / len(times["removeTime"])
        }
    return averaged_data

# 画折线图
def plot_graph(data, title):
    sorted_data = dict(sorted(data.items()))
    x_values = list(sorted_data.keys())
    y_add_values = [times["addTime"] for times in sorted_data.values()]
    y_remove_values = [times["removeTime"] for times in sorted_data.values()]

    plt.plot(x_values, y_add_values, label="addTime")
    plt.plot(x_values, y_remove_values, label="removeTime")

    plt.xlabel('Data Quantity')
    plt.ylabel('Time')
    plt.title(title)
    plt.legend()
    plt.show()

# 主函数
def main():
    root = tk.Tk()
    root.withdraw()  # 隐藏主窗口

    data = read_data()
    averaged_data = calculate_average(data)
    title = "Time vs Data Quantity"
    plot_graph(averaged_data, title)

if __name__ == "__main__":
    main()
