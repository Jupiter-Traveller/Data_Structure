#include <stdio.h>
#include <stdlib.h>
#include "static.queue.h"

//!!!
//This is a library which implements queue operations using array
//!!!

//initialize a queue
void initQueue (ArrayQueue *q)
{
    q->front = 0;
    q->rear = 0;
}

//judge whether a queue is empty
//if this queue is empty then return 1, otherwise return 0
int isEmpty (ArrayQueue *q)
{
    return q->front == q->rear;
}

//judge whether a queue is full
//if this queue is full then return 1, otherwise return 0
int isFull (ArrayQueue *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}

//get a queue's size
int getSize (ArrayQueue *q)
{
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

//
void enqueue (ArrayQueue *q, int data)
{
    if (isFull (q)) {
        printf ("This queue is full! Can't enqueue!\n");
        return ;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

//
int dequeue (ArrayQueue *q)
{
    if (isEmpty (q)) {
        printf ("This queue is empty! Can't dequeue!\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return value;
}

int front (ArrayQueue *q)
{
    if (isEmpty (q)) {
        printf ("This queue is empty! Can't display front!\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue (ArrayQueue *q)
{
    if (isEmpty (q)) {
        printf ("This queue is empty!\n");
        return ;
    }
    printf ("front -> ");
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf ("[%d] ", q->data[i]);
    }
    printf ("<- rear\n");
}