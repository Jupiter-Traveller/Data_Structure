#include <stdio.h>
#include <stdlib.h>
#include "static.queue.h"

void test ()
{
    ArrayQueue q;
    initQueue(&q);

    printf("===== 入队测试 =====\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    printQueue(&q);  // 预期: 队头 → [10] [20] [30] [40] [50] ← 队尾
    printf("大小: %d\n", getSize(&q));  // 预期: 5

    enqueue(&q, 60);  // 预期: 队列已满！

    printf("\n===== 出队测试 =====\n");
    printf("出队: %d\n", dequeue(&q));  // 预期: 10
    printf("出队: %d\n", dequeue(&q));  // 预期: 20
    printQueue(&q);  // 预期: 队头 → [30] [40] [50] ← 队尾

    printf("\n===== 循环验证 =====\n");
    // 出队释放了前面两个位置，再入队应该"绕回去"
    enqueue(&q, 60);
    enqueue(&q, 70);
    printQueue(&q);  // 预期: 队头 → [30] [40] [50] [60] [70] ← 队尾
    printf("大小: %d\n", getSize(&q));  // 预期: 5

    printf("\n===== 查看队头 =====\n");
    printf("队头: %d\n", front(&q));  // 预期: 30
}