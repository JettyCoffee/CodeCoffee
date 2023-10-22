#include <stdio.h>

void CountOff(int n, int m, int out[]);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int out[n];
    CountOff(n,m,out);
    for(int i=0;i<n;i++)
        printf("%d ",out[i]);
    return 0;
}

void CountOff(int n, int m, int out[])
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        out[i] = 0;
    }
    int index = 0;
    for(int i=0; i<n; i++)
    {
        int j = 0;
        int finder = m % (n - i);
        if(finder == 0)
        {
            finder = n - i;
        }
        while(1)
        {
            if(out[index] == 0)
            {
                j++;
                if(j == finder)
                {
                    out[index] = ++count;
                    break;
                }
            }
            index = (index + 1) % n;
        }
    }
}