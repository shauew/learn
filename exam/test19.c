// 19.简单密码（明暗码转换）（完全自编，漂亮）
// 题目描述
// 密码是我们生活中非常重要的东东，我们的那么一点不能说的秘密就全靠它了。哇哈哈. 接下来渊子要在密码之上再加一套密码，
// 虽然简单但也安全。
// 假设渊子原来一个BBS上的密码为zvbo9441987,我们称之为暗码，也为真正的密码。为了方便记忆，他通过一种算法把这个密码
// 变换成YUANzhi1987，这个密码是他的名字和出生年份，怎么忘都忘不了，而且可以明目张胆地放在显眼的地方而不被别人知道
// 真正的密码，我们称YUANzhi1987为明码，也为虚假的密码。

// 他是怎么从明码变换到暗码的？渊子做了如下几步：
// 把明码中出现的大写字母则变成小写之后往后移一位，如：X，先变成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。
// 按照“abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9”的规则，将明码中的小写字母都转换为数字
// 明码中除了大小写字母外的其他字符不变换

// 声明：密码中没有空格

// 输入描述:
// 输入包括多个测试数据。输入是一个明文，密码长度不超过100个字符，输入直到文件结尾
// 输出描述:
// 输出渊子真正的密文
// 示例1
// 输入
// YUANzhi1987
// 输出
// zvbo9441987

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char s[100];
    int i;
    while (scanf("%s", s) != EOF) {
        for (i = 0; i < strlen(s); i++) {
            char temp = (s[i]);
            if ((temp >= 'A') && (temp <= 'Y')) {temp += 'a' - 'A' + 1;}
            else if (temp == 'Z') {temp = 'a';}
            else if ((temp >= 'a') && (temp <= 'c')) {temp = '2';}
            else if ((temp >= 'd') && (temp <= 'f')) {temp = '3';}
            else if ((temp >= 'g') && (temp <= 'i')) {temp = '4';}
            else if ((temp >= 'j') && (temp <= 'l')) {temp = '5';}
            else if ((temp >= 'm') && (temp <= 'o')) {temp = '6';}
            else if ((temp >= 'p') && (temp <= 's')) {temp = '7';}
            else if ((temp >= 't') && (temp <= 'v')) {temp = '8';}
            else if ((temp >= 'w') && (temp <= 'z')) {temp = '9';}
            putchar(temp);
        }
    }

    return 0;
}