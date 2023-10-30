#include <stdio.h>

struct Info
{
    char name[11];
    long int birth;
    char tel[20];
};

int main()
{
    int n;
    scanf("%d\n", &n);
    struct Info info[n];
    struct Info infotemp;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        scanf("%s", info[i].name);
        scanf("%ld", &info[i].birth);
        scanf("%s", info[i].tel);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(info[i].birth <= info[j].birth)
            {
                infotemp = info[i];
                info[i] = info[j];
                info[j] = infotemp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s %ld %s\n", info[i].name,info[i].birth,info[i].tel);
    }

}