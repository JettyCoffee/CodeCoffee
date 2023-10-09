#include <stdio.h>

int main()
{
    int n;
    double h;
    scanf("%lf %d",&h,&n);
    for(int i=0;i<n;i++)
    {
        h = h / 2;
    }
    printf("%.2lf",h);
    return 0;
}