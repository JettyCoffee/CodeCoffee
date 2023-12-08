#include <stdio.h>

int Ack(int m,int n);

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",Ack(m,n));
}

int Ack(int m,int n)
{
    if(m == 0)
    {
        return (n+1);
    }
    if(n == 0 && m > 0)
    {
        Ack(m-1,1);
    }
    if(n > 0 && m > 0)
    {
        Ack(m-1 , Ack(m,n-1));
    }
}