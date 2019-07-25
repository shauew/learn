// 题目描述
// •连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
// •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
// 输入描述:
// 连续输入字符串(输入2次,每个字符串长度小于100)
// 输出描述:
// 输出到长度为8的新字符串数组
// 示例1
// 输入
// abc
// 123456789
// 输出
// abc00000
// 12345678
// 90000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kprintf (char *s, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        putchar(s[i]);
    }
}

void fix_output (char *s)
{
    int len = strlen(s);
    int m = len / 8;
    int n = len % 8;
    int i;

    // 空字符串不处理
    if (s[0] == '\0') {
        return;
    }

    for (i = 0; i < m; i++) {
        kprintf(&s[i], 8);
        putchar('\n');
    }

    printf("%s", &s[i * 8]);
    for (i = 0; i < 8 - n; i++) {
        putchar('0');
    }
    putchar('\n');
}

int main ()
{
    char s1[100] = {0};
    char s2[100] = {0};

    gets(s1);
    gets(s2);

    fix_output(s1);
    fix_output(s2);

    return 0;
}
