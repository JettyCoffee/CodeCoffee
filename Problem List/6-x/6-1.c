#include <stdio.h>
#include <string.h>

void StringCount( char s[]);

int main()
{
    char s[100];
    int i = 0;
    while ((s[i] = getchar()) != EOF)
    {
        i++;
    }
    s[i] = '\0';
    StringCount(s);
    return 0;
}

void StringCount( char s[])
{
    int number=0 ,other=0 ,pause=0 ,english=0;
    char *ss = s;
    int str = strlen(s);
    for(int i = 0; i < str; i++)
    {  
        if( (*ss>='a' && *ss<='z') || (*ss>='A' && *ss<='Z') )
        {
            english++;
        }
        else if(*ss >= '0' && *ss <= '9')
        {
            number++;
        }
        else if(*ss == ' ' || *ss == '\n' )
        {
            pause++;
        }
        else
        {
            other++;
        }
    *ss++;
    }
    printf("%d %d %d %d",english,pause,number,other);
}