#include <stdio.h>

struct Book
{
    char name[50];
    float value;
};

int main()
{
    int n;
    scanf("%d\n",&n);
    struct Book books[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s%f\n",books[i],&books[i].value);
    }
    int max=0,min=0;
    for(int i=0;i<n;i++)
    {
        if(books[i].value > books[max].value)
        {
            max = i;
        }
        if(books[i].value < books[min].value)
        {
            min = i;
        }
    }
    printf("%.2f,%s\n%.2f,%s",books[max].value,books[max].name,books[min].value,books[min].name);
}