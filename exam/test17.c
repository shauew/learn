// 17.坐标移动
// 题目描述
// 开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
// 输入：
// 合法坐标为A(或者D或者W或者S) + 数字（两位以内）
// 坐标之间以;分隔。
// 非法坐标点需要进行丢弃。如AA10; A1A; $%$; YAD; 等。
// 下面是一个简单的例子 如：
// A10;S20;W10;D30;X;A1A;B10A11;;A10;
// 处理过程：
// 起点（0,0）
// + A10 = （-10,0）
// + S20 = (-10,-20)
// + W10 = (-10,-10)
// + D30 = (20,-10)
// + x = 无效
// + A1A = 无效
// + B10A11 = 无效
// + 一个空 不影响
// + A10 = (10,-10)
// 结果 （10， -10）
// 输入描述:
// 一行字符串
// 输出描述:
// 最终坐标，以,分隔
// 示例1
// 输入
// A10;S20;W10;D30;X;A1A;B10A11;;A10;
// 输出
// 10,-10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int x = 0, y = 0, move = 0, i, j, k;
    char s[100] = {0};
    char *ptr = NULL;
    char *str = &s[1];
    gets(&s[1]);
    s[0] = ';';
    while (1) {
        char *op, *a, *b, *pre;
        ptr = strchr(str, ';');
        if (ptr == NULL) {
            printf("null\n");
            break;
        }
        pre = ptr - 4;
        op  = ptr - 3;
        a   = ptr - 2;
        b   = ptr - 1;

        if ((*a >= '0' && *a <= '9') &&
            (*b >= '0' && *b <= '9') &&
            (*pre == ';')) {
            move = (*a - '0') * 10 + (*b - '0');
            switch (*op) {
                case 'A':
                    x -= move;
                break;

                case 'D':
                    x += move;
                break;

                case 'W':
                    y += move;
                break;

                case 'S':
                    y -= move;
                break;

                default:
                break;
            }
        }
        printf("(%d, %d) %s\n", x, y, str);
        str = ptr + 1;
        if (*str == '\0') {
            printf("end\n");
            break;
        }
    }

    printf("(%d, %d)", x, y);

    return 0;
}