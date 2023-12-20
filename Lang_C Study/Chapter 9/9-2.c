#include <stdio.h>

struct Fushu
{
    int a1;
    int a2;
    int b1;
    int b2;
};

void chengji(struct Fushu *fushu,int *shibu,int *xubu) 
{
    *shibu = fushu->a1 * fushu->b1 - fushu->a2 * fushu->b2;
    *xubu = fushu->a1 * fushu->b2 + fushu->a2 * fushu->b1;
}

int main()
{
    int shibu;
    int xubu;
    struct Fushu fushu;
    scanf("%d%d%d%d", &fushu.a1, &fushu.a2,&fushu.b1,&fushu.b2);
    chengji(&fushu,&shibu,&xubu);
    printf("(%d+%di) * (%d+%di) = %d + %di",fushu.a1,fushu.a2,fushu.b1,fushu.b2,shibu,xubu);
}