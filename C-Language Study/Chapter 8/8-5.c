#include <stdio.h>
#include <string.h>

void strmcpy(char *t, int m, int n, char *s);

int main()
{
    int m,n=0;
    scanf("%d\n", &m);
    char t[10000],s[10000];
    while((t[n] = getchar()) != EOF)
    {
        n++;
    }
    strmcpy(t, m, n, s);
    for(int i=0;i<(n-m);i++)
    {
        printf("%c", s[i]);
    }
    return 0;
}

void strmcpy(char *t, int m, int n, char *s)
{
    if(m > n)
    {
        for(int i=0;i<m;i++)
        {
            s[i] = ' ';
        }
    }
    else
    {
        char *a;
        a=t+m-1;   //关于-1的问题，写个小表格就知道了
        strcpy(s,a);
    }
}