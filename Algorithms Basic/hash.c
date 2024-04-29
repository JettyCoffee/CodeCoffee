#include <stdio.h>
#include <string.h>

// 定义花卉信息的结构体
typedef struct {
    char name[50];
    int frequency;
    char description[200];
} JettyFlower;

// 哈希函数，这里简单地使用字符串的第一个字符
unsigned int hash(char *str) {
    return str[0] % 100;
}

// 创建一个足够大的哈希表数组
#define TABLE_SIZE 100
JettyFlower hashTable[TABLE_SIZE];

// 初始化哈希表
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(hashTable[i].name, "");
    }
}

// 添加花卉信息到哈希表
void addFlowerToHashTable(JettyFlower flower) {
    int index = hash(flower.name);
    hashTable[index] = flower;
}

// 根据花卉名称检索详细信息
JettyFlower *searchFlowerInfo(char *name) {
    int index = hash(name);
    if (strcmp(hashTable[index].name, name) == 0) {
        return &hashTable[index];
    }
    return NULL;
}

int main() {
    // 初始化哈希表
    initHashTable();

    // 添加花卉信息
    JettyFlower peony = {"牡丹", 6, "牡丹被称为花中之王，象征着富贵和吉祥。"};
    addFlowerToHashTable(peony);

    // ... 添加其他花卉信息

    // 检索牡丹的信息
    JettyFlower *flowerInfo = searchFlowerInfo("牡丹");
    if (flowerInfo != NULL) {
        printf("花卉名称: %s\n访问频率: %d\n描述: %s\n", flowerInfo->name, flowerInfo->frequency, flowerInfo->description);
    } else {
        printf("未找到该花卉的信息。\n");
    }

    return 0;
}
