/*匹配括号
描述

输入一串字符串（长度不超过50），其中有普通的字符与括号组成（
包括‘(’、‘)’、‘[’,']'）,要求验证括号是否匹配，如果匹配则输出0、否则输出1。
注意不要有不必要的输出，比如“请输入字符串”。

输入
一行字符串。

输出
一个整数表示答案。*/
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
    int strlength = strlen(input);
    int flag = 0;
    //入栈
    for(int i=0; i<strlength; i++){
        switch(input[i]){
            case '(':
            case '[':
                push(stack,input[i]);
                flag += 1;
                break;
            case ')':
                if(top(stack) == '('){
                    pop(stack);
                    flag -= 1;
                    break;
                }
                else{
                    printf("1");
                    exit(0);
                }
            case ']':
                if(top(stack) == '['){
                    pop(stack);
                    flag -= 1;
                    break;
                }
                else{
                    printf("1");
                    exit(0);
                }

        }
    }
    if(flag == 0) printf("0");
    else printf("1");
    exit(0);
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