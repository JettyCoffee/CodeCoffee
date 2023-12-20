/*实现循环链表解决约瑟夫问题
描述

请使用循环链表解决约瑟夫问题。
约瑟夫问题为n个人围成一个圆圈，首先第1个人从1开始一个人一个人顺时针报数,报到第m个人，令其出列。然后再从下一个人开始，从1顺时针报数，报到第m个人，再令其出列，…，如此下去,直到圆圈中只剩一个人为止。此人即为优胜者。


输入
输入两个整数n和m，n为总人数，m为将被逐出的报数值。


输出
输出一个整数，为最后优胜者序号。*/
#include <stdio.h>
#include <stdlib.h>

//C语言下的循环链表模型
#define MAXSIZE 50
#define element_type int

//定义节点结构
typedef struct Node{
    element_type data;
    struct Node* next;
}JettyNode;

//创建新的节点
JettyNode* CreateNode(element_type data){
    JettyNode* newnode = (JettyNode*) malloc(sizeof(JettyNode));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

//从循环链表尾部插入元素
JettyNode* InsertAtListBack(int n){
    JettyNode* head = (JettyNode*) malloc(sizeof(JettyNode));
    head->data = 1;
    head->data = head;
    JettyNode* now = head;
    head->data = 1;
    if(n == 1){
        head->next = head;
        return head;
    }
    for(int i=2;i<=n;i++){
        JettyNode* newnode = (JettyNode*) malloc(sizeof(JettyNode));
        newnode->data = i;
        newnode->next = head;
        now->next = newnode;
        now = newnode;
    }
    return head;
}

//从循环列表里删除元素
element_type Josephus(JettyNode** head, int m){
    JettyNode* now = *head;
    JettyNode* prev = NULL;
    while(now->next != *head){
        prev = now;
        now = now->next;
    }
    prev = now;
    now = now->next;

    while(*head != (*head)->next){
        for(int i=1;i<m;i++){
            prev = now;
            now = now->next;
        }
        prev->next = now->next;
        if(now == *head){
            *head = now->next;
        }
        free(now);
        now = prev->next;
    }
    return (*head)->data;
}

int main(){
    JettyNode* head;
    int n,m;
    scanf("%d%d",&n,&m);
    head = InsertAtListBack(n);
    int winner = Josephus(&head, m);
    printf("%d",winner);
    return 0;
}