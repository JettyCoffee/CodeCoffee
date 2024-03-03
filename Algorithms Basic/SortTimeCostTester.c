#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>

long int InsertionSort(long int *data, int n);
int MainMergeSort(int *data, int begin, int end, int *temp);
int BubbleSort(int *data, int n);
void MergeSort(int *data, int n);
int main() {
    FILE *file;
    char filename[100];
    int front,back;
    scanf("%d%d", &front, &back);
    int N = (int)(front * pow(10, back));
    int *data1 = malloc(sizeof(int) * N);
    int *data2 = malloc(sizeof(int) * N);
    int *data3 = malloc(sizeof(int) * N);

    printf("请输入文件名：\n");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d", &data1[i]) != EOF && fscanf(file, "%d", &data2[i]) != EOF && fscanf(file, "%d", &data3[i]) != EOF && i < N) {
        i++;
    }

    fclose(file);

    LARGE_INTEGER start, end, freq;
    double elapsed_time;
    FILE *file_ptr1,*file_ptr2,*file_ptr3;
    file_ptr1 = fopen("InsertionSort_Output.txt", "a");
    file_ptr2 = fopen("Merge_Output.txt", "a");
    file_ptr3 = fopen("BubbleSort_Output.txt", "a");

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    InsertionSort(data1,N);
    QueryPerformanceCounter(&end);
    elapsed_time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    
    
    fprintf(file_ptr1, "%d %f\n",N, elapsed_time);
    
    QueryPerformanceCounter(&start);
    MergeSort(data2,N);
    QueryPerformanceCounter(&end);
    elapsed_time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    
    
    fprintf(file_ptr2, "%d %f\n", N,elapsed_time);
    
    QueryPerformanceCounter(&start);
    BubbleSort(data3,N);
    QueryPerformanceCounter(&end);
    elapsed_time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;

    fprintf(file_ptr3, "%d %f\n",N,elapsed_time);

    return 0;
}

long int InsertionSort(long int *data, int n){
    for(int i=0; i <= n; i++){
        int key = data[i];
        int count = i - 1;
        while(count > 0 && data[count] > key){
            data[count+1] = data[count];
            count--;
            data[count+1] = key; 
        }
    }
}

int MainMergeSort(int *data, int begin, int end, int *temp){
    if(begin >= end){
        return 0;
    }
    int mid = (begin + end) / 2;
    MainMergeSort(data,begin,mid,temp);
    MainMergeSort(data,mid+1,end,temp);

    int begin1 = begin;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = end;
    int i = begin1; 

    while((begin1 <= end1) && (begin2 <= end2)){
        if(data[begin1] < data[begin2]){
            temp[i++] = data[begin1++];
        }
        else{
            temp[i++] = data[begin2++];
        }
    }
    while(begin1 <= end1){
        temp[i++] = data[begin1++];
    }
    while(begin2 <= end2){
        temp[i++] = data[begin2++];
    }
    memcpy(data + begin, temp+begin, sizeof(int)*(end-begin+1));
}

void MergeSort(int *data, int n){
    int* temp = (int*)malloc(sizeof(int) * n);
    MainMergeSort(data, 0, n-1, temp);
}

int BubbleSort(int *data, int n){
    for(int i = 0; i < n-1; i++){
        int swapped = 0;  // 添加标志位
        for(int j = 0; j < n-1-i; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}
