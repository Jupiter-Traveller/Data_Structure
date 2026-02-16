//!!!
//This is a library which contains queue opeartions using linked list
//!!!
#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"

//initialize a queue
void initQueue (LinkedQueue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

//judge whether a quque is empty
int isEmpty (LinkedQueue *q)
{
    return q->front == NULL;
}

//
void enqueue (LinkedQueue *q, int data)
{
    Node *new_node = (Node *)malloc (sizeof (Node));
    if (new_node == NULL) {
        printf ("Run out of memory! Can't enqueue!\n");
        return ;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (isEmpty (q)) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size ++;
}

//
int dequeue (LinkedQueue *q)
{
    if (isEmpty (q)) {
        printf ("This queue is empty! Can't dequeue!\n");
        return -1;
    }
    int value = q->front->data;
    Node *temp = q->front;
    q->front = temp ->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free (temp);
    q->size --;
    return value;
}

int front (LinkedQueue *q)
{
    if (isEmpty (q)) {
        printf ("This queue is empty! Can't display front!\n");
        return -1;
    }
    return q->front->data;
}

void printQueue (LinkedQueue *q)
{
    if (isEmpty (q)) {
        printf ("This is a empty queue!\n");
        return ;
    }
    printf ("front -> ");
    Node *current = q->front;
    while (current != NULL) {
        printf ("[%d] ", current->data);
        current = current->next;
    }
    printf ("<- rear\n");
}

void freeQueue (LinkedQueue *q)
{
    while (!isEmpty (q)) {
        dequeue (q);
    }
}

//

void JosephRing (int n, int k)
{
    LinkedQueue q;
    initQueue (&q);
    for (int i = 1; i <= n; i ++) {
        enqueue (&q, i);
    }
    printf ("Order: ");
    int i = 1;
    int order;
    while (!isEmpty (&q)) {
        order = dequeue (&q);
        if (i == 0) {
            printf ("%d, ", order);
        }
        else {
            enqueue (&q, order);
        }
        i = (i + 1) % k;
    }
}