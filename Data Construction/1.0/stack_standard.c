#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

//程序函数
int mainstring(JettyStack *stack, element_type *input){

}

int main(){
    JettyStack stack;
    initStack(&stack);

    element_type input[MAXSIZE + 1];

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    mainstring(&stack,input);

    return 0;
}