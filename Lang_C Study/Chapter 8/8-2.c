#include <stdio.h>

int search( int list[], int n, int x);

int main()
{
    int n,x;
    scanf("%d", &n);
    int list[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &list[i]);
    }
    scanf("%d", &x);
    search(list,n,x);
}

int search( int list[], int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(list[i] == x)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
}