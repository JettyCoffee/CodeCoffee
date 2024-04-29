/*卷积核
卷积核（Convolutional Kernel）操作是计算机视觉和图像处理中常用的一种操作，用于提取图像中的特征。下面是对卷积核操作的详细介绍：
卷积核：卷积核是一个小的矩阵，它包含了一组权重参数。通常，卷积核的大小是正方形的，比如3x3、5x5等。卷积核的参数可以通过训练来学习，也可以手动定义。
卷积操作：卷积操作是将卷积核应用于输入图像的过程。具体来说，将卷积核的每个元素与输入图像的对应位置进行相乘，然后将所有乘积结果相加，得到输出图像中对应位置的像素值。
步幅（Stride）：步幅是指卷积核在输入图像上滑动的步长。步幅越大，输出图像的尺寸就越小；步幅越小，输出图像的尺寸就越大。常见的步幅为1，表示卷积核每次滑动一个像素。
==========================================================================================================================================================

今天你将实现一个卷积操作！
简单来说，本题给出两个矩阵
一个大小为n*n的输入矩阵，一个大小为m*m的矩阵（卷积核）
将卷积核在输入矩阵上按照上面动图的方式移动，
每次计算出卷积核和输入矩阵对应位置数字乘积之和，
填入输出矩阵的对应位置，最后给出输出矩阵的大小和值。

输入
第1行两个由空格分隔的整数，分别是n,m（1<=m<=n<=50）
接下来n行，每行n个由空格分隔的整数x[i][j]（1<=x[i][j]<=50），表示输入矩阵第i行第j列位置的数值。
接下来m行，每行m个由空格分隔的整数y[i][j]（1<=y[i][j]<=50），表示卷积核第i行第j列位置的数值。

输出
输出第一行，由空格分隔的两个整数p,q，表示输出矩阵的是一个p行q列的矩阵。
接下来的p行，每行q个由空格分隔的整数s[i][j]。表示输出矩阵第i行第j列位置的数值。

*/
#include <stdio.h>
#define SIZE 50

typedef struct array{
    int data[SIZE][SIZE];
    int kernel[SIZE][SIZE];
}JettyArray;

int Convolutional(JettyArray *array, int line,int row,int m){
    int sum = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            sum += array->kernel[i][j] * array->data[i+row][j+line];
        }
    }
    return sum;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    JettyArray array;
    int data[n][n], kernel[m][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&array.data[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&array.kernel[i][j]);
        }
    }
    printf("%d %d\n",n-m+1,n-m+1);
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            printf("%d",Convolutional(&array,j,i,m));
            if(j != n-m){
                printf(" ");
            }
            if(j == n-m){
                printf("\n");
            }
        }
    }
    

}