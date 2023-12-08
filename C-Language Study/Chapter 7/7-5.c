#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int hang[n];
    int lie[n];
    for(int i = 0; i < n; i++)
    {
        hang[i] = a[i][0];
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] >= hang[i])
            {
                hang[i] = a[i][j];
            }
        }
    }
    for(int j = 0; j < n; j++)
    {
        lie[j] = a[0][j];
        for(int i = 0; i < n; i++)
        {
            if(a[i][j] <= lie[j])
            {
                lie[j] = a[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(lie[j] == hang[i])
            {
                printf("%d %d", i,j);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
