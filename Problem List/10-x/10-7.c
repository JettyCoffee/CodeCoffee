#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    scanf("%d", &n);
    dectobin(n);
}

void dectobin( int n )
{
    int length = 0;
    int a[100];
    while(n/2)
    {
        a[length++] = n%2;
        n/=2;
    }
    a[length++] = n%2;
    for(int i=length-1; i>=0; i--)
    {
        printf("%d", a[i]);
    }
}