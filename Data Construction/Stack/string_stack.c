/*使用数组实现一个字符串的栈
描述

请使用数组实现一个字符串的栈，最大容量为20。输出字符串逆序结果。
注意不要有不必要的输出，比如“请输入字符串”。

输入
一行字符串，长度可能大于最大容量。

输出
输入字符串的逆序输出。*/
#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 20

struct StringStack {
    char stack[MAX_CAPACITY];
    int top;
};

void initStack(struct StringStack *s) {
    s->top = -1;
}

void push(struct StringStack *s, char c) {
    if (s->top < MAX_CAPACITY - 1) {
        s->stack[++(s->top)] = c;
    }
}

char pop(struct StringStack *s) {
    if (s->top >= 0) {
        return s->stack[(s->top)--];
    }
    return '\0';
}

int isEmpty(struct StringStack *s) {
    return s->top == -1;
}

void reverseString(struct StringStack *s, const char *input) {
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        push(s, input[i]);
    }

    while (!isEmpty(s)) {
        printf("%c", pop(s));
    }

    printf("\n");
}

int main() {
    struct StringStack stack;
    initStack(&stack);
    char input[MAX_CAPACITY + 1];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    reverseString(&stack, input);

    return 0;
}
