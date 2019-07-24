// 计算字符串最后一个单词的长度，单词以空格隔开。

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