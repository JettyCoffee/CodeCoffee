#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>

typedef struct {
    int size;
    int capacity;
    int *data;
} JettyData;

void InsertHeap(JettyData *data, int data1);
void MAXHeapifyUp(JettyData *data, int i);
void Swap(int *a, int *b);
void DataProducer(JettyData *data, int N);

int main(){
    JettyData data, testdata;
    int front_n = 1;
    int back_n = 7;
    int size = (int)(front_n * pow(10, back_n));
    
    data.size = 0;
    data.capacity = size;
    data.data = (int*)malloc(sizeof(int) * size);
    
    testdata.size = 0;
    testdata.capacity = size;
    testdata.data = (int*)malloc(sizeof(int) * size);
    
    DataProducer(&data, size);

    LARGE_INTEGER start, end, freq;
    double time;
    FILE *time_file = fopen("HeapSortTimeCost.txt", "a");
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    for(int i = 0; i < size; i++){
        InsertHeap(&testdata, data.data[i]);
    }

    QueryPerformanceCounter(&end);
    time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    fprintf(time_file, "%d %f\n", size, time);
    fclose(time_file);

    free(data.data);
    free(testdata.data);

    return 0;
}

void InsertHeap(JettyData *data, int data1){ // Insert data1 into the heap
    if(data->size >= data->capacity) {
        // Handle resizing if necessary
        return;
    }
    data->data[data->size] = data1;
    data->size++;
    MAXHeapifyUp(data, data->size - 1);
}

void MAXHeapifyUp(JettyData *data, int i){
    int parent = (i - 1) / 2;
    while(i > 0 && data->data[i] > data->data[parent]){
        Swap(&data->data[i], &data->data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DataProducer(JettyData *data, int N){
    int min = 0;
    int max = 10000000;
    int T = 2;
    data->data = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        data->data[i] = rand() % (max - min + 1) + min;
    }
    if (T == 0 || T == 1) {
        MergeSort(data->data, N);
        if (T == 1) {
            for (int i = 0; i < N / 2; i++) {
                int temp = data->data[i];
                data->data[i] = data->data[N - 1 - i];
                data->data[N - 1 - i] = temp;
            }
        }
    }
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
