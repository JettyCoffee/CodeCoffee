#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX 10000000

int main() {
    int N, min, max;
    printf("矩阵(方阵)的大小N:\n");
    scanf("%d", &N);
    min = 0;
    max = MAX;
    srand(time(NULL));
    int **output = (int**)malloc(sizeof(int*) * N);
    for(int i=0; i<N; i++){
        output[i] = (int*)malloc(sizeof(int) *N);
    }
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            output[i][j] = rand() % (max - min + 1);
            output[i][j] += min;
        }
        
    }
    char filename[100];
    sprintf(filename, "oridata_Martix_%d.txt", N);
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        for(int j=0;j<N;j++){
            fprintf(file, "%d\n", output[i][j]);
        }
    }
    fclose(file);
    free(output);
    return 0;
}