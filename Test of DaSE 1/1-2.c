#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<(n-1)/2;i++) //描述上半行的数量
    {
        for(int i1=(n-1)/2-i;i1>0;i1--)  //空格数量
        {
        printf(" ");
        }
        printf("*");
        for(int i2=0;i2<2*(i)-1;i2++) //*数量
        {
        printf(" ");
        }
        if(i != 0) printf("*");
        printf("\n");
    }
    printf("*");
    for(int a=0;a<n-2;a++)
    {
        printf(" ");
    }
    printf("*");
    printf("\n");
    for(int i=0;i<(n-1)/2;i++) //描述下半行的数量
    {
        for(int i2=0;i2<i+1;i2++) //*数量
        {
        printf(" ");
        }
        printf("*");
        for(int i1=0;i1<(n-4-2*i);i1++)  //空格数量
        {
        printf(" ");
        }
        if(i != (n-1)/2-1) printf("*");
        printf("\n");
    }
    return 0;
}

//打印空心菱形图案
//描述
//输入一个正整数n（n为奇数），打印一个高度为n的“*”空心菱形图案。试编写相应程序。

//输入
//输入一个整数 n

//输出
//打印一个高度为n的空心棱形图案，行首非 “*” 号区域用空格字符填充，行末无空格填充，上下行之间无空行。