// 8.合并表记录（此题出的不够好不够准确）
// 题目描述
// 数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
// 输入描述:
// 先输入键值对的个数
// 然后输入成对的index和value值，以空格隔开
// 输出描述:
// 输出合并后的键值对（多行）
// 示例1
// 输入
// 4
// 0 1
// 0 2
// 1 2
// 3 4
// 输出
// 0 3
// 1 2
// 3 4

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n = 0, i = 0, k = 0, v = 0;
    int key[100]   = {0};
    int value[100] = {0};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &k, &v);
        value[k] += v;
        key[k] = 1;
    }

    for (i = 0; i < 100; i++) {
        if (1 == key[i]) {
            printf("%d %d\n", i, value[i]);
        }
    }

    return 0;
}