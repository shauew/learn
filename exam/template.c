#include <stdio.h>

int factor (int n)
{
    if ((1 == n) || (0 == n)) {
        return 1;
    }
    return n * factor(n - 1);
}

int main (int argc, char *argv[])
{
    char a[20] = {0};
    char b[20] = {0};
    //scanf("%s %s", &a, &b);
    //printf("%s %s", a, b);

    int n, m, i;
    scanf("%d%d", &n, &m);
    int count = 1;
    // for (i = 1; i <= m; i++) {
    //     count *= n;
    //     count /= i;
    // }

    // count = factor(n);
    // count /= factor(n - m);
    permutation(n, m);
    printf("%d", count);
    return 0;
}



/* end of file */