#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count[10] = {0}; // 记录每个数字出现的次数

    // 处理每个整数
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        while (num != 0) {
            int digit = num % 10;
            count[digit]++;
            num /= 10;
        }
    }

    // 找到出现次数最多的数字
    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }

    // 输出出现次数最多的数字
    int first = 1; // 用于判断是否为第一个数字，以避免输出多余的空格
    for (int i = 0; i < 10; i++) {
        if (count[i] == maxCount) {
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
        }
    }

    return 0;
}
