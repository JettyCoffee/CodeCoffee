#include <stdio.h>

int prime(int p);
int PrimeSum(int m, int n);

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int sum = PrimeSum(m,n);    
    printf("%d",sum);
    return 0;
}

int prime(int p)
{
    if(p<=1)
    {
        return 0;
    }
    for(int i=2;i<p;i++)
    {
        if(p % i == 0)
        {
            return 0;
        }
    } 
    return 1;
}

int PrimeSum(int m, int n)
{
    int sum = 0;
    for(int i=m;i<=n;i++)
    {
        if(prime(i) == 1)
        {
            sum += i;
        }
    }
    return sum;
}