#include <stdio.h>

int GCD(int num1,int num2);
int LCM(int num1,int num2);

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int gcd = GCD(m,n);
    int lcm = LCM(m,n);
    printf("%d %d",gcd,lcm);
    return 0;
}

int GCD(int num1,int num2)
{
    while (num2 != 0)
    {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int LCM(int num1,int num2)
{
    return (num1*num2)/GCD(num1,num2);
}