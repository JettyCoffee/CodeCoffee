#include <stdio.h>
#include <math.h>

int main()
{
    char input[101],n=0;
    int num[101];
    while((input[n] = getchar()) != '#')
    {
        if(input[n] == '0')
        {
            num[n] = 0;
            n++;
        }
        if(input[n] == '1')
        {
            num[n] = 1;
            n++;
        }
        if(input[n] == '2')
        {
            num[n] = 2;
            n++;
        }
        if(input[n] == '3')
        {
            num[n] = 3;
            n++;
        }
        if(input[n] == '4')
        {
            num[n] = 4;
            n++;
        }
        if(input[n] == '5')
        {
            num[n] = 5;
            n++;
        }
        if(input[n] == '6')
        {
            num[n] = 6;
            n++;
        }
        if(input[n] == '7')
        {
            num[n] = 7;
            n++;
        }
        if(input[n] == '8')
        {
            num[n] = 8;
            n++;
        }
        if(input[n] == '9')
        {
            num[n] = 9;
            n++;
        }
        if(input[n] == 'A' || input[n] == 'a')
        {
            num[n] = 10;
            n++;
        }
        if(input[n] == 'B' || input[n] == 'b')
        {
            num[n] = 11;
            n++;
        }
        if(input[n] == 'C' || input[n] == 'c')
        {
            num[n] = 12;
            n++;
        }
        if(input[n] == 'D' || input[n] == 'd')
        {
            num[n] = 13;
            n++;
        }
        if(input[n] == 'E' || input[n] == 'e')
        {
            num[n] = 14;
            n++;
        }
        if(input[n] == 'F' || input[n] == 'f')
        {
            num[n] = 15;
            n++;
        }
        if(input[n] == '-')
        {
            printf("-");
        }
    }
    int result=0,j=0;
    for(int i = n-1; i >= 0; i--)
    {
        result += num[i] * pow(16,j);
        j++;
    }
    printf("%d\n", result);
    return 0;
}
