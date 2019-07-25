// 2.计算字符个数
// 题目描述
// 写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
// 输入描述:
// 输入一个有字母和数字以及空格组成的字符串，和一个字符。
// 输出描述:
// 输出输入字符串中含有该字符的个数。
// 示例1
// 输入
// ABCDEF A
// 输出
// 1

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char a[5000] = {0};
    char b = 0;
    int i = 0;
    int count = 0;

    gets(a);
    b = getchar();
    //scanf("%s %c", &a, &b);

    while (a[i]) {
        if ((a[i] >= 'A') && (a[i] <= 'Z')) {
            if ((a[i] == b) || ((a[i] + 32) == b)) {
                count++;
            }
        } else if ((a[i] >= 'a') && (a[i] <= 'z')) {
            if ((a[i] == b) || ((a[i] - 32) == b)) {
                count++;
            }
        } else if (a[i] == b) {
            count++;
        }
        i++;
    }

    printf("%d", count);

    return 0;
}