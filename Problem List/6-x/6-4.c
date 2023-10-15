#include <stdio.h>
int fib(int n);
void printFN(int m,int n);
int main()
{
    int m,n,t;
    scanf("%d%d%d",&m,&n,&t);
    printf("%d\n",fib(t));
    printFN(m,n);
}

int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}

void printFN(int m,int n)
{
    int out[21];
    for(int i=0;i<=20;i++)
    {
        out[i]=fib(i);
    }
    int num[n-m+1];
    int a =0;
    for(int i=m;i<=n;i++)
    {
            for(int j=0;j<21;j++)
            {
                if(out[j] == i)
                {
                    num[a] = i;
                    a++;
                }
            }
        
    }
    if(a==0)
    {
        printf("No Fibonacci number");
        return 0;
    }
    for (int i=0;i<a;i++)
    {
        printf("%d",num[i]);
        if(i != a - 1)
        {
            printf(" ");
        }
    }
}