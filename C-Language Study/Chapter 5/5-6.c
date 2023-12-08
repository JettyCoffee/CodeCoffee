#include <stdio.h>
#include <math.h>

int narcissistic(int num);
void PrintN(int m,int n);

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    PrintN(m,n);
    return 0;
}

int narcissistic(int num)
{
    int n = 0;
    int sum = 0;
    int temp = num;
    while (temp != 0)
    {
        temp /= 10;
        n++;
    }
    int power = n;
    temp = num;
    while (temp != 0)
    {  
        int digit = temp % 10;
        sum += pow(digit,power);
        temp /= 10;
    }
    if(sum == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void PrintN(int m,int n)
{
    for(int i=m;i<=n;i++)
    {
        int innarcissistic = narcissistic(i);
        if(innarcissistic == 1)
        {
            printf("%d\n",i);
        }
    }
}