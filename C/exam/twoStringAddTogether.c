#include <stdio.h>
#include <string.h>

#define SCALE 8

int main (int argc, char *argv[])
{
    char a[100] = {0};
    char b[100] = {0};
    char c[100] = {0}, temp[100] = {0};
    int   i = 0, n = 0;
    int   a_int = 0, b_int = 0, c_int = 0;

    scanf("%s %s", &a, &b);
    printf("a=%s b=%s\n", a, b);
    printf("alen=%d blen=%d\n", strlen(a), strlen(b));
    for (i = 0; i < strlen(a); i++) {
        a_int *= SCALE;
        a_int += a[i] - 'a';
    }

    for (i = 0; i < strlen(b); i++) {
        b_int *= SCALE;
        b_int += b[i] - 'a';
    }

    c_int = a_int + b_int;
    printf("%d = %d + %d\n", c_int, a_int, b_int);

    n = 0;
    do {
        temp[n] = (c_int % SCALE) + 'a';
        c_int /= SCALE;
        n++;
    }  while (c_int);       //进制转换

    // 逆序
    for (i = 0; i < strlen(temp); i++) {
        c[i] = temp[n - 1 - i];
    }

    printf("%s = %s + %s\n", c, a, b);
}

/* end of file */