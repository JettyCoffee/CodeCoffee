#include <stdio.h>

// 合并两个有序数组
void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // 将左半边剩余的元素复制到 arr
    while (i < left_size) {
        arr[k++] = left[i++];
    }

    // 将右半边剩余的元素复制到 arr
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

// 归并排序函数
void merge_sort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    // 计算中间索引
    int middle = size / 2;

    // 分别对左右两半进行排序
    merge_sort(arr, middle);
    merge_sort(arr + middle, size - middle);

    // 合并两个有序数组
    int left[middle];
    int right[size - middle];

    // 将数组分为左右两半
    for (int i = 0; i < middle; i++) {
        left[i] = arr[i];
    }

    for (int i = middle; i < size; i++) {
        right[i - middle] = arr[i];
    }

    // 合并左右两半
    merge(arr, left, middle, right, size - middle);
}

// 打印数组
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 示例用法
int main() {
    int arr[] = {38, 27, 43, 3, 3, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组: ");
    print_array(arr, size);

    merge_sort(arr, size);

    printf("排序后的数组: ");
    print_array(arr, size);

    return 0;
}
