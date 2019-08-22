// 6.质数因子
// 题目描述
// 功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
// 最后一个数后面也要有空格

#include <stdio.h>
#include <stdlib.h>

void factor (int n)
{
    int i = 0;

    // 使用短除法的形式来作解即可
    while (n) {
        for (i = 2; i <= n; i++) {
            if ((n % i) == 0) {
                printf("%d ", i);
                break;
            }
        }
        n /= i;
    }
}

int main ()
{
    int n;
    scanf("%d", &n);
    factor(n);
    return 0;
}