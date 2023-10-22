#include <stdio.h>
#include <math.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int count = 0;
    for(int i=n; i<=m; i++)
    {
        int sum = 0;
        int shuwei = 0;
        int equal = i;
        while(equal > 0)
        {
            equal /= 10;
            shuwei++;
        }
        int equal1 = i;
        for(int j=shuwei;j>0;j--)
        {
            sum += pow((equal1 % 10),j);
            equal1 /= 10;
        }
        if(sum == i)
        {
            count++;
        }
    }
    printf("%d",count);
}

//正逆数
//描述

//啥是正逆数？比如一个数n，从左往右依次把第i位（i从1开始）的数字乘i次方后累加，如果得到的sum等于原数字n，就把它叫做正逆数。

//例子：89就是个正逆数，因为8^1+9^2=89

//现在给你2个整数n,m，请求出[n,m]范围内有几个正逆数

//输入
//输入仅有1行，包含用空格隔开的两个整数n,m，分别表示区间的左端和右端。

//输出、
//[n,m]范围内有几个正逆数。
