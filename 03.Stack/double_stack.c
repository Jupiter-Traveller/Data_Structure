#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"
#include "double_stack.h"

MyQueue *myQueueCreate ()
{
    MyQueue *obj = (MyQueue *) malloc (sizeof (MyQueue));
    initStack (&(obj->inputStack));
    initStack (&(obj->outputStack));
    return obj;
}

void myQueueEnqueue (MyQueue *obj, int data)
{
    if (isFull (&(obj->inputStack))) {
        printf ("This queue is full. Can't enqueue!\n");
        return ;
    }
    push (&(obj->inputStack), data);
}

int myQueueDequeue (MyQueue *obj)
{
    if (isEmpty (&(obj->outputStack))) {
        move (obj);
    }
    int data = pop1 (&(obj->outputStack));
    move_over (obj);
    return data;
}

void move (MyQueue *obj)
{
    if (isEmpty (&(obj->outputStack))) {
        while (!isEmpty (&(obj->inputStack))) {
            int data = pop1 (&(obj->inputStack));
            push (&(obj->outputStack), data);
        }
    }
}

void move_over (MyQueue *obj)
{
    while (!isEmpty (&(obj->outputStack))) {
        int data = pop1 (&(obj->outputStack));
        push (&(obj->inputStack), data);
    }
}

void printMyQueue (MyQueue *obj)
{
    if (isEmpty (&(obj->outputStack))) {
        move (obj);
    }
    printStack (&(obj->outputStack));
    move_over (obj);
}

void freeMyQueue (MyQueue *obj)
{
    free (obj);
}