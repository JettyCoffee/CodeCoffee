#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    scanf("%s", s);
    int str= strlen(s);
    int a=0;
    if(str%2!=0)
    {
        a=1;
    }
    int jishu=0,oushu=0;
    for(int i=0; i<str; i++)
    {
        for(int j=0; j<str; j++)
        {
            if(s[i]==s[j])
            {
                oushu++;
            }
            if(s[i]!=s[j])
            {
                jishu++;
            }
        }
    }
    oushu=oushu/2;
    jishu=jishu/2;
    if(a == 1)
    {
        if(jishu%2==0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    if(a == 0)
    {
        if(jishu%2==0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

//正逆数
//描述
//啥是正逆数？比如一个数n，从左往右依次把第i位（i从1开始）的数字乘i次方后累加，如果得到的sum等于原数字n，就把它叫做正逆数。
//例子：89就是个正逆数，因为8^1+9^2=89
//现在给你2个整数n,m，请求出[n,m]范围内有几个正逆数

//输入
//输入仅有1行，包含用空格隔开的两个整数n,m，分别表示区间的左端和右端。

//输出
//1表示可以构成回文，0表示不行