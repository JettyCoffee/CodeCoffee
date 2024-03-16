#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define NUM 15

typedef struct a{
    int size;
    int *PID;
    int *Urgency;
    int *Timeout;
    double *Weight;
}JettyData;
void BuildPriorityQueue(JettyData *data);
void OutputMAX(JettyData *data);
void BuildMAXHeap(JettyData *data);
void MAXHeapify(JettyData *data, int i);
void Swap(int *a, int *b);
int main(){
    JettyData data;
    //测试数据集提前放入代码，注意所有的PID所对应的值为实际值减1
    FILE *file;
    int size = NUM;
    data.size = size;
    data.PID = (int*)malloc(sizeof(int) * size);
    data.Urgency = (int*)malloc(sizeof(int) * size);
    data.Timeout = (int*)malloc(sizeof(int) * size);
    data.Weight = (double*)malloc(sizeof(double) * size);
    file = fopen("text.txt","r");
    if (file == NULL) {
        printf("无法打开文件");
        exit(1);
    }
    for(int i = 0; i < NUM; i++){
        fscanf(file,"%d",&data.PID[i]);
        data.PID[i]--;
        fscanf(file,"%d",&data.Urgency[i]);
        fscanf(file,"%d",&data.Timeout[i]);
    }
    fclose(file);
    for(int i=0; i<data.size; i++){
        data.Weight[i] = (2.0 / data.Urgency[i]) + (1.0 / data.Timeout[i]);//计算权重
    }
    BuildPriorityQueue(&data);//构建优先级队列
    for(int i=0; i<size; i++){
        OutputMAX(&data);
    }
    return 0;
}

void BuildPriorityQueue(JettyData *data){
    BuildMAXHeap(data);
}

void OutputMAX(JettyData *data){
    Swap(&data->PID[0],&data->PID[(data->size-1)]);//把最大的数据放至堆底
    data->size--;
    MAXHeapify(data,0);
    printf("Task ID: %d, Urgency: %d, Processing Time: %d, Weight: %f\n",data->PID[data->size]+1,data->Urgency[data->PID[data->size]],data->Timeout[data->PID[data->size]],data->Weight[data->PID[data->size]]);
}
void BuildMAXHeap(JettyData *data){
    for(int i = data->size/2; i >= 0; i--){
        MAXHeapify(data,i);//从树底向上递归
    }
}

void MAXHeapify(JettyData *data, int i){
    int left = i * 2;
    int right = left + 1;
    int top = i;
    if(left < data->size && data->Weight[data->PID[left]] >= data->Weight[data->PID[top]]){
        if(data->Weight[data->PID[left]] == data->Weight[data->PID[top]]){
            if(data->Urgency[data->PID[left]] < data->Urgency[data->PID[top]]){
                top = left;
            }
        }
        else{
            top = left;
        }
    }
    if(right < data->size && data->Weight[data->PID[right]] >= data->Weight[data->PID[top]]){
        if(data->Weight[data->PID[right]] == data->Weight[data->PID[top]]){
            if(data->Urgency[data->PID[right]] < data->Urgency[data->PID[top]]){
                top = right;
            }
        }
        else{
            top = right;
        }
    }
    if(top != i){
        Swap(&data->PID[i],&data->PID[top]);
        MAXHeapify(data,top);
    }
}
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}