#include <stdio.h>

double fn( double x, int n );
double calc_pow( double x, int n );

int main()
{
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    printf("%.2lf", fn(x, n));
}

double fn( double x, int n )
{
    double result = 0;
    for(int i=1;i<=n;i++)
    {
        if(i % 2 == 0)
        {
            result -= calc_pow(x,i);
        }
        if(i % 2 != 0)
        {
            result += calc_pow(x,i);
        }
    }
    return result;
}

double calc_pow( double x, int n )
{
    double result = 1;
    for( int i = 1; i <= n; i++ )
    {
        result *= x;
    }
    return result;
}