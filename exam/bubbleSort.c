#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//-finput-charset=GB2312 选择输入文件的编码
//-fexec-charset=GB2312  选择输出文件的编码

/* 宏定义random */
#define random(x) (rand() % (x))

// 基本思想：比较相邻的两个数，如果前者比后者大，则进行交换。每一轮排序结束，选出一个未排序中最大的数放到数组后面。
// 冒泡排序算法
void bubble_sort (int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i ; j++) {
            // 如果前面的数比后面大，进行交换
            if (arr[j] > arr[j + 1]) {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main (int argc, char *argv[])
{
    int i = 0;
    int n = 0;
    int *arr = NULL;

    if (1 == argc) {
        printf("请输入需要生成的排序数组数：\n");
        return 0;
    }

    n = atoi(argv[1]);
    arr = malloc(n);

    /* 种下随机数种子 */
    srand((unsigned)time(NULL));

    /* 生成随机表 */
    for (i = 0; i < n; ++i) {
        arr[i] = random(10);
    }

    bubble_sort(arr, n);
    printf("排序后的数组为：\n");
    for (int j = 0; j<n; j++)
        printf("%d ", arr[j]);
    printf("\n");
    return 0;
}

/* end of file */