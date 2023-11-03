#include <stdio.h>
#include <math.h>

int search(int n,int *count);
int isPerfectSquare(int num);

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i = 101; i < n; i++)
    {
        search(i,&count);
    }
    printf("%d\n",count);
}

int search(int n,int *count)
{
    int num[3];
    if(isPerfectSquare(n) == 1)
    {
        for(int i=0; i < 3; i++)
        {
            num[i] = n % 10;
            n /= 10;
        }
        for(int i=0; i < 3; i++)
        {
            for(int j=i+1 ; j < 3; j++)
            {
                if(num[j] == num[i])
                {
                    (*count)++;
                }
            }
        }
    }
}

int isPerfectSquare(int num) {
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0 && num / i == i) {
            return 1; // 是完全平方数
        }
    }
    return 0; // 不是完全平方数
}