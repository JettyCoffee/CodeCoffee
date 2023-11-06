#include <stdio.h>
#include <string.h>

int main()
{
    char *months[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char input[100];
    scanf("%s", input);
    int flags = 0;
    for(int i = 0; i < 7; i++)
    {
        if(strcmp(input,months[i]) == 0)
        {
            printf("%d",i);
            flags = 1;
            break;
        }
    }
    if(flags == 0)
    {
        printf("wrong input!");
    }
}