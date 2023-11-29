#include <stdio.h>

int prime(int p);
void Goldbach(int n);

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    if(m%2 != 0)
    {
        m++;
    }
    for(int i=m; i<=n;)
    {
        Goldbach(i);
        i += 2;
    }
}

int prime(int p)
{
    if(p==1) return 0;
    for(int j=2; j<p; j++)
    {
        if(p%j==0)
        {
        return 0;
        }
    }
    return 1;
}

void Goldbach(int n)
{
    int max=0;
    for(int i=2; i<n; i++)
    {
        if(prime(i) == 1)
        {
            max = n - i;
            if(prime(max) == 1)
            {
                printf("%d=%d+%d\n",n,i,max);
                break;
            }
        }
    }
}