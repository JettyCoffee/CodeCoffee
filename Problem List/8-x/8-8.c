#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    scanf("%s", s);
    int i = 0, j = strlen(s) - 1;
    while (i < j)
    {
        if (s[i]!= s[j])
        {
            printf("No");
            return 0;
        }
        i++;
        j--;
    }
    printf("Yes");
    return 0;
}