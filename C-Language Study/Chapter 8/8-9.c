#include <stdio.h>
#include <string.h>

void StringCount( char s[],int n);

int main()
{
    char s[100];
    int i = 0;
    while ((s[i] = getchar()) != EOF)
    {
        i++;
    }
    s[i] = '\0';
    StringCount(s,i);
    return 0;
}

void StringCount( char s[],int n)
{
    int number=0 ,other=0 ,pause=0 ,englishmax=0,englishmin=0;
    char *ss = s;
    for(int i = 0; i < n; i++)
    {  
        if(*ss>='a' && *ss<='z')
        {
            englishmin++;
        }
        else if(*ss>='A' && *ss<='Z')
        {
            englishmax++;
        }        
        else if(*ss >= '0' && *ss <= '9')
        {
            number++;
        }
        else if(*ss == ' ' )
        {
            pause++;
        }
        else
        {
            other++;
        }
    *ss++;
    }
    other -= 1;
    printf("%d %d %d %d %d",englishmax,englishmin,pause,number,other);
}