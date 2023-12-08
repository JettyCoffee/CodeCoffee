#include <stdio.h>

int main()
{
    int m,n,prenum=0;
    scanf("%d%d",&m,&n);
    for(int i=m; i<n; i++)
    {
        int yinzi = 1;
        for(int j=2; j<i; j++)
        {
            if(i % j == 0)
            {
                yinzi += j;
            }
        }
        if( yinzi == i)
        {
            prenum++;
        }
    }
    prenum > 0 ? printf("%d", prenum) :printf("No perfect number");
}