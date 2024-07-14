
import pandas as pd
import matplotlib.pyplot as plt

# 从 CSV 文件读取数据
file_path = r'C:\Users\25405\Desktop\sorting_performance3.csv' # 替换为你的 CSV 文件路径
df = pd.read_csv(file_path)

# 显示数据的前几行，确保正确加载
print(df.head())

# 如果数据包含 'DataSize'、'Algorithm' 和 'Time(seconds)' 列
# 可以直接使用数据来绘制图表

# 拆分数据为冒泡排序和快速排序
bubble_sort = df[df['Algorithm'] == 'Bubble Sort']
quick_sort = df[df['Algorithm'] == 'Quick Sort']

# 创建图表
plt.figure(figsize=(10, 6))
plt.plot(bubble_sort['Data Size'], bubble_sort['Time (seconds)'], marker='o', label='Bubble Sort')
plt.plot(quick_sort['Data Size'], quick_sort['Time (seconds)'], marker='s', label='Quick Sort')
plt.xscale('log')  # 使用对数刻度绘制数据量
plt.yscale('log')  # 使用对数刻度绘制时间
plt.title('Performance Comparison of Bubble Sort and Quick Sort')
plt.xlabel('Data Size')
plt.ylabel('Time (seconds)')
plt.grid(True)
plt.legend()

# 显示图表
plt.show()