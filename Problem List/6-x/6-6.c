#include <stdio.h>

int reverse(int number);

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 0)
    {
        printf("0\n");
        return 0;
    }
    reverse(n);
}

int reverse(int number)
{
    if(number < 0)
    {
        printf("-");
        number *= -1;
    }
    int nixu[1000]={0},i=0;
    while(number != 0)
    {
        nixu[i] = number % 10;
        number /= 10;
        i++;
    }
    int j = 0;
    while(nixu[j] == 0)
    {
        j++;
    }
    for(j;j<i;j++)
    {
        printf("%d",nixu[j]);
    }
}