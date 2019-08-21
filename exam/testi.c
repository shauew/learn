// 题目描述
// 为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，
// 牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准
// 来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
// 输入描述:
// 每个输入包含一个测试用例。
// 每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
// 接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
// 接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
// 保证不存在两项工作的报酬相同。
// 输出描述:
// 对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。
// 示例1
// 输入
// 3 3
// 1 100
// 10 1000
// 1000000000 1001
// 9 10 1000000000
// 输出
// 100
// 1000
// 1001

#include <stdio.h>
#include <stdlib.h>

typedef struct hashnode {
    struct hashnode *next;
    int pi;
} hashnode_t;
hashnode_t *pre, *next;
hashnode_t hashnodes[100000] = {[0 ... 100000 - 1] = {NULL, 0}};

int main ()
{
    int n, m, i, j;
    int di[100001] = {0};
    int pi[100001] = {0};
    int ai[100001] = {0};
    int index = 0;

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &di[i], &pi[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &ai[i]);
    }

    // 将工作按难度排序，并将最大薪酬放入当前难度中
    for (i = 0; i < n - 1; i++) {         // 小伙伴
        for (j = 0; j < n - 1 - i; j++) {
            if (di[j] > di[j + 1]) {
                int tempd = di[j], tempp = pi[j];
                di[j] = di[j + 1]; pi[j] = pi[j + 1];
                di[j + 1] = tempd; pi[j + 1] = tempp;
                if (pi[j] > pi[j + 1]) {    // 冒泡保留大的值
                    pi[j + 1] = pi[j];
                }
            }
        }
    }

    // 二分查找
    for (i = 0; i < m; i++) {         // 小伙伴
        int high = n - 1, low = 0;
        index = (high - low) / 2;
        while (1) {
            if ((ai[i] >= di[index]) && (ai[i] < di[index + 1])) {
                printf("%d\n", pi[index]);
                break;
            }
            if ((ai[i] == di[index + 1])) {
                printf("%d\n", pi[index + 1]);
                break;
            }
            if (ai[i] > di[index]) {
                if (high - index > 2) {
                    low = index;
                    index = (high - index) / 2;
                }
            } else {
                if (index - low > 2) {
                    high = index;
                    index = (index - low) / 2;
                }
            }
        }
    }

    return 0;
}

int main ()
{
    int n, m, i, j;
    int di[100000] = {0};
    int pi[100000] = {0};
    int ai[100000] = {0};

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &di[i], &pi[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &ai[i]);
    }

    // 暴力查找
    for (i = 0; i < m; i++) {         // 小伙伴
        int max = 0;
        for (j = 0; j < n; j++) {     // 难度
            if (ai[i] >= di[j]) {
                if (pi[j] > max) {
                    max = pi[j];
                }
            }
        }
        printf("%d\n", max);
    }

    return 0;
}