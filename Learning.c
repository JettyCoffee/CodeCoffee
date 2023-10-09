#include <stdio.h>
#include <math.h>

int main() {
    int n, count, hua, i, temp, temp1;
    count = 0;
    
    // 输入n，表示要计算各位数字的n次方之和
    scanf("%d", &n);
    
    // 计算范围的起始和结束数字
    i = pow(10, n);
    temp1 = pow(10, (n + 1));
    
    // 从起始数字到结束数字循环
    for (i; i < temp1; i++) {
        hua = 0;
        
        // 对于每个数字，计算各位数字的n次方之和
        for (int m = 1; m <= n + 1; m++) {
            temp = 0;
            int mid = pow(10, m);
            temp = i / mid; // 获取各位数字
            hua += pow(temp, n); // 计算各位数字的n次方之和
        }
        
        // 如果各位数字的n次方之和等于该数字本身，则计数加1
        if (hua == i) {
            count++;
        }
    }
    
    // 输出满足条件的特殊数的数量
    printf("%d\n", count);
    
    return 0;
}