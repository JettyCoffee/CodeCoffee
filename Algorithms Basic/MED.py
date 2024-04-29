import random
import string
import time
import seaborn as sns
import matplotlib.pyplot as plt

#生成一组随机字符串（小写字母）
def random_lowerstring(row,col): #row为生成字符串的数量，col为每个字符串的长度
    result = []
    for i in range(row): #生成row个字符串
        result.append(''.join(random.choices(string.ascii_lowercase, k=col))) #生成col长度的字符串
    return result

#计算两个字符串的最小编辑距离（相似度）
def find_MED(str1, str2):
    length1 = len(str1)
    length2 = len(str2)  # 初始化长度
    MED_map = [[0] * (length2+1) for _ in range(length1+1)] # 初始化MED表

    for i in range(1, length1+1): # 初始化MED表的第一行和第一列
        MED_map[i][0] = i
    for j in range(1, length2+1):
        MED_map[0][j] = j

    # 动态规划填表
    for i in range(1, length1+1):
        for j in range(1, length2+1):
            if str1[i-1] == str2[j-1]:
                MED_map[i][j] = MED_map[i-1][j-1] # 如果两个字符相同，则MED值不变
            else:
                MED_map[i][j] = min(MED_map[i-1][j]+1, MED_map[i][j-1]+1, MED_map[i-1][j-1]+1) # 如果两个字符不同，则MED值为左上角、上方、左方三个值的最小值

    return MED_map[length1][length2]  # 返回MED的值


#实验一：编写随机字符串生成算法
# 生成N个‘a’-‘z’范围长度为M的随机字符串并输出；（N,M定为5,10）
#print(random_lowerstring(5, 10)) # ['jzqzqzqzqz', 'zqzqzqzqzq', 'zqzqzqzqzq', 'zqzqzqzqzq', 'zqzqzqzqzq']

#实验二&三：给定word1 = "intention", word2 = "execution"
# 请返回将 word1 转换成 word2 所使用的最少操作数
word1 = "intention"
word2 = "execution"
print(find_MED(word1, word2)) # 5

import random
#实验四：随机生成两个范围为26个英文字母（小写），
# 长度为5、50、100、500、1000、5000的随机字符串word1,word2
# 请返回将 word1 转换成 word2 所使用的最少操作数，并记录时间
lengths = [5, 50, 100, 500, 1000, 5000] # 字符串长度
word1 = ''.join(random_lowerstring(1, lengths[random.randint(0,5)]))
word2 = ''.join(random_lowerstring(1, lengths[random.randint(0,5)]))
timecost_matrix = [[0] * len(lengths) for _ in range(len(lengths))] # 初始化时间矩阵
for i in lengths:
    word1 = ''.join(random_lowerstring(1, i)) # 生成长度为i的字符串
    for j in lengths:
        word2 = ''.join(random_lowerstring(1, j)) # 生成长度为j的字符串
        timecost_matrix[lengths.index(i)][lengths.index(j)] = find_MED(word1, word2) 

#绘制热力图
figure = sns.heatmap(timecost_matrix, annot=True,cmap="YlGnBu", xticklabels=lengths, yticklabels=lengths)
plt.grid(True)
plt.show()

start_time = time.perf_counter()
print(find_MED('abc', 'ab')) # 1
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")
