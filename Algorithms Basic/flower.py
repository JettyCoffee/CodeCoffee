import random

flowers = [
    ("康乃馨", 1), ("玫瑰", 1), ("格桑花", 1),
    ("海棠", 2), ("荷花", 2), ("栀子花", 2), ("莲花", 2), ("百合", 2),
    ("月季", 3), ("杜鹃花", 3), ("郁金香", 3), ("茉莉花", 3),
    ("菊花", 4), ("梅花", 4), ("兰花", 4),
    ("芍药", 5), ("茶花", 5),
    ("牡丹", 6)
]

# 使用sorted()函数按访问频率降序排序
sorted_flowers = sorted(flowers, key=lambda x: x[1], reverse=True)

# 函数用于根据花卉名称检索详细信息
def search_flower_info(flower, flower_name):
    return flower_hash_table.get(flower_name)

##构建哈希表来存储这些数据，并基于哈希表来检索数据。
# 创建字典（哈希表）
flower_hash_table = {}
i = 0
# 填充字典
for i in range(len(flowers)):
    flower_hash_table[flowers[i][0]] = flowers[i][1]
def search_flower_info_hash(folwer_name):
    return flower_hash_table.get(folwer_name,"404 Not Found")


##1.随机构建二叉搜索树（randomly built BST），进行搜索。
class TreeNode:
    def __init__(self,key=0,left=None,right=None):
        self.key = key
        self.left = left
        self.right = right

class AVLNode:
    def __init__(self, key, height=1, left=None, right=None):
        self.key = key
        self.height = height
        self.left = left
        self.right = right

def get_height(node):
    if not node:
        return 0
    return node.height

def update_height(node):
    node.height = max(get_height(node.left), get_height(node.right)) + 1

def get_balance(node):
    if not node:
        return 0
    return get_height(node.left) - get_height(node.right)

def left_rotate(x):
    y = x.right
    T2 = y.left
    y.left = x
    x.right = T2
    update_height(x)
    update_height(y)
    return y

def right_rotate(y):
    x = y.left
    T2 = x.right
    x.right = y
    y.left = T2
    update_height(y)
    update_height(x)
    return x

def insert_avl(root, key):
    if not root:
        return AVLNode(key)
    if key < root.key:
        root.left = insert_avl(root.left, key)
    else:
        root.right = insert_avl(root.right, key)
    
    update_height(root)
    balance = get_balance(root)
    
    # Left Left Case
    if balance > 1 and key < root.left.key:
        return right_rotate(root)
    # Right Right Case
    if balance < -1 and key > root.right.key:
        return left_rotate(root)
    # Left Right Case
    if balance > 1 and key > root.left.key:
        root.left = left_rotate(root.left)
        return right_rotate(root)
    # Right Left Case
    if balance < -1 and key < root.right.key:
        root.right = right_rotate(root.right)
        return left_rotate(root)
    
    return root

def search(root, key):
    if not root:
        return None
    if root.key == key:
        return root.key
    elif key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)

def convert_to_number(chinese_character):
    return sum(ord(char) for char in chinese_character)

def bstsearchlink(root, key):
    return search(root, flower_bst.get(key))

random.shuffle(flowers)
flower_bst = {}
#将加权后的数字与名字映射
for i in range(len(flowers)):
    flower_bst[flowers[i][0]] = flowers[i][1]+convert_to_number(flowers[i][0])
#将数字插入二叉树
avl_root = None
for flower in flowers:
    avl_root = insert_avl(avl_root, flower[1])

import time

start_time = time.perf_counter()
for flower in flowers:
    search_key = flower[0]
    search_flower_info(sorted_flowers, search_key)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")

start_time = time.perf_counter()
for flower in flowers:
    search_key = flower[0]
    search_flower_info_hash(search_key)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")

start_time = time.perf_counter()
for flower in flowers:
    search_key = flower[0]
    bstsearchlink(avl_root,search_key)
end_time = time.perf_counter()
print(f"函数执行时间：{end_time - start_time}秒")

print(convert_to_number("牡丹"))  # 输出牡丹两个字符的Unicode编码值之和
