// 写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char a[5000] = {0};
    char b = 0;
    int i = 0;
    int count = 0;

    scanf("%s %c", &a, &b);

    while (a[i]) {
        if (a[i] == b) {
            count++;
        }
        i++;
    }

    printf("%d", count);

    return 0;
}