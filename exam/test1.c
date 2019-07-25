// 1. 字符串最后一个单词的长度
// 题目描述
// 计算字符串最后一个单词的长度，单词以空格隔开。
// 输入描述:
// 一行字符串，非空，长度小于5000。
// 输出描述:
// 整数N，最后一个单词的长度。
// 示例1
// 输入
// hello world
// 输出
// 5

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char s[5000] = {0};
    int i = 0;
    int count = 0;

    gets(s);

    while (s[i]) {
        if (s[i] != ' ') {
            count++;
        } else {
            count = 0;
        }
        i++;
    }

    printf("%d", count);

    return 0;
}