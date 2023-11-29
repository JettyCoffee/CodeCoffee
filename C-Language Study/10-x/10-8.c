#include <stdio.h>

void printdigits(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printdigits(n);
}

void printdigits(int n)
{
    int a[100];
    int count = 0;
    while(n/10)
    {
        a[count++] = n % 10;
        n /= 10;
    }
    a[count++] = n % 10;
    for(int i=count-1; i>=0; i--)
    {
        printf("%d\n", a[i]);
    }
}