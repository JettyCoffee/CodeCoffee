#include <stdio.h>

int main()
{
    char s[1000000];
    int i = 0,count = 1;
    while ((s[i] = getchar()) != EOF)
    {

        if(s[i] != ' ')
        {
            if(s[i-1] == ' ')
            {
                count++;
            }
        }
        if(s[i] == '.')
        {
            break;
        }
        i++;
    }
        if(s[0] == ' ')
        {
            count--;
        }    
    printf("%d",count);
    return 0;
}