#include "static_stack.h"

typedef struct {
    ArrayStack inputStack;
    ArrayStack outputStack;
} MyQueue;

MyQueue *myQueueCreate ();
void myQueueEnqueue (MyQueue *obj, int data);
int myQueueDequeue (MyQueue *obj);
void move (MyQueue *obj);
void printMyQueue (MyQueue *obj);
void freeMyQueue (MyQueue *obj);
void move_over (MyQueue *obj);
