// 18.密码验证合格程序
// 题目描述
// 密码要求:
// 1.长度超过8位
// 2.包括大小写字母.数字.其它符号,以上四种至少三种
// 3.不能有相同长度超2的子串重复
// 说明:长度超过2的子串
// 输入描述:
// 一组或多组长度超过2的子符串。每组占一行
// 输出描述:
// 如果符合要求输出：OK，否则输出NG
// 示例1
// 输入
// 021Abc9000
// 021Abc9Abc1
// 021ABC9000
// 021$bc9000
// 输出
// OK
// NG
// NG
// OK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char s[20];
    while (scanf("%s", s) != EOF) {
        int flag = 0, i = 0, lock = 0b1111;
        if (strlen(s) < 8) {
            printf("NG\n");
            goto end;
        }
        for (i = 0; i < strlen(s); i++) {
            if ((s[i] >= 'A') && (s[i] <= 'Z')) {
                if ((lock & 0b0001)) {
                    flag++;
                    lock &= 0b1110;
                }
            } else if ((s[i] >= 'a') && (s[i] <= 'z')) {
                if ((lock & 0b0010)) {
                    flag++;
                    lock &= 0b1101;
                }
            } else if ((s[i] >= '0') && (s[i] <= '9')) {
                if ((lock & 0b0100)) {
                    flag++;
                    lock &= 0b1011;
                }
            } else if (lock & 0b1000) {
                flag++;
                lock &= 0b0111;
            }
        }
        if (flag < 3) {
            printf("NG\n");
            goto end;
        }
        for (i = 0; i < strlen(s) - 4; i++) {
            char temp[3] = {s[i], s[i + 1], 0};
            if (strstr(&s[i + 2], temp)) {
                printf("NG\n");
                goto end;
            }
        }

        printf("OK\n");
        end:
        i = 0;
    }

    return 0;
}