#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a = 100;
    char s[100] = {0};

    itoa(a, s, 10);
    printf("10 %s\n", s);

    itoa(a, s, 2);
    printf("2  %s\n", s);

    itoa(a, s, 8);
    printf("8  %s\n", s);

    itoa(a, s, 16);
    printf("16 %s\n", s);

    itoa(a, s, 17);
    printf("17 %s\n", s);

    return 0;
}