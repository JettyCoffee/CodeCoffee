#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int fib[n];
    fib[1]=1;
    fib[2]=1;
    fib[3]=1;
    for(int i = 4; i <= n; i++)
    {
        fib[i] = fib[i-1] + fib[i-3];
    }
    printf("%d\n", fib[n]);
}

//仿斐波那契数列
//描述

//仿斐波那契数列前三项为1，1， 1
//从第四项开始Fb[i] = Fb[i-1] + Fb[i-3]（i=4,5,6……）
//对于给定n，请你输出仿斐波那契数列第n项的值。（4<=n<=58）

//输入
//一个整数n。（4<=n<=58）

//输出
//一个整数，表述仿斐波那契数列第n项的值