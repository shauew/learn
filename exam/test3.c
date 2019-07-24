// 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
// 对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，
// 按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。

// 注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。
// 输入描述:
// 输入多行，先输入随机整数的个数，再输入相应个数的整数
// 输出描述:
// 返回多行，处理后的结果

#include <stdio.h>
#include <stdlib.h>

// int main ()
// {
//     int n, i, j;
//     int s[1000] = {0};
//     char temp[5] = {0};

//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%s", &temp);
//         s[i] = atoi(temp);
//     }

//     for (i = 0; i < n - 1; i++)  {
//         for (j = 0; j < n - 1 - i; j++) {
//             if (s[j] > s[j + 1]) {
//                 int temp;
//                 temp = s[j];
//                 s[j] = s[j + 1];
//                 s[j + 1] = temp;
//             }
//         }
//     }

//     for (i = 0; i < n; i++) {
//         if (s[i] != s[i + 1]) {
//             printf("%d\n", s[i]);
//         }
//     }
// }

int main ()
{
    int n, i, j;
    int s[1001] = {0};
    char temp[5] = {0};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int index = 0;
        scanf("%s", &temp);
        index = atoi(temp);
        s[index] = 1;
    }

    for (i = 0; i < 1001; i++) {
        if (s[i] == 1) {
            printf("%d\n", i);
        }
    }
}