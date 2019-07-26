// 10.字符个数统计
// 题目描述
// 编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
// 输入描述:
// 输入N个字符，字符在ACSII码范围内。
// 输出描述:
// 输出范围在(0~127)字符的个数。
// 示例1
// 输入
// abc
// 输出
// 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char s[1000] = {0};
    char c[128] = {0};
    int i, len;
    int n = 0;

    scanf("%s", &s);
    len = strlen(s);
    for (i = 0; i < len; i++) {
        c[s[i]] = 1;
    }

    for (i = 0; i < 128; i++) {
        if (c[i] == 1) {
            n++;
        }
    }

    printf("%d", n);

    return 0;
}