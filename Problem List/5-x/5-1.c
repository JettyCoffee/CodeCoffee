#include <stdio.h>

int sign(int x);

int main(){
    int x;
    scanf("%d",&x);
    int n = sign(x);
    printf("%d",n);
    return 0;
}

int sign(int x)
{
    if(x>=0)
    {
        if(x>0)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return -1;
    }

}