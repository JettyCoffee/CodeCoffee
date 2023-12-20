#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 36
#define element_type int

//队列结构体
typedef struct Queue{
    char data[MAXSIZE];
    int x[MAXSIZE],y[MAXSIZE];
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
    return queue->count;
}
//入队
void enqueue(JettyQueue *queue, char element, int x , int y){
    queue->data[(++queue->rear) % MAXSIZE] = element;
    queue->x[(queue->rear) % MAXSIZE] = x;
    queue->y[(queue->rear) % MAXSIZE] = y;
    queue->count++;
}
//出队
char dequeue(JettyQueue *queue, int *x , int *y){
    *x = queue->x[queue->front % MAXSIZE];
    *y = queue->y[queue->front % MAXSIZE];
    queue->count--;
    return queue->data[queue->front++ % MAXSIZE];
}