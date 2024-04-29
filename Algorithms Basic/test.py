'''
Author: JettyCoffee jetty_coffee@outlook.com
Date: 2024-04-09 13:48:05
LastEditors: JettyCoffee jetty_coffee@outlook.com
LastEditTime: 2024-04-09 21:52:46
FilePath: \CodeCoffee\Algorithms Basic\test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import random

class TreeNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.left = None
        self.right = None

def insert(root, key, val):
    if root is None:
        return TreeNode(key, val)
    if random.random() < 0.5:
        if key < root.key:
            root.left = insert(root.left, key, val)
        else:
            root.right = insert(root.right, key, val)
    else:
        if key > root.key:
            root.left = insert(root.left, key, val)
        else:
            root.right = insert(root.right, key, val)
    return root

def search(root, key):
    if root is None or root.key == key:
        return root
    if key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)

# 示例：创建BST并插入花卉数据
flowers = ['牡丹', '芍药', '茶花', '菊花', '梅花', '兰花', '月季', '杜鹃花', '郁金香', '茉莉花', '海棠', '荷花', '栀子花', '莲花', '百合', '康乃馨', '玫瑰', '格桑花']
flower_info = {flower: f"{flower}6" for flower in flowers}
bst_root = None
for flower in flowers:
    bst_root = insert(bst_root, flower, flower_info[flower])

# 示例：搜索'牡丹'的信息
result = search(bst_root, '牡丹')
if result:
    print(result.val)
else:
    print("未找到信息")
