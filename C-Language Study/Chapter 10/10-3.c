#include <stdio.h>

double calc_pow( double x, int n );

int main()
{
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    printf("%0.lf",calc_pow(x,n));
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