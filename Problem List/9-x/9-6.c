#include <stdio.h>

struct Info
{
    int tag;
    char name[10];
    int score;
    char grade;
};

void set_grade(struct Info *info,int *count)
{
    if(info->score >= 85)
    {
        info->grade = 'A';
    }
    else if(info->score >= 70 && info->score <= 85)
    {
        info->grade = 'B';
    }
    else if(info->score >= 60 && info->score <= 69)
    {
        info->grade = 'C';
    }
    else if(info->score <= 59)
    {
        info->grade = 'D';
        *count += 1;
    }

}

int main()
{
    int n;
    scanf("%d\n", &n);
    struct Info info[n];
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%s%d", &info[i].tag,info[i].name,&info[i].score);
    }
    for(int i = 0; i < n; i++)
    {
        set_grade(&info[i],&count);
    }
    printf("The count for failed (<60): %d\n",count);
    printf("The grades:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %s %c\n", info[i].tag,info[i].name,info[i].grade);
    }

}

