#include <stdio.h>

int main()
{
    int n,month,total,born1,born2,born3;
    scanf("%d",&n);
    total = 1;
    born1 = 0;
    born2 = 0;
    born3 = 1;
    month = 2;
    while(total < n)
    {
        born3 += born2;
        born2 = born1;
        born1 = born3;
        month = month + 1;
        total = born1+born2+born3;
    }
    if(month == 2){
        month = 1;
    }
    printf("%d",month);
    return 0;
}