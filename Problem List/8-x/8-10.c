#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    float average=0, sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=a[i];
    }
    average=sum/n;
    float max = a[0];
    float min = a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    printf("average = %.2f\n", average);
    printf("max = %.2f\n", max);
    printf("min = %.2f\n", min);
    return 0;
}