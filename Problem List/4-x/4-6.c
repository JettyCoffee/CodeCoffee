#include <stdio.h>
#include <math.h>
long long pp(int x,int y){
  	long long sum = 1;
    for(int i=0;i<y;i++){
        sum *= x;
    }
    return sum;
}
int main()
{
    int n,count,hua,i,temp,temp1,flag;
    count = 0;
    scanf("%d",&n);
    i = pp(10,n-1);
    temp1 = pp(10,n);
    for(i; i < temp1; i++)
    {
        hua = 0;
        flag = i;
        for(int m=1;m<=n+1;m++)
        {
            temp = flag % 10;
            hua += pp(temp,n);
            flag /= 10;
        }
        if(hua == i)
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}