# 导入必要的库
import pandas as pd
import matplotlib.pyplot as plt

# 加载Excel文件
file_path = 'D:/Users/Jetty/Desktop/cypv.xlsx'
excel_data = pd.ExcelFile(file_path)

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['HarmonyOS Sans SC']  # 使用黑体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示为方块的问题

# 读取Sheet1数据
sheet1_df = excel_data.parse('Sheet1')

# 将 '发布日期' 列转换为日期格式
sheet1_df['发布日期'] = pd.to_datetime(sheet1_df['发布日期'])

# 设置图表大小
fig, ax1 = plt.subplots(figsize=(14, 8))

# 绘制播放量柱状图 (7-14天播放量和当前播放量)
bar_width = 0.5  # 柱状图的宽度
index = range(len(sheet1_df))  # 用于定位柱子的索引

# 创建两个柱状图: 播放量(7-14d) 和 当前播放量
bar1 = ax1.bar([i - bar_width/2 for i in index], sheet1_df['播放量(7-14d)'], bar_width, label='7-14天综合播放量', color='skyblue')
bar2 = ax1.bar([i + bar_width/2 for i in index], sheet1_df['当前播放量'], bar_width, label='当前播放量', color='g')

# 为每个播放量柱状图添加标签 (显示具体的数值)
for rect in bar1:
    height = rect.get_height()
    ax1.annotate(f'{height} 万', xy=(rect.get_x() + rect.get_width() / 2, height), 
                 xytext=(0, 3), textcoords="offset points", ha='center', fontsize=8)

for rect in bar2:
    height = rect.get_height()
    ax1.annotate(f'{height} 万', xy=(rect.get_x() + rect.get_width() / 2, height), 
                 xytext=(0, 3), textcoords="offset points", ha='center', fontsize=8)

# 设置x轴标签为视频标题
ax1.set_xlabel('视频标题')
ax1.set_ylabel('播放量 (万)')
ax1.set_title('原神各视频播放量对比')

# 将视频标题设置为横坐标标签，并保持视频发布顺序
ax1.set_xticks(index)
ax1.set_xticklabels(sheet1_df['视频标题'], rotation=45, ha='right', fontsize=10)

# 添加图例
ax1.legend()

# 调整图表布局
fig.tight_layout()

# 显示图表
plt.show()
