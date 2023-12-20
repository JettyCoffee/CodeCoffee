#include <stdio.h>
#include <stdlib.h>

int CountDigit(int num,int digit);

int main(){
    int num,num1;
    int digit;
    scanf("%ld %d",&num,&digit);
    num1 = abs(num);
    int count = CountDigit(num1,digit);  
    printf("%d",count);
    return 0;
}

int CountDigit(int num,int digit)
{
    int count = 0;
    while (num != 0)
    {
        int temp = num % 10;
        num /= 10;
        if(temp == digit)
        {
            count++;
        }
    }
    return count;
}
