//按要求分解字符串，输入两个数M，N；M代表输入的M串字符串，N代表输出的每串字符串的位数，不够补0。
//例如：输入2,8， “abc” ，“123456789”，则输出为“abc00000”,“12345678“,”90000000”

#include <stdio.h>
#include <string.h>

void kprintf (char *s, int len)
{
    int j = 0;
    for (j = 0; j < len; j++) {
        putchar(s[j]);
    }
}

int solve (char *s, int len, int n)
{
    int a = len / n;
    int b = len % n;
    int i;

    for (i = 0; i < a; i++) {
        kprintf(&s[i * n], n);
        putchar(' ');
    }

    if (b) {
        kprintf(&s[i * n], b);
        for (i = 0; i < (n - b); i++) {
            putchar('0');
        }
        putchar(' ');
    }
}

int main (int argc, char *argv[])
{
    char s[1000] = {0};
    int i, m, n;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++) {
        scanf("%s", &s);
        solve(s, strlen(s), n);
    }

    return 0;
}



/* end of file */