import tkinter as tk
from tkinter import filedialog
import subprocess


# 主窗体
class MainWindow(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("主窗体")
        self.geometry("300x200")  # 设置主窗口大小
        self.configure(bg="#f0f0f0")  # 设置背景颜色

        self.create_widgets()

    def create_widgets(self):
        self.import_button = tk.Button(self, text="导入CSV文件", command=self.open_choose_csv_window, bg="#007bff", fg="white", font=("Arial", 12))
        self.import_button.pack(padx=20, pady=10)

    def open_choose_csv_window(self):
        self.import_button.config(state=tk.DISABLED)  # 禁用导入按钮
        self.disable_close_button()    # 禁用主窗口的原生关闭按钮
        choose_csv_window = ChooseCSVPathWindow(self)  # 创建ChooseCSVPathWindow窗体的实例
        choose_csv_window.grab_set()    # 阻止用户与其他窗口进行交互
        choose_csv_window.wait_window()     # 等待子窗口关闭
        self.enable_close_button()  # 启用主窗口的原生关闭按钮
        self.import_button.config(state=tk.NORMAL)  # 恢复导入按钮

    def disable_close_button(self):
        # 禁用主窗口的关闭按钮
        self.protocol("WM_DELETE_WINDOW", lambda: None)

    def enable_close_button(self):
        # 启用主窗口的关闭按钮
        self.protocol("WM_DELETE_WINDOW", self.destroy)


# 选择csv文件窗体
class ChooseCSVPathWindow(tk.Tk):
    def __init__(self, parent):
        tk.Tk.__init__(self)
        self.parent = parent
        self.title("选择账单路径")
        self.grid_columnconfigure(1, weight=1)

        self.wechat_entry = None
        self.alipay_entry = None

        self.create_widgets()

    def create_widgets(self):
        wechat_label = tk.Label(self, text="微信账单路径：")
        wechat_label.grid(row=0, column=0, padx=5, pady=5, sticky="e")
        self.wechat_entry = tk.Entry(self, state="readonly")     # state="readonly"禁止用户输入
        self.wechat_entry.grid(row=0, column=1, padx=5, pady=5, sticky="we")
        wechat_button = tk.Button(self, text="选择文件", command=self.select_wechat_file)
        wechat_button.grid(row=0, column=2, padx=5, pady=5)

        alipay_label = tk.Label(self, text="支付宝账单路径：")
        alipay_label.grid(row=1, column=0, padx=5, pady=5, sticky="e")
        self.alipay_entry = tk.Entry(self, state="readonly")
        self.alipay_entry.grid(row=1, column=1, padx=5, pady=5, sticky="we")
        alipay_button = tk.Button(self, text="选择文件", command=self.select_alipay_file)
        alipay_button.grid(row=1, column=2, padx=5, pady=5)

        confirm_button = tk.Button(self, text="确认", command=self.confirm_action)
        confirm_button.grid(row=2, column=1, padx=5, pady=5)

    def select_file(self, entry):
        file_path = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
        if file_path:  # 如果用户选择了文件
            entry.config(state='normal')  # 先设置为可编辑状态
            entry.delete(0, tk.END)     # 清空输入框
            entry.insert(0, file_path)      # 输入框填写用户选择的路径
            entry.config(state='readonly')  # 再设置为只读状态

    def select_wechat_file(self):
        self.select_file(self.wechat_entry)

    def select_alipay_file(self):
        self.select_file(self.alipay_entry)

    # 按下确认按钮的一系列动作
    def confirm_action(self):
        wechat_path = self.wechat_entry.get()
        alipay_path = self.alipay_entry.get()
        # 使用 subprocess 模块来执行 AccountProcess.py，并传递文件路径作为命令行参数
        subprocess.run(['python', 'AccountProcess.py', wechat_path, alipay_path])
        self.grab_release()    # 恢复交互
        self.destroy()

    def on_close(self):
        self.grab_release()    # 恢复交互
        self.destroy()


if __name__ == "__main__":
    app = MainWindow()
    app.mainloop()
