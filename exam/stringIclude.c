#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
    char a[100] = {0};
    char b[100] = {0};
    char c[100] = {0}, temp[100] = {0};
    int   i = 0, n = 0;
    int   a_int = 0, b_int = 0, c_int = 0;

    scanf("%s%s", &a, &b);

    if ((strlen(a) < 5) || (strlen(b) < 5)) {
        printf("Less than 5 characters.\n");
        return 0;
    }

    for (i = 0; i < strlen(a); i++) {
        a_int |= 1 << (a[i] - 'A');
    }

    for (i = 0; i < strlen(b); i++) {
        b_int |= 1 << (b[i] - 'A');
    }

    c_int = 1;
    for (i = 0; i < 26; i++) {
        // A不能比B大
        if ((a_int & 1) > (b_int & 1)) {
            c_int = 0;
            break;
        }
        a_int >>= 1;
        b_int >>= 1;
    }

    if (c_int) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
}

/* end of file */