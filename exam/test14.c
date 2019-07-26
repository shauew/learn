// 14.字符串的连接最长路径查找（将字符串按照英文字母字典序排列）
// 题目描述
// 给定n个字符串，请对n个字符串按照字典序排列。
// 输入描述:
// 输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
// 输出描述:
// 数据输出n行，输出结果为按照字典序排列的字符串。
// 示例1
// 输入
// 9
// cap
// to
// cat
// card
// two
// too
// up
// boat
// boot
// 输出
// boat
// boot
// cap
// card
// cat
// to
// too
// two
// up

#include <stdio.h>
#include <string.h>

int lettercmp (char *s1, char *s2)
{
    int i = 0;
    while ((s1[i] != '\0') && (s2[i] != '\0')) {
        if ((s1[i] >= 'A') && (s1[i] <= 'Z') &&
            (s2[i] >= 'a') && (s2[i] <= 'z')) {
            return 1;
        } else if ((s1[i] >= 'a') && (s1[i] <= 'z') &&
                   (s2[i] >= 'A') && (s2[i] <= 'Z')) {
            return 0;
        } else {
            if (s1[i] > s2[i]) {
                return 1;
            } else if (s1[i] < s2[i]) {
                return 0;
            }
        }
        i++;
    }
    if (s1[i] > s2[i]) {
        return 1;
    } else {
        return 0;
    }
}

int main ()
{
    int n, i, j;
    char s[1000][100] = {0};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (lettercmp(s[j], s[j + 1]) > 0) {            // 比较字符串
                char temp[100] = {0};
                memcpy(temp, s[j], strlen(s[j]));
                memset(s[j], 0, strlen(s[j]));
                memcpy(s[j], s[j + 1], strlen(s[j + 1]));
                memset(s[j + 1], 0, strlen(s[j + 1]));
                memcpy(s[j + 1], temp, strlen(temp));
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    return 0;
}