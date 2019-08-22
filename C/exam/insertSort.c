#include <stdio.h>

void insertSort (int *a, int n) {
    int i = 0, j = 0, temp = 0;
    for (i = 1; i < n; i++) {
        temp = a[i];
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > temp) {
                a[j + 1] = a[j];  // 比temp 大的已排序数据后移一位
            } else {
                break;
            }
        }
        a[j + 1] = temp; // 空出来的位置，把temp放进去
    }
}

int main() {
    int a[] = {11, 7, 9, 22, 10, 18, 4, 43, 5, 1, 32};
    int n = sizeof(a) / sizeof(int);

    insertSort(a, n);
    printf("排序好的数组为：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}