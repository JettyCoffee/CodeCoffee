#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define number 4000

typedef struct Matrix {
    int **matrix;
} JettyMatrix;

void defineMatrix(JettyMatrix *matrix, int size);
void writetomatrix(JettyMatrix *matrix, int size);
void Normal_Matrix_Multiply(JettyMatrix *matrix, JettyMatrix *matrix1, JettyMatrix *matrix2, int N);
void Strassen_Matrix(JettyMatrix *m0, JettyMatrix *m1, JettyMatrix *m2, int N);
void MatrixAdd(int n, JettyMatrix *m1, JettyMatrix *m2, JettyMatrix *m0);
void MatrixMin(int n, JettyMatrix *m1, JettyMatrix *m2, JettyMatrix *m0);
void freeMatrix(JettyMatrix *matrix, int size);

void writetomatrix(JettyMatrix *matrix, int size) {
    FILE *file;
    char filename[100];
    sprintf(filename, "oridata_Martix_%d.txt", size);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fscanf(file, "%d", &matrix->matrix[i][j]);
        }
    }
    fclose(file);
}

int main() {
    JettyMatrix matrix, matrix1, matrix2;
    int N, size;
    N = number;
    if (N % 2 == 1) {
        size = N + 1;
        defineMatrix(&matrix, size);
        defineMatrix(&matrix1, size);
        defineMatrix(&matrix2, size);
    } else {
        size = N;
        defineMatrix(&matrix, size);
        defineMatrix(&matrix1, size);
        defineMatrix(&matrix2, size);
    }
    writetomatrix(&matrix1, N);
    writetomatrix(&matrix2, N);

    LARGE_INTEGER start, end, freq;
    double elapsed_time;
    FILE *file_ptr1, *file_ptr2;
    file_ptr2 = fopen("Strassen.txt", "a");

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    Strassen_Matrix(&matrix, &matrix1, &matrix2, size);
    QueryPerformanceCounter(&end);
    elapsed_time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    fprintf(file_ptr2, "%d %f\n", N, elapsed_time);

    fclose(file_ptr2);

    freeMatrix(&matrix, size);
    freeMatrix(&matrix1, size);
    freeMatrix(&matrix2, size);

    return 0;
}

void defineMatrix(JettyMatrix *matrix, int size) {
    matrix->matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        matrix->matrix[i] = (int *)malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix->matrix[i][j] = 0;
        }
    }
}

void Normal_Matrix_Multiply(JettyMatrix *matrix, JettyMatrix *matrix1, JettyMatrix *matrix2, int N) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            for (int i = 0; i < N; i++) {
                matrix->matrix[row][col] += matrix1->matrix[row][i] * matrix2->matrix[i][col];
            }
        }
    }
}

void Strassen_Matrix(JettyMatrix *m0, JettyMatrix *m1, JettyMatrix *m2, int N) {
    if (N <= 128) {
        Normal_Matrix_Multiply(m0, m1, m2, N);
        return;
    }

    int size = N / 2;

    JettyMatrix A11, A12, A21, A22, B11, B12, B21, B22;
    defineMatrix(&A11, size);
    defineMatrix(&B11, size);
    defineMatrix(&A12, size);
    defineMatrix(&B12, size);
    defineMatrix(&A21, size);
    defineMatrix(&B21, size);
    defineMatrix(&A22, size);
    defineMatrix(&B22, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A11.matrix[i][j] = m1->matrix[i][j];
            A12.matrix[i][j] = m1->matrix[i][j + size];
            A21.matrix[i][j] = m1->matrix[i + size][j];
            A22.matrix[i][j] = m1->matrix[i + size][j + size];
            B11.matrix[i][j] = m2->matrix[i][j];
            B12.matrix[i][j] = m2->matrix[i][j + size];
            B21.matrix[i][j] = m2->matrix[i + size][j];
            B22.matrix[i][j] = m2->matrix[i + size][j + size];
        }
    }

    JettyMatrix S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
    defineMatrix(&S1, size);
    defineMatrix(&S2, size);
    defineMatrix(&S3, size);
    defineMatrix(&S4, size);
    defineMatrix(&S5, size);
    defineMatrix(&S6, size);
    defineMatrix(&S7, size);
    defineMatrix(&S8, size);
    defineMatrix(&S9, size);
    defineMatrix(&S10, size);

    MatrixMin(size, &B12, &B22, &S1);
    MatrixAdd(size, &A11, &A12, &S2);
    MatrixAdd(size, &A21, &A22, &S3);
    MatrixMin(size, &B21, &B11, &S4);
    MatrixAdd(size, &A11, &A22, &S5);
    MatrixAdd(size, &B11, &B22, &S6);
    MatrixMin(size, &A12, &A22, &S7);
    MatrixAdd(size, &B21, &B22, &S8);
    MatrixMin(size, &A11, &A21, &S9);
    MatrixAdd(size, &B11, &B12, &S10);

    JettyMatrix P1, P2, P3, P4, P5, P6, P7;
    defineMatrix(&P1, size);
    defineMatrix(&P2, size);
    defineMatrix(&P3, size);
    defineMatrix(&P4, size);
    defineMatrix(&P5, size);
    defineMatrix(&P6, size);
    defineMatrix(&P7, size);

    Strassen_Matrix(&P1, &A11, &S1, size);
    Strassen_Matrix(&P2, &S2, &B22, size);
    Strassen_Matrix(&P3, &S3, &B11, size);
    Strassen_Matrix(&P4, &A22, &S4, size);
    Strassen_Matrix(&P5, &S5, &S6, size);
    Strassen_Matrix(&P6, &S7, &S8, size);
    Strassen_Matrix(&P7, &S9, &S10, size);

    JettyMatrix C11, C12, C21, C22, add1, add2;
    defineMatrix(&C11, size);
    defineMatrix(&C12, size);
    defineMatrix(&C21, size);
    defineMatrix(&C22, size);
    defineMatrix(&add1, size);
    defineMatrix(&add2, size);

    MatrixAdd(size, &P5, &P4, &add1);
    MatrixMin(size, &P6, &P2, &add2);
    MatrixAdd(size, &add1, &add2, &C11);

    MatrixAdd(size, &P1, &P2, &C12);

    MatrixAdd(size, &P3, &P4, &C21);

    MatrixAdd(size, &P5, &P1, &add1);
    MatrixAdd(size, &P3, &P7, &add2);
    MatrixMin(size, &add1, &add2, &C22);

    // 合并结果
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m0->matrix[i][j] = C11.matrix[i][j];
            m0->matrix[i][j + size] = C12.matrix[i][j];
            m0->matrix[i + size][j] = C21.matrix[i][j];
            m0->matrix[i + size][j + size] = C22.matrix[i][j];
        }
    }
}

void MatrixAdd(int n, JettyMatrix *m1, JettyMatrix *m2, JettyMatrix *m0) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            m0->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
}

void MatrixMin(int n, JettyMatrix *m1, JettyMatrix *m2, JettyMatrix *m0) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m0->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
}

void freeMatrix(JettyMatrix *matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
}
