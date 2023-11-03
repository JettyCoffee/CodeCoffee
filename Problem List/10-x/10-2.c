#include <stdio.h>

double Fact(int n);
double Factsum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    double fact = Fact(n);
    double factsum = Factsum(n);
    printf("%0.lf\n%.0lf", fact, factsum);
}

double Factsum(int n)
{
    double result = 0;
    for(int i=1;i<=n;i++)
    {
        result += Fact(i);
    }
    return result;
}

double Fact(int n)
{
    double result = 1;
    for(int i=2;i<=n;i++)
    {
        result *= i;
    }
    return result;
}