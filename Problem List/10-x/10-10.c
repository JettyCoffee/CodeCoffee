#include <stdio.h>
#include <math.h>

int Area(double *area,int a,int b,int c);
int S(double *s,int a,int b,int c);

int main()
{
    int a,b,c;
    double area = 0;
    scanf("%d%d%d",&a,&b,&c);
    Area(&area,a,b,c);
    printf("%.2lf",area);
}

int S(double *s,int a,int b,int c)
{
    *s = (double)(a+b+c)/2;
}

int Area(double *area,int a,int b,int c)
{
    double s = 0;
    S(&s,a,b,c);
    *area = (double)sqrt( s * (s - a) * (s -b) * (s -c) );
}