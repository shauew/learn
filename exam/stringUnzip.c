#include <stdio.h>
#include <string.h>

typedef struct string_part {
    char *start;
    int   len;
    int   repeat;
} string_part_t;

void kprintf (char *s, int len, int repeat)
{
    int i = 0, j = 0;
    for (i = 0; i < repeat; i++) {
        for (j = 0; j < len; j++) {
            putchar(s[j]);
        }
    }
}

int main (int argc, char *argv[])
{
    int i = 0, j = 0, count = 0;
    char s[50] = {0};
    string_part_t part[100];
    int start = 0;
    int index = 0;
    int temp[100] = {0};

    scanf("%s", &s);
    //printf("%s\n", s);

    for (i = 0; i < 100; i++) {

        start = index;

        part[i].start  = &s[index];
        part[i].len    = 0;
        part[i].repeat = 0;

        while (!((s[index] >= '0') && (s[index] <= '9'))) {
            index++;
        }
        //printf("out1\n");
        part[i].len = index - start;

        while ((s[index] >= '0') && (s[index] <= '9')) {
            part[i].repeat = part[i].repeat * 10 + s[index] - '0';
            index++;
        }
        //printf("out2\n");

        if (s[index] == '\0') {
            //printf("break\n");
            count = i + 1;
            break;
        }
    }

    //printf("count is %d\n", count);

    // 先使用冒泡排序把序号找到，之后再按重复次数分配打印
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i ; j++) {
            // 如果前面的数比后面大，进行交换
            // 因为间隔为数字，所以可以这样比较，即使字符串相同，也可由重复次数来协助判断顺序
            if (strcmp(part[j].start, part[j + 1].start)) {
                string_part_t temp   = part[j];
                part[j]     = part[j + 1];
                part[j + 1] = temp;
            }
        }
    }

    // 由低到高检索输出指定字符串
    for (j = 1; j < 100; j++) {
        //printf("len %d repeat %d\n", part[i].len, part[i].repeat);
        for (i = 0; i < count; i++) {
            if (j == part[i].repeat) {
                kprintf(part[i].start, part[i].len, part[i].repeat);
            }
        }
    }

    return 0;
}

/* end of file */