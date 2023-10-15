#include <stdio.h>

int main()
{
    int m,n;
    scanf("%d%d",&m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {   
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("%d", sum);
        if(i != m-1)
        {
            printf(" ");
        }
    }
    return 0;
}