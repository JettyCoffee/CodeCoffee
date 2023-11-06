#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *astrcat(char *str1, char *str2);

int main()
{
    char str1[100], str2[100];
    scanf("%s%s", str1, str2);
    char *p = astrcat(str1, str2);
    printf("%s\n%s", p, str1);
}

char *astrcat(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    //str1 = realloc(str1, (len1 + len2 + 1) * sizeof(char));
    strcat(str1, str2);
    return str1;
}