// 题目描述
// 写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
// 输入描述:
// 输入一个十六进制的数值字符串。
// 输出描述:
// 输出该数值的十进制字符串。
// 示例1
// 输入
// 0xA
// 输出
// 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char s[1000];
    char *index;
    int  v = 0;

    scanf("%s", &s);
    index = strstr(s, "0x");
    index += 2;

    while (*index != '\0') {
        int temp = 0;
        if ((*index >= 'A') && (*index <= 'F')) {
            temp = *index - 'A' + 10;
        } else if ((*index >= 'a') && (*index <= 'f')) {
            temp = *index - 'a' + 10;
        } else if ((*index >= '0') && (*index <= '9')) {
            temp = *index - '0';
        } else {
            index++;
            continue;
        }
        index++;
        v = v * 16 + temp;
    }

    printf("%d", v);

    return 0;
}