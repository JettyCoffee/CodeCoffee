#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


void MainMergeSort(int *data, int begin, int end, int *temp);
void MergeSort(int *data, int n);
void DataProducer(int *data);
void DataProducer(int *data){
    int N, min, max, T;
    printf("请选择数据集类型：\n顺序递增(最佳情况)(0)、顺序递减(最差情况)(1)、随机取值(2)\n");
    scanf("%d", &T);
    printf("请输入科学计数法表示的数据大小:\n");
    int front_n, back_n;
    scanf("%d%d", &front_n, &back_n);
    N = (int)(front_n * pow(10, back_n));
    min = 0;
    max = 10000000;
    data = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        data[i] = rand() % (max - min + 1);
        data[i] += min;
    }
    if (T == 0 || T == 1) {
        MergeSort(data, N);
        if (T == 1) {
            for (int i = 0; i < N / 2; i++) {
                int temp = data[i];
                data[i] = data[N - 1 - i];
                data[N - 1 - i] = temp;
            }
        }
    }
    return;
}
void MainMergeSort(int *data, int begin, int end, int *temp) {
    if (begin >= end) {
        return;
    }
    int mid = (begin + end) / 2;
    MainMergeSort(data, begin, mid, temp);
    MainMergeSort(data, mid + 1, end, temp);

    int begin1 = begin;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = end;
    int i = begin;

    while ((begin1 <= end1) && (begin2 <= end2)) {
        if (data[begin1] < data[begin2]) {
            temp[i++] = data[begin1++];
        } else {
            temp[i++] = data[begin2++];
        }
    }
    while (begin1 <= end1) {
        temp[i++] = data[begin1++];
    }
    while (begin2 <= end2) {
        temp[i++] = data[begin2++];
    }
    memcpy(data + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int *data, int n) {
    int *temp = (int*)malloc(sizeof(int) * n);
    MainMergeSort(data, 0, n - 1, temp);
    free(temp);
}