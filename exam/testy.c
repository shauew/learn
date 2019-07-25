#include <stdio.h>

// 组合
int combination (int n, int m)
{
    if ((m == 0) || (m == n)) {
        return 1;
    }
    return combination(n - 1, m) + combination(n - 1, m - 1);
}

// 排列
int permutation  (int n, int m)
{
    if (m == 1) {
        return n;
    }
    return n * permutation(n - 1, m - 1);
}

// int main ()
// {
//     int n, m, k;
//     int sum = 0;
//     int i, a, b, index = 0;
//     char s[100] = {0};
//     int comb = 0;

//     scanf("%d%d%d", &n, &m, &k);

//     if (k > combination(n + m, n)) {
//         printf("%s", "-1");
//         return -1;
//     }

//     while (n & m) {

//         comb = combination(n - 1 + m, n - 1);
//         if (k <= comb) {
//             s[index++] = 'a';
//             n--;
//         } else {
//             s[index++] = 'z';
//             m--;
//             k -= comb;
//         }
//     }

//     printf("%s", s);

//     return -1;
// }

int main()
{
    int n, m, k;
    int i;
    int index = 0;
    char s[200];

    scanf("%d%d%d", &n, &m, &k);

    while (n && m) {

        long long count = 1;

        // 采用排列
        // Cn^m = n!/(m!*(n-m)!)
        // 替换其中的 n 为 m + n; m不变;
        // 得 count = (m+n)!/(m!*n!)
        // => (m+n)(m+n-1)(m+n-2)...(m+1)m!/(m!*(n)(n-1)(n-2)...(1))
        // => (m+n)(m+n-1)(m+n-2)...(m+1)/((n)(n-1)(n-2)...(1))
        // 下面是 n-1 与 m 的组合（即假设首字符为a）
        // 组合能取整成功，不用担心
        for (i = 1; i < n; i++) {
            count *= m + i;
            count /= i;
            if (count > k) {    // 防止越界。count>k就可以退出计算了
                break;
            }
        }

        // 每次都是假定首字符为a，所以排列一直是到n-1
        if (k <= count) {
            s[index++] = 'a';   // 如果k小于等于count，则表明首字符的确应为a，k还在剩下的字符里
            n--;                // 问题缩减为 n--个a和m个z 中找第k大
        } else {
            s[index++] = 'z';   // 问题缩减为 n个a和m--个z中找第k-count大 （顺序可以参考正负数的界限补码，生长方向相同）
            m--;                // 相当于从头再假设第一个字符为a
            k -= count;
        }
    }

    // 循环结束后，即n或m为0时；剩余子序列只存在全"a"或全"z"中的一种情况
    if (k != 1) {
        printf("-1");
        return 0;
    }

    // 补足剩下的字符
    while (n--) {
        s[index++] = 'a';
    }
    while (m--) {
        s[index++] = 'z';
    }
    s[index] = 0;

    printf("%s", s);

    return 0;
}