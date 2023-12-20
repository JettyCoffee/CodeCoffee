#include <stdio.h>

int main()
{
    int n,candy_need = 0;
    scanf("%d",&n);
    int candy[n],candy_give[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&candy[i]);
    }
    for(int a=0;;a++)
    {
        for(int m=0;m<n;m++) //本循环计算分给其他孩子的糖果
        {
            candy[m] /= 2;
            candy_give[m] = candy[m];
        }        
        for(int i=0;i<n;i++) //
        {
            if(i == 0)
            {
                candy[n-1] += candy_give[i];
            }
            else
            {
                candy[i-1] += candy_give[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(candy[i]%2 != 0)
            {
                candy[i]++;
                candy_need++;
            }            
        }
        int temp = 0;
        for(int i=0;i<n-1;i++)
        {
            if(candy[i] == candy[i+1])
            {
                temp++;
            }
            if(temp == n-1)
            {
                printf("%d",candy_need);
                return 0;
            }
        }
    }
    
}