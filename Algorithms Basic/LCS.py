import random
import seaborn as sns
import matplotlib.pyplot as plt

# 打开文件并读取数据
with open('E:\CodeCoffee\Algorithms Basic\chimpanzee.txt', 'r') as file:
    # 初始化一个空列表来存储序列和分类
    sequences = []
    for line in file:
        # 找到数字分隔符的位置
        index = next((i for i, char in enumerate(line) if char.isdigit()), None)
        # 分割序列和分类
        sequence = line[:index].strip()
        classification = line[index:].strip()
        # 将序列和分类添加到列表中
        sequences.append([sequence, classification])

def find_LCS(str1, str2):
    length1 = len(str1)
    length2 = len(str2)  # 初始化长度
    LCS_length = [[0] * (length2+1) for _ in range(length1+1)]
    result = []

    # 动态规划填表
    for i in range(1, length1+1):
        for j in range(1, length2+1):
            if str1[i-1] == str2[j-1]:
                LCS_length[i][j] = LCS_length[i-1][j-1] + 1
            else:
                LCS_length[i][j] = max(LCS_length[i-1][j], LCS_length[i][j-1])

    # 回溯找LCS
    i, j = length1, length2
    while i > 0 and j > 0:
        if str1[i-1] == str2[j-1]:
            result.insert(0, str1[i-1])  # 在结果列表前面插入字符
            i -= 1
            j -= 1
        elif LCS_length[i][j-1] > LCS_length[i-1][j]:
            j -= 1
        else:
            i -= 1
    return ''.join(result)  # 将列表转换为字符串

def similarity_percentage(index1,index2):
    str_lcs = find_LCS(sequences[index1][0],sequences[index2][0])
    return (100*2*len(str_lcs)/(len(sequences[index1][0])+len(sequences[index2][0])))



#为实验三选择两个随机数
#m = random.randint(1,len(sequences))
#n = random.randint(1,len(sequences))
#lcs_mn = find_LCS(sequences[m][0],sequences[n][0])
#print(f"The LCS of sequence 1 at index {m} class {sequences[m][1]} len {len(sequences[m][0])} and sequence 2 at index {n} class {sequences[n][1]} len {len(sequences[n][0])} is: {lcs_mn} with length {len(lcs_mn)}")

#实验四内容
import string
# 生成一个长度为5000的随机字符串(26大写字母)
random_string = ''.join(random.choices(string.ascii_uppercase, k=5000))
# 生成长度分别为5、50、500、5000的随机字符串(26大写字母)
random_string_5 = ''.join(random.choices(string.ascii_uppercase, k=10))
random_string_50 = ''.join(random.choices(string.ascii_uppercase, k=100))
random_string_500 = ''.join(random.choices(string.ascii_uppercase, k=1000))
random_string_5000 = ''.join(random.choices(string.ascii_uppercase, k=2500))
# 此处为计时代码...
import time
start_time = time.perf_counter()
find_LCS(random_string, random_string_5)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")
start_time = time.perf_counter()
find_LCS(random_string, random_string_50)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")
start_time = time.perf_counter()
find_LCS(random_string, random_string_500)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")
start_time = time.perf_counter()
find_LCS(random_string, random_string_5000)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")

#实验五内容
selectNumber = 4
selectIndex = [0]*selectNumber
selectedLCS = [0]*selectNumber
for i in range(0,selectNumber):
    selectIndex[i] = random.randint(1,len(sequences)) #生成对应数量的随机数
similarity_matrix = [[0]*selectNumber for _ in range(selectNumber)] #生成相似度矩阵
for i in range(selectNumber):
    for j in range(selectNumber):
        similarity_matrix[i][j] = similarity_percentage(selectIndex[i],selectIndex[j])


figure = sns.heatmap(similarity_matrix, annot=True, fmt=".2f", cmap="YlGnBu", xticklabels=selectIndex, yticklabels=selectIndex)
plt.grid(True)
plt.show()