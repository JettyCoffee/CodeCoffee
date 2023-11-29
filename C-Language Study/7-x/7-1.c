#include <stdio.h>

int main()
{
    int n,temp=0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int j = 0; j < n; j++){
         for (int i = 0; i < n-1; i++)
        {
            if(a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n-1)
        {
            printf(" ");
        }
        
    }
}