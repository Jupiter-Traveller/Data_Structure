#include "dynamic_stack.h"
#include <stdio.h>
#include <stdlib.h>

//!!!
//This library implement dynamic stack using linked list
//!!!

//initialize the stack
void Dynamic_initStack (LinkedStack *s)
{
    s->size = 0;
    s->top = NULL;
}

//judeg whether stack is empty
int Dynamic_isEmpty (LinkedStack *s)
{
    return s->top == NULL;
}

//push a value into the stack
void Dynamic_push (LinkedStack *s, int data)
{
    Node *new_node = (Node *)malloc (sizeof (Node));
    if (new_node == NULL) {
        printf ("Run out of memory! Can't push!\n");
        return ;
    }
    new_node->data = data;
    new_node->next = s->top;
    s->size ++;
    s->top = new_node;
}

//pop a value from the stack
int Dynamic_pop (LinkedStack *s)
{
    if (Dynamic_isEmpty (s)) {
        printf ("This is a empty stack! Can't pop!\n");
        return -1;//error
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free (temp);
    s->size --;
    return value;
}

//return a peak value of a stack
int Dynamic_peek (LinkedStack *s)
{
    if (Dynamic_isEmpty (s)) {
        printf ("This is a empty stack! Can't check the peek!\n");
        return -1;//error
    }
    return s->top->data;
}

//print all the elements in the stack from top to bottom
void Dynamic_printStack (LinkedStack *s)
{
    if (Dynamic_isEmpty (s)) {
        printf ("This is a empty stack!\n");
        return ;
    }
    printf ("top -> ");
    Node *temp = s->top;
    while (temp != NULL) {
        printf ("[%d] ", temp->data);
        temp = temp->next;
    }
    printf ("<- bottom\n");
}

//free the memeory which held the stack
void freeStack (LinkedStack *s)
{
    while (!Dynamic_isEmpty (s)) {
        Dynamic_pop (s);
    }

}