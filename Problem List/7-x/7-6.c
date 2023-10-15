#include <stdio.h>

int main()
{
    int input[101],n=0;
    while((input[n] = getchar()) != EOF)
    {
        n++;
    }
    int count = 0;
    for(int j=0;j<n;j++)
    {
        if(input[j] != 'A' && input[j] != 'E' && input[j] != 'I' && input[j] != 'O' && input[j] != 'U' && input[j] >= 'A' && input[j] <= 'Z')
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
