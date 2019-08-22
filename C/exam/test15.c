// 15.求int型正整数在内存中存储时1的个数
// 题目描述
// 输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
// 输入描述:
// 输入一个整数（int类型）
// 输出描述:
// 这个数转换成2进制后，输出1的个数
// 示例1
// 输入
// 5
// 输出
// 2

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, i = 0;
    scanf("%d", &n);
    while (n) {
        if (n & 0x1) {
            i++;
        }
        n >>= 1;
    }
    printf("%d", i);
    return 0;
}