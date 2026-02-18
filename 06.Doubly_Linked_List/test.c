#include <stdio.h>
#include "doubly_linked_list.h"
#include "test.h"
#include "browser_history.h"

void test ()
{
    Node* head = NULL;

    append(&head, 10); // List: 10
    push(&head, 20);   // List: 20 <-> 10
    push(&head, 30);   // List: 30 <-> 20 <-> 10
    append(&head, 40); // List: 30 <-> 20 <-> 10 <-> 40

    printf("原始链表:\n");
    printList(head);

    // 测试删除
    // 假设我们要删除 head->next (即 20)
    printf("\n删除第二个节点 (20) 后:\n");
    deleteNode(&head, head->next); 
    printList(head);
}

void test_sort ()
{
    Node *head = NULL;
    append (&head, 20);
    append (&head, 30);
    append (&head, 40);
    append (&head, 60);
    append (&head, 70);
    printList (head);

    Node *new1, *new2, *new3;
    new1 = createNode (10);
    new2 = createNode (50);
    new3 = createNode (80);


    sortedInsert (&head, new3);
    printList (head);

    sortedInsert (&head, new1);
    printList (head);

    sortedInsert (&head, new2);
    printList (head);
}

extern Node *current_page;

void test_brewser ()
{
    char ch;
    int steps;
    do {
        printf ("Enter a to visit a website\n");
        printf ("Enter f to forward\n");
        printf ("Enter b to back\n");
        printf ("Enter q to quit!\n");
        ch = getchar ();
        if (ch == 'a') {
            printf ("Please enter a url: ");
            scanf ("%d", &steps);
            visit (steps);
            printf ("This is the website: %d\n", current_page->data);
            getchar ();
        }
        if (ch == 'f') {
            printf ("Please enter a step: ");
            scanf ("%d", &steps);
            forward (steps);
            printf ("This is the website: %d\n", current_page->data);
            getchar ();
        }
        if (ch == 'b') {
            printf ("Please enter a step: ");
            scanf ("%d", &steps);
            back (steps);
            printf ("This is the website: %d\n", current_page->data);
            getchar ();
        }
        
    } while (ch != 'q');
    printf ("Close!!!\n");
}