#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//C语言下的栈基础模型
/************************************************************************/
#define MAXSIZE 50
#define element_type char

//定义结构体
typedef struct SrtingStack{
    element_type stack[MAXSIZE];
    int top;
}JettyStack;

//初始化栈
void initStack(JettyStack *stack){
    stack->top = -1;
}

//入栈
void push(JettyStack *stack, element_type element){
    if(stack->top < MAXSIZE - 1) stack->stack[++stack->top] = element;
}//MAXSIZE - 1是因为top初始为-1

//出栈
element_type pop(JettyStack *stack){
    if(stack->top >= 0) return stack->stack[stack->top --];
    return '\0';
}

//取top元素
element_type top(JettyStack *stack){
    return stack->stack[stack->top];
}

//检测栈是否为空
int isEmpty(JettyStack *stack){
    return stack->top == -1;
}
/************************************************************************/

//冒泡排序基础模型1.0
void bubblesort_1_0(int A[], int n){
    bool sorted = false; //整体排序标志，首先假定未排序
    while(!sorted){ //为全局排序前进行逐层扫描
        sorted = true; //假定已经排序
        for(int i = 1;i<n;i++){ //自左向右进行扫描检查交换元素
            if(A[i-1] > A[i]){
                swap(A[i],A[i-1]));
                sorted = false; //因整体排序无法保证所以清除排序标志
            }
        }
        n--; //排序后末尾元素一定有序，所以缩短排序检测长度
    }
} //本方法缩短蛮力计算n-1次扫描的复杂度

//C语言下的循环队列基础模型
/************************************************************************/
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
    queue->count--;
    return queue->data[queue->front++ % MAXSIZE];
}

//引用队首
element_type getfront(JettyQueue *queue){
    return queue->data[(queue->front) % MAXSIZE];
}

//报告规模
element_type size(JettyQueue *queue){
    return queue->count;
}
/************************************************************************/