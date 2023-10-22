#include <stdio.h>

void splitfloat(float x, int *intpart, float *fracpart);

int main()
{
    float x;
    scanf("%f", &x);
    int intpart;
    float fracpart;
    splitfloat(x, &intpart, &fracpart);
    printf("%d %.3f", intpart, fracpart);
}

void splitfloat(float x, int *intpart, float *fracpart)
{
    *intpart = (int)x;
    *fracpart = x - *intpart;
}