#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LINE 5


int main()
{
    char input[LINE][SIZE];
    char temp[SIZE];
    int i=0;
    for(int i=0; i<LINE; i++)
    {
        scanf("%s",input[i]);
    }

    for(int i=0; i<LINE; i++)
    {
        for(int j=i+1; j<LINE; j++)
        {
            if(strcmp(input[i],input[j])>0)
            {
                strcpy(temp,input[i]);
                strcpy(input[i],input[j]);
                strcpy(input[j],temp);
            }
        }
    }
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", input[i]);
    }

    return 0;
}
