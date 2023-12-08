#include <stdio.h>
#include <string.h>

char *macth(char *s,char ch1,char ch2);

int main()
{
    char s[10];
    scanf("%s\n", &s);
    char ch1, ch2;
    scanf("%c %c", &ch1,&ch2);
    char *p = NULL;
    p = macth(s,ch1,ch2);
    if(p != NULL)
    {
        printf("%s", p);
    }
    return 0;
}

char *macth(char *s,char ch1,char ch2)
{
    char *start = NULL;
    int flags = 0;
    while (*s != '\0') 
    {
        if (*s == ch1) 
        {
            start = s;
            flags = 1;
        }
        if (flags) 
        {
            printf("%c", *s);
            if (*s == ch2 || *s == '\0')  
            {
                break;
            }
        }
        s++;
    }
    printf("\n");
    return start;
}