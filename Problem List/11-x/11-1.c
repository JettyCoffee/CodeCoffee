#include <stdio.h>

int main()
{
    char *months[12] = {"January", "February", "March", "April", "May", "June","July","August","September", "October", "November", "December"};
    int n;
    scanf("%d", &n);
    if(n > 0 && n <= 12)
    {
        printf("%s",*(months+n-1));
    }
    else
    {
        printf("wrong input!\n");
    }
}