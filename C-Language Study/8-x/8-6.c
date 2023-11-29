#include <stdio.h>

void delchar(char *str,char c,int n);

int main()
{
    char str[100];char c;
    scanf("%s\n",&c);
    int n=0;
    while((str[n] = getchar()) != EOF)
    {
        n++;
    }
    delchar(str,c,n);
}

void delchar(char *str,char c,int n)
{
    int i=0;
    while(i != n)
    {
        if(str[i]!= c)
        {
            printf("%c",str[i]);
        }
        i++;
    }
}