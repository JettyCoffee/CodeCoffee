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