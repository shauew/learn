#include <stdio.h>

int main ()
{
    int n;
    long s[100];
    int i;
    long t1 = 0;
    long t2 = 0;
    long max = 0;
    int index1 = 0, index2 = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    index1 = 0;
    index2 = n - 1;
    t1 += s[index1++];
    t2 += s[index2--];
    for (i = 0; i < n; i++) {
        if (t1 < t2) {
            t1 += s[index1++];
        } else if (t1 > t2) {
            t2 += s[index2--];
        }
        if (t1 == t2) {
            max = t1;
            t1 += s[index1++];
        }
        if (index1 - 1 >= index2 + 1) {
            break;
        }
    }

    printf("%d", max);

    return 0;
}