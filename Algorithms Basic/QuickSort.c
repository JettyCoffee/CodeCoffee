#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define NUM 1024

typedef struct a{
    int *data;
}JettyData;

int GetMidIndex(int left, int right);
void Swap(int *a, int *b);
int PartDivide(JettyData *data, int left, int right);
void QuickSort(JettyData *data, int left, int right);
int main(){
    FILE *file;
    char filename[1024];
    int size = NUM;
    sprintf(filename,"test_%d.txt",size);
    file = fopen(filename,"r");
    JettyData data;
    int left = 0;
    int right = NUM;
    for(int i = 0; i < NUM; i++){
        fscanf(file,"%d",&data.data[i]);
    }
    fclose(file);
    LARGE_INTEGER start, end, freq;
    double time;
    FILE *time_file = fopen("SortedTimeCost.txt", "a");
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    QuickSort(&data,left,right);
    QueryPerformanceCounter(&end);
    time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    fprintf(time_file, "%d %f\n", NUM, time);
    fclose(time_file);
    return 0;
}

void QuickSort(JettyData *data, int left, int right){
    if(left >= right){
        return;
    }
    int i = PartDivide;
    QuickSort(data, left, i-1);
    QuickSort(data, i+1, right);
}

int PartDivide(JettyData *data, int left, int right){
    int mid = GetMidIndex(left, right);
    Swap(data->data[mid], data->data[left]);
    //调换mid和left的数据值
    int key = left;//key保留原始mid的数据
    while(left < right){
        while(left < right && data->data[key] <= data->data[right]){
            right--;//检测到right所指数据大于key，属于右侧数组
        }
        while(left < right && data->data[key] >= data->data[left]){
            left++;//检测到left所指数据小于key，属于左侧数组
        }
        Swap(data->data[left], data->data[right]);//交换左右两个数据
    }
    Swap(data->data[left], data->data[key]);//将data[key]与data[left]进行交换，达成分割
    return left;//此时left所指数据为原始mid数据
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int GetMidIndex(int left, int right){
    return rand() % (right - left + 1) + left;
}