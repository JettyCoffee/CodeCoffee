#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N,min,max,T;
    printf("请选择数据集类型：顺序递增(0)、顺序递减(1)、随机取值(2)");
    scanf("%d",&T);
    scanf("%d%d%d",&N,&min,&max);
    srand(time(NULL));
    int output[N];
    for (int i = 0; i < N; i++) {
        output[i] = rand() % (max - min+1) + min;
    }

    return 0;
}

int Merge(int *data[], int n){
    if()
}