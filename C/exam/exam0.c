// 举办一场8小时的聚会，时间段从12：00到20：00点，让来访的客人事先填写好到达的时间和离开的时间，
// 为了掌握聚会期间座位的数目，需要先估计不同时间的最大客人数量。

// 到达和离开的时间，以整点计算，输入为整数，比如“12，18”表示该客人到达时间为12点后13点前，离开时间是17点后18点前
// 按小时区间统计客人的数量，需要统计[12,13)，[13,14)…[19,20)共8个时间段的最大客人数量假设邀请的客人最多100个
// 题目给了一个样例：假设输入为[12,15)，[16,17)，[12,20)，输出为[12,13)：2，[13,14)：2，[14,15)：2，[15,16)：1，
// [16,17)：1，[17,18)：1，[18,19)：1，[19,20)：1        

// 对样例进行分析发现，每个区间的最大客人数量是通过计算能够覆盖该区间的所有客人的时间区间的数量得到的，
// 这样做是有道理的，因为题目要求我们计算的是每个时间段的最大客人数量，如果一个客人的时间区间包含了
// 某个时间段，那么我们有理由认为这个客人会在这个时间段来访。以计算[12,13)时间段的最大客人数量为例，
// [12,15)区间能够覆盖[12,13)时间段，[16,17)区间不能覆盖，[12,20)区间能够覆盖，所以[12,13)区间的
// 最大客人数量为2，其他的时间段以此类推。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 宏定义random */
#define random(x) (rand() % (x))

/* 时间表 */
typedef struct time_list {
    int arrive;
    int leave;
} time_list_t;

/* 获取原始随机表 */
int time_list_get (time_list_t *p_time_list)
{
    p_time_list->arrive = 12 + random(20 - 12);     /* 最大只能是19 */
    p_time_list->leave  = p_time_list->arrive + 1 + (random(20 - p_time_list->arrive));
    return 0;
}

/* 计算处在给定间隔之间的数目 */
int count_by_time_interval (int lower_bound, int higher_bound, time_list_t *p_time_list, int list_len)
{
    int i = 0, count = 0;

    for (i = 0; i < list_len; ++i) {
        if ((lower_bound  >= p_time_list[i].arrive) &&
            (higher_bound <= p_time_list[i].leave)) {
            count++;
        }
    }

    printf("[%d,%d):%d\n", lower_bound, higher_bound, count);

    return count;
}

/* 主函数 */
int main (int argc, char *argv[])
{
    int i = 0;
    int num_list[] = {12, 13, 14, 15, 16, 17, 18, 19, 20};
    time_list_t customer_list[100] = {0};

    /* 种下随机数种子 */
    srand((unsigned)time(NULL));

    /* 生成随机表 */
    for (i = 0; i < 100; ++i) {
        time_list_get(&customer_list[i]);
    }

    /* 检索分段 */
    for (i = 0; i < 8; ++i) {
        count_by_time_interval(num_list[i], num_list[i + 1], &customer_list[0], 100);
    }

    return 0;
}

/* end of file */