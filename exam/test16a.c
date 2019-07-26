// 背包问题

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10       // 物品最大件数
#define MAX_M 30       // 背包最大负重

// 价格 重量 背包重量 物品数量
int knapsack (int v[], int w[], int bag, int n)
{
    int i, j;
    int c[MAX_N][MAX_M] = {0};              // 缓存价值

    for(i = 1; i <= n; i++) {               // 共有m件物品  从1开始，避免0被选中 以及最初价值为0
        for(j = 0; j <= bag; j++) {         // 背包剩余重量
            c[i][j] = c[i - 1][j];          // 先装载不能放入背包时的值
            // 如果物品可以放下，判断价值大的可能来装载
            if ((w[i] <= j) && (c[i][j] < c[i - 1][j - w[i]] + v[i])) {
                c[i][j] = c[i - 1][j - w[i]] + v[i];
            }
        }
    }

    return c[n][bag];
}

int main ()
{
    int v[MAX_M], w[MAX_M], bag, n, i;
    scanf("%d%d", &w, &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &v[i], &w[i]);
    }
    printf("%d\n", knapsack(v, w, bag, n));
    return 0;
}