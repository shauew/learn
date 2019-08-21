#include <stdio.h>
#include <stdlib.h>

int* twoSum (int* nums, int numsSize, int target, int *returnSize) {

    #define HASHSIZE 40960
    #define HASHEND (HASHSIZE - 1)

    int i, h0, h1, found;
    int *ret = (int *)malloc(sizeof(int) * 2);

    typedef struct hashnode hashnodes_t;
    typedef struct hashnode {
        int index;          // 节点的索引
        int num;            // 想要查找的数
        hashnodes_t *next;
    };
    hashnodes_t hashnodes[HASHSIZE] = {[0 ... HASHEND] = {-1, 0, NULL}};
    hashnodes_t *next = NULL, *pre = NULL;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++) {

        h0 = nums[i] < 0 ? (0 - nums[i]) % HASHSIZE : nums[i] % HASHSIZE;                               // nums[i] 的绝对值，正负共用一个点
        h1 = target - nums[i] < 0 ? (nums[i] - target) % HASHSIZE : (target - nums[i]) % HASHSIZE;      // target 与 num[i] 差的绝对值，正负共用一个点
        found = 0;

        if (hashnodes[h1].index > -1) {                     // 如果目标出现
            next = (hashnodes_t *)&hashnodes[h1];           // 装载next
            do {
                pre = next;
                if (nums[i] == next->num) {                 // 排查是否有我们需要的目标点
                    found = 1;
                    break;
                }
                next = pre->next;
            } while (next != NULL);
        }

        if (found) {                // 找到就退出
            ret[0] = pre->index;
            ret[1] = i;
            *returnSize = 2;
            break;
        } else {                    // 找不到就装表
            if (hashnodes[h0].index == -1) {             // 节点还未被填充，先填充第一个
                hashnodes[h0].index = i;
                hashnodes[h0].num = target - nums[i];
            } else {                                    // 节点已经被填充，链入末尾
                next = (hashnodes_t *)&hashnodes[h0];   // 链头
                do {            // 查找表的末尾
                    pre  = next;
                    next = pre->next;
                } while (next != NULL);  // 至此 next为空
                // 更新链尾
                pre->next = (hashnodes_t *)malloc(sizeof(hashnodes_t));     // 分配空间加载到末尾
                pre->next->index = i;
                pre->next->num   = target - nums[i];
                pre->next->next  = NULL;
            }
        }
    }

    return ret;
}

int main ()
{
    int nums[] = {2, 7, 11, 15}, target = 9;
    int *p = NULL;
    int ret;
    p = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &ret);
    printf("[%d, %d]", p[0], p[1]);
    free(p);
    return 0;
}