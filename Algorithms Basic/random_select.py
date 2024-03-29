# -*- coding: utf-8 -*-
import pandas as pd
import random
import os

file_path = r'E:\CodeCoffee\Algorithms Basic\data.xls'
data = pd.read_excel(file_path,index_col=0)
#data = data.drop(data.columns[0], axis=1)

top_downloaded = data.nlargest(1, '下载量')
lowest_downloaded = data.nsmallest(1, '下载量')

#print (top_downloaded)
#print (lowest_downloaded)

def partition(jettylist, left, right, key_index):
    key = jettylist[key_index]
    jettylist[key_index], jettylist[right] = jettylist[right], jettylist[key_index]
    #把key交换至list末尾
    temp_index = left
    for i in range(left,right):
        if jettylist[i] < key:
            jettylist[i], jettylist[temp_index] = jettylist[temp_index], jettylist[i]
            #若发现i小于key，则将其与temp的数据交换，再讲temp向右自增
            temp_index += 1
    jettylist[temp_index], jettylist[right] = jettylist[right], jettylist[temp_index]
    return temp_index

def random_select(jettylist, left, right, i):
    if left == right:
        return jettylist[left]
    key_index = random.randint(left, right)
    key_index = partition(jettylist, left, right, key_index)
    #进行一次快排基础操作
    k = key_index - left + 1 # k为比key小的元素个数
    if i == k: #i是寻找的第i小的元素下标
        return jettylist[key_index]
    elif i < k:
        return random_select(jettylist, left, key_index-1, i)
    else:
        return random_select(jettylist, key_index+1, right, i-k)

def partition_selectver(jettylist, left, right, key):
    for i in range(left,right):
        if jettylist[i] == key:
            key_index = i
            break
    jettylist[key_index], jettylist[right] = jettylist[right], jettylist[key_index]
    #把key交换至list末尾
    temp_index = left
    for i in range(left,right):
        if jettylist[i] < key:
            jettylist[i], jettylist[temp_index] = jettylist[temp_index], jettylist[i]
            #若发现i小于key，则将其与temp的数据交换，再讲temp向右自增
            temp_index += 1
    jettylist[temp_index], jettylist[right] = jettylist[right], jettylist[temp_index]
    return temp_index

def select(jettylist, left, right, key):
    if left == right:
        return jettylist[left]
    
    mid = find_mid(jettylist, left, right) #找到中位数的中位数
    mid_index = partition_selectver(jettylist, left, right, mid) #此时数组内mid左侧都比他小，而mid右侧都比他大

    k = mid_index - left + 1 #k为当前select函数内，比jettylist里的mid小的元素
    if k == key:
        return jettylist[mid_index]
    elif k > key:
        return select(jettylist, left, mid_index-1, key)
    else:
        return select(jettylist, mid_index+1, right, key-k)
    
def find_mid(jettylist, left, right):
    length = right - left + 1 
    #length = len(jettylist)
    if length % 5 == 0:
        mid_list = [0] * (length//5)
    else:
        mid_list = [0] * (length//5 + 1)##创建包括不超过5的一个中位数分割数组
    group_count = 0
    for i in range(0,length):
        if i % 5 == 0: #当i为五的倍数的时候执行
            five_list_begin = left + i
        if (i+1) % 5 == 0 or i == length-1: #当i为五的倍数-1的时候执行
            five_list_end = left + i
            group_count += 1
            temp_list = sorted(jettylist[five_list_begin:five_list_end])
            if five_list_begin == five_list_end:
                temp_list = [0]
                temp_list[0] = jettylist[five_list_begin]
            mid_list[group_count-1] = temp_list[len(temp_list)//2]
    mid_list.sort()
    mid = mid_list[group_count // 2]
    return mid

view_counts = data['浏览量'].tolist()
view_1000st = random_select(view_counts, 0, len(view_counts)-1, 1000)
view_1000st1 = select(view_counts, 0, len(view_counts)-1, 1000)
print (view_1000st)
print (view_1000st1)
#print(type(data))
#print(data)