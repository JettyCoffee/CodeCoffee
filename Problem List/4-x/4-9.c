#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<(n-1)/2;i++) //描述上半行的数量
    {
        for(int i1=(n-1)/2-i;i1>0;i1--)  //空格数量
        {
        printf(" ");
        }
        for(int i2=0;i2<2*(i+1)-1;i2++) //*数量
        {
        printf("*");
        }
        printf("\n");
    }
    for(int a=0;a<n;a++)
    {
        printf("*");
    }
    printf("\n");
    for(int i=0;i<(n-1)/2;i++) //描述下半行的数量
    {
        for(int i2=0;i2<i+1;i2++) //*数量
        {
        printf(" ");
        }
        for(int i1=0;i1<(n-2-2*i);i1++)  //空格数量
        {
        printf("*");
        }
        printf("\n");
    }
    return 0;
}