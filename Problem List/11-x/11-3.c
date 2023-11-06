#include <stdio.h>
#include <string.h>

int max_len(char *s[], int n);

int main()
{
    int n;
    scanf("%d\n", &n);
    char *str[n];
    for(int i=0; i<n; i++)
    {
        str[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", str[i]);
    }
    printf("%d", max_len(str, n));
        for (int i = 0; i < n; i++) {
        free(str[i]);
    }
}

int max_len(char *s[], int n)
{
    int max_len = 0;
    for(int i=0; i<n; i++)
    {
        int len = strlen(s[i]);
        if(len > max_len)
        {
            max_len = len;
        }
    }
    return max_len;
}