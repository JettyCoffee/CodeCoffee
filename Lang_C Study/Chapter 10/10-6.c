#include <stdio.h>

int fib(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld", fib(n));
}

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    long int result;
    result = fib(n-2) + fib(n-1);
    return result;
}