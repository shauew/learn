// 9.从右至左提取不重复的整数（完全自己编的，棒）
// 题目描述
// 输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
// 输入描述:
// 输入一个int型整数
// 输出描述:
// 按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
// 示例1
// 输入
// 9876673
// 输出
// 37689

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int may_pow (int a, int b)
{
    int ret = 1;
    int i;

    for (i = 0; i < b; i++) {
        ret *= a;
    }

    return ret;
}

int main ()
{
    int m = 0, n = 0, temp = 0, flag = 0, i = 0, n1 = 0;

    scanf("%d", &m);

    while (m) {

        temp = m % 10;

        // 把0~9数字全部取尽即可
        if (!((1 << temp) & flag)) {
            //n = n + (temp * (int)may_pow(10, i++));
            n = n * 10 + temp;
            flag |= (1 << temp);
        }

        m = m / 10;
    }

    printf("%d", n);

    return 0;
}