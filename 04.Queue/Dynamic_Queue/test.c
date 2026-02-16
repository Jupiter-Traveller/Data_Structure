#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"
#include "test.h"

void test ()
{
    LinkedQueue q;
    initQueue(&q);

    printf("===== 入队测试 =====\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);  // 预期: 队头 → [10] [20] [30] ← 队尾

    printf("\n===== 出队测试 =====\n");
    printf("出队: %d\n", dequeue(&q));  // 预期: 10
    printQueue(&q);  // 预期: 队头 → [20] [30] ← 队尾

    printf("\n===== 边界测试 =====\n");
    dequeue(&q);  // 20
    dequeue(&q);  // 30
    dequeue(&q);  // 预期: 队列为空！
    printQueue(&q);

    // 空了之后重新入队，验证 front/rear 都正确重置
    enqueue(&q, 99);
    printQueue(&q);  // 预期: 队头 → [99] ← 队尾

    freeQueue(&q);
}

void test_JosephRing ()
{
    int n, k;
    printf ("Please Enter total number: ");
    scanf ("%d", &n);
    printf ("Please Enter number: ");
    scanf ("%d", &k);
    JosephRing (n, k);
}
