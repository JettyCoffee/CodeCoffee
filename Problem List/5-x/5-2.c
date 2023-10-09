#include <stdio.h>

int even(int n);
int OddSum(int List[],int N);

int main(){
    int n;
    scanf("%d\n",&n);
    int List[n];
    int sum = 0;
    int N;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&N);
        List[i]=N;
        sum += OddSum(List ,i);
    }
    printf("%d",sum);
    return 0;
}

int even(int n)
{
    if(n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int OddSum(int List[], int N)
{
    if(even(List[N]) == 0)
    {
        return List[N];
    }
    else
    {
        return 0;
    }
}