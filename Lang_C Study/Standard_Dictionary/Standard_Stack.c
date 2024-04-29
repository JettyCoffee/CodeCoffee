#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 36
#define element_type int

typedef struct Stack{
    int data[MAXSIZE];
    int x[MAXSIZE],y[MAXSIZE];
    int top;
}JettyStack;

//初始化栈
void initStack(JettyStack *stack){
    stack->top = -1;
}

//入栈
void push(JettyStack *stack, element_type element, int x, int y){
    if(stack->top < MAXSIZE - 1){
        stack->data[++stack->top] = element;
        stack->x[stack->top] = x;
        stack->y[stack->top] = y;
    }
}//MAXSIZE - 1是因为top初始为-1

//出栈
element_type pop(JettyStack *stack, int *x, int *y){
    if(stack->top >= 0){
        *x = stack->x[stack->top];
        *y = stack->y[stack->top];
        return stack->data[stack->top--];
    }
    return 0;
}

//检测栈是否为空
int isEmpty(JettyStack *stack){
    return stack->top == -1;
}