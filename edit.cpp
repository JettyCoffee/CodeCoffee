#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//C语言下的队列基础模型
#define MAXSIZE 50
#define element_type int

//定义结构体
typedef struct Queue{
    element_type data[MAXSIZE];
    int rear, front, count;
}JettyQueue;

//初始化队列
void initQueue(JettyQueue *queue){
    queue->rear = -1;
    queue->front = 0;
    queue->count = 0;
}

//判断队列是否为空
int isEmpty(JettyQueue *queue){
    return queue->count == 0;
}

//入队
void enqueue(JettyQueue *queue, element_type element){
    //queue->data[((queue->rear++) == MAXSIZE) ? 0 : (queue->rear++)] = element;
    if(queue->count == MAXSIZE) return;
    queue->data[(queue->rear++) % MAXSIZE] = element;
    queue->count++;
}

//出队
element_type dequeue(JettyQueue *queue){
    if(queue->count == 0) return -1;
    return queue->data[queue->front % MAXSIZE];
    queue->front++;
    queue->count--;
}

//引用队首
element_type getfront(JettyQueue *queue){
    return queue->data[(queue->front) % MAXSIZE];
}

//报告规模
element_type size(JettyQueue *queue){
    return queue->count;
}