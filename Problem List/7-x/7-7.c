#include <stdio.h>

int main()
{
    int input[81],n=0;
    while((input[n] = getchar()) != EOF)
    {
        n++;
    }
    for(int j=0;j<n;j++)
    {
        if(input[j] == 'A')
        {
            input[j] = 'Z';
        }
        else if(input[j] == 'B')
        {
            input[j] = 'Y';
        }
        else if(input[j] == 'C')
        {
            input[j] = 'X';
        }
        else if(input[j] == 'D')
        {
            input[j] = 'W';
        }
        else if(input[j] == 'E')
        {
            input[j] = 'V';
        }
        else if(input[j] == 'F')
        {
            input[j] = 'U';
        }
        else if(input[j] == 'G')
        {
            input[j] = 'T';
        }
        else if(input[j] == 'H')
        {
            input[j] = 'S';
        }
        else if(input[j] == 'I')
        {
            input[j] = 'R';
        }
        else if(input[j] == 'J')
        {
            input[j] = 'Q';
        }
        else if(input[j] == 'K')
        {
            input[j] = 'P';
        }
        else if(input[j] == 'L')
        {
            input[j] = 'O';
        }
        else if(input[j] == 'M')
        {
            input[j] = 'N';
        }
        else if(input[j] == 'N')
        {
            input[j] = 'M';
        }
        else if(input[j] == 'O')
        {
            input[j] = 'L';
        }
        else if(input[j] == 'P')
        {
            input[j] = 'K';
        }
        else if(input[j] == 'Q')
        {
            input[j] = 'J';
        }
        else if(input[j] == 'R')
        {
            input[j] = 'I';
        }
        else if(input[j] == 'S')
        {
            input[j] = 'H';
        }
        else if(input[j] == 'T')
        {
            input[j] = 'G';
        }
        else if(input[j] == 'U')
        {
            input[j] = 'F';
        }
        else if(input[j] == 'V')
        {
            input[j] = 'E';
        }
        else if(input[j] == 'W')
        {
            input[j] = 'D';
        }
        else if(input[j] == 'X')
        {
            input[j] = 'C';
        }
        else if(input[j] == 'Y')
        {
            input[j] = 'B';
        }
        else if(input[j] == 'Z')
        {
            input[j] = 'A';
        }
    }
    for(int i = 0; i <n; i++)
    {
        printf("%c",input[i]);
    }
    return 0;
}
