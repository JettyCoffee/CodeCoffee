#include <stdio.h>

int ArrayShift(int a[], int n, int m);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+m];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    ArrayShift(a,n,m);
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

int ArrayShift(int a[], int n, int m)
{
    int j = m%n;
    for(int i=n-1; i>=0; i--)
    {
        a[i+j] = a[i];
    }
    for(int i=0; i<j; i++)
    {
        a[i] = a[n+i];
    }
}