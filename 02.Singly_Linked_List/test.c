#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "test.h"

void test ()
{
    Node *head = NULL;  // 初始化空链表
    
    printf("===== 测试头插法 =====\n");
    insertAtHead1(&head, 30);
    insertAtHead1(&head, 20);
    insertAtHead1(&head, 10);
    printList(head);  // 预期: [10] -> [20] -> [30] -> NULL
    
    printf("\n===== 测试尾插法 =====\n");
    insertAtEnd1(&head, 40);
    insertAtEnd1(&head, 50);
    printList(head);  // 预期: [10] -> [20] -> [30] -> [40] -> [50] -> NULL
    
    printf("\n===== 测试指定位置插入 =====\n");
    insertAtPosition1(&head, 25, 2);  // 在位置 2 插入 25
    printList(head);  // 预期: [10] -> [20] -> [25] -> [30] -> [40] -> [50] -> NULL
    
    printf("\n===== 测试搜索 =====\n");
    int pos = search(head, 30);
    if (pos != -1)
        printf("找到 30，位置: %d\n", pos);  // 预期: 位置 3
    else
        printf("未找到 30\n");
    
    pos = search(head, 99);
    if (pos != -1)
        printf("找到 99，位置: %d\n", pos);
    else
        printf("未找到 99\n");  // 预期: 未找到
    
    printf("\n===== 测试删除 =====\n");
    printf("链表长度: %d\n", getLength(head));  // 预期: 6
    deletValue1(&head, 25);
    printList(head);  // 预期: [10] -> [20] -> [30] -> [40] -> [50] -> NULL
    
    deletValue1(&head, 10);  // 删除头节点
    printList(head);  // 预期: [20] -> [30] -> [40] -> [50] -> NULL
    
    deletValue1 (&head, 10);  // 删除尾节点
    printList(head);  // 预期: [20] -> [30] -> [40] -> NULL
    
    printf("链表长度: %d\n", getLength(head));  // 预期: 3
    
    printf("\n===== 释放链表 =====\n");
    freeList(&head);
    printList(head);  // 预期: 链表为空: NULL
} 

void test_reverse ()
{
    Node *head=NULL;
    printf ("初始化链表： ");
    printList (head);
    reverseList (&head);
    printf ("反转： ");
    printList (head);
    reverseList (&head);
    printf ("再反转： ");
    printList (head);
}