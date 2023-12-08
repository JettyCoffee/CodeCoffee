#include <stdio.h>
#include <string.h>

char *search(char *s, char *t);

int main()
{
    char s[30],t[30];
    int n = 0;
    while((s[n] = getchar()) != '\n')
    {
        n++;
    }
    s[n+1] = '\0';
    n = 0;
    while((t[n] = getchar()) != '\n')
    {
        n++;
    }
    t[n+1] = '\0';
    char *p = NULL;
    p = search(s, t);
    if(p == NULL)
    {
        printf("-1");
    }
    else
    {

        printf("%ld", p-s);
    }
    return 0;
}

char *search(char *s, char *t)
{

    while(*s != '\0')
    {
        char *temp_s = s;
        char *temp_t = t;
        int count = 0;
        while(*temp_s != '\0' && *temp_s == *temp_t)
        {
            temp_s++;
            temp_t++;
            count++;
        }
        if(*temp_t == '\n' || *temp_t == '\0')
        {
            temp_s -= count;
            return temp_s;
        }
        s++;
    }
    return NULL;
}