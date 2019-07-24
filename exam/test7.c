// 7.四舍五入求整（需要滚瓜烂熟的3行程序）
// 题目描述
// 写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
// 输入描述:
// 输入一个正浮点数值
// 输出描述:
// 输出该数值的近似整数值
// 示例1
// 输入
// 5.5
// 输出
// 6

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float f = 0;
    //double f = 0;
    //char s[1000] = {0};
    scanf("%f", &f);
    //scanf("%lf", &f);       // 输入double的时候需要使用%lf
    // scanf("%s", &s);
    // f = atof(s);
    printf("%f\n", f);
    printf("%d", (int)(f + 0.5));
    return 0;
}