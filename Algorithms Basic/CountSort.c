#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define RANGE 5000
#define SIZE 1000

typedef struct a{
    int *data;
    int size;
    int maxdata;
}JettyData;

void CountSort(JettyData *data);

int main(){
    FILE *file;
    char filename[1024];
    int size = SIZE;
    sprintf(filename,"output_%d_%d.txt",RANGE,size);
    file = fopen(filename,"r");
    JettyData data;
    data.data = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        fscanf(file,"%d",&data.data[i]);
    }
    data.maxdata = RANGE;
    data.size = size;
    fclose(file);
    LARGE_INTEGER start, end, freq;
    double time;
    sprintf(filename,"CountSort_SameSize_%d.txt",SIZE);
    FILE *time_file = fopen(filename, "a");
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    CountSort(&data);
    CountSort(&data);
    CountSort(&data);

    QueryPerformanceCounter(&end);
    time = ((end.QuadPart - start.QuadPart) / (double)freq.QuadPart)/3;
    fprintf(time_file, "%d %f\n", RANGE, time);
    fclose(time_file);
    return 0;
}

void CountSort(JettyData *data){
    int k = data->maxdata;
    int len = data->size;
    int *arrC = (int *)malloc(sizeof(int)*(k+1));
    int *arrB = (int *)malloc(sizeof(int)*len);
    for(int i = 0; i <= k; i++){
        arrC[i] = 0;
    }
    for(int i = 0; i < len; i++){
        arrB[i] = 0;
    }
    for(int i = 0; i < len; i++){
        arrC[data->data[i]]++;//将数组的元素计数
    }
    for(int i = 1; i <= k; i++){
        arrC[i] += arrC[i-1];//确认每一个元素的最后的位置
    }
    for(int i = len-1;i>=0;i--){
        arrB[arrC[data->data[i]]-1] = data->data[i];//导向该元素后放置在数组末
        arrC[data->data[i]]--;
    }
    /*for(int i = 0; i < len; i++){
        data->data[i] = arrB[i];//将排序后的数组替换回原数组，此时能保证有序性
    }*/
}