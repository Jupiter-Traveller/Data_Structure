#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "static_stack.h"
#include "dynamic_stack.h"
#include "test.h"
#include "double_stack.h"

void test_static ()
{
    ArrayStack s;
    initStack(&s);

    printf("===== 压栈测试 =====\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s);  // 预期: 栈顶 → [30] [20] [10] ← 栈底

    printf("\n===== peek 测试 =====\n");
    printf("栈顶元素: %d\n", peek1(&s));  // 预期: 30

    printf("\n===== 弹栈测试 =====\n");
    printf("弹出: %d\n", pop1(&s));  // 预期: 30
    printf("弹出: %d\n", pop1(&s));  // 预期: 20
    printStack(&s);  // 预期: 栈顶 → [10] ← 栈底

    printf("\n===== 边界测试 =====\n");
    pop1(&s);   // 弹出 10
    pop1(&s);   // 预期: 栈为空！无法弹出
}

void test_dynamic ()
{
    LinkedStack s;
    Dynamic_initStack(&s);

    printf("===== 压栈测试 =====\n");
    Dynamic_push(&s, 10);
    Dynamic_push(&s, 20);
    Dynamic_push(&s, 30);
    Dynamic_printStack(&s);                    // 预期: 栈顶 → [30] [20] [10] ← 栈底
    printf("栈大小: %d\n", s.size);    // 预期: 3

    printf("\n===== 弹栈测试 =====\n");
    printf("弹出: %d\n", Dynamic_pop(&s));     // 预期: 30
    Dynamic_printStack(&s);                    // 预期: 栈顶 → [20] [10] ← 栈底

    printf("\n===== 释放测试 =====\n");
    freeStack(&s);
    Dynamic_printStack(&s);  // 预期: 栈为空
}

void test_isBalanced ()
{
    char str[100];
    printf ("Please Enter a string: ");
    gets (str);
    printf ("%d", isBalanced (str));
}

void test_convert ()
{
    int n;
    printf ("Please Enter a number convert to binary: ");
    scanf ("%d", &n);
    convert (n);
}

void test_myQueue ()
{
    printf("--- 开始测试用两个栈实现队列 ---\n");
    
    MyQueue* q = myQueueCreate();
    
    myQueueEnqueue(q, 1); // 队列: [1]
    myQueueEnqueue(q, 2); // 队列: [1, 2]
    myQueueEnqueue(q, 3); // 队列: [1, 2, 3]
    
    printMyQueue (q); //应该为 [1, 2, 3]
    
    printf("出队元素 (应为1): %d\n", myQueueDequeue(q)); // 队列: [2, 3]
    printMyQueue (q); //应该为 [2, 3]

    myQueueEnqueue(q, 4); // 队列: [2, 3, 4]
    
    printf("出队元素 (应为2): %d\n", myQueueDequeue(q));
    printf("出队元素 (应为3): %d\n", myQueueDequeue(q));

    printMyQueue (q); //应该为 [4]
    printf("出队元素 (应为4): %d\n", myQueueDequeue(q)); // 队列: []
    
    printMyQueue (q);//无元素
    freeMyQueue (q);
}