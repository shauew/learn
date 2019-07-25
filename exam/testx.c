#include <stdio.h>

struct {
    int high;
    int low;
} list[100];

int main ()
{
    int n, k, i, value;
    int s[100];
    int min, max;
    int min_index, max_index;
    int loop = 0;

    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    while (1) {

        min = 10000;
        max = 0;

        for (i = 0; i < n; i++) {
            if (s[i] > max) {
                max = s[i];
                max_index = i;
            }
            if (s[i] < min) {
                min = s[i];
                min_index = i;
            }
        }

        value = max - min;
        s[max_index]--;
        s[min_index]++;

        list[loop].high = max_index;
        list[loop].low  = min_index;
        loop++;

        if ((value <= 1) || (loop == k)) {
            if (value == 0) {
                loop--;
            }
            break;
        }
    }

    printf("%d %d\n", value, loop);

    for (i = 0; i < loop; i++) {
        printf("%d %d\n", list[i].high + 1, list[i].low + 1);
    }

    return 0;
}