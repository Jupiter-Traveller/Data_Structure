#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

//!!!
//This library implement static stack using static array
//!!!

//initialize stack
void initStack (ArrayStack *s)
{
    s->top = -1; //indeicate empty stack
}

//judge whether a stack is full
int isFull (ArrayStack *s)
{
    return s->top == 100 - 1;
}

//judge whether a stack is empty
int isEmpty (ArrayStack *s)
{
    return s->top == -1;
}

//push a value into stack
void push (ArrayStack *s, int data)
{
    if (isFull (s)) {
        printf ("This stack is full! Can't push!\n");
        return; 
    }
    s->top ++;
    s->data[s->top] = data;
}

//pop a value form stack
int pop1 (ArrayStack *s)
{
    if (isEmpty (s)) {
        printf ("This stack is empty! Can't pop!\n");
        return -1;
    }
    s->top --;
    return s->data[s->top + 1];
}

//return 0 if stack is empty, otherwise return 1
//return peek value by pointer argument
int pop2 (ArrayStack *s, int *value)
{
    if (isEmpty (s)) {
        printf ("This stack is empty! Can't pop!\n");
        return 0;
    }
    s->top --;
    *value = s->data[s->top + 1];
    return 1;
}

//return the peek value of a stack
int peek1 (ArrayStack *s)
{
    if (isEmpty (s)) {
        printf ("This is a empty stack! Can't check the peek!\n");
        return -1;
    }
    return s->data[s->top];
}

//return 0 if stack is empty, otherwise reutrn 1
//return peek value by pointer argument
int peek2 (ArrayStack *s, int *value)
{
    if (isEmpty (s)) {
        printf ("This is a empty stack! Can't check the peek!\n");
        return 0;
    }
    *value = s->data[s->top];
    return 1;
}

//print all the elements in the stack from top to bottom
void printStack (ArrayStack *s)
{
    if (isEmpty (s)) {
        printf ("This is a empty stack!\n");
        return ;
    }
    printf ("top -> ");
    for (int i = s->top; i >= 0; i --) {
        printf ("[%d] ", s->data[i]);
    }
    printf ("<- bottom\n");
}

//The following two functions are exercise
int isBalanced(char *str)
{
    // ( == 1
    // [ == 2
    // { == 3
    ArrayStack s;
    initStack (&s);
    while (*str) {
        if (*str == '(') push (&s, 1);
        if (*str == '[') push (&s, 2);
        if (*str == '{') push (&s, 3);
        if (*str == ')') {
            if (isEmpty (&s) || pop1 (&s) != 1) {
                return 0;
            }
        }
        if (*str == ']') {
            if (isEmpty (&s) || pop1 (&s) != 2) {
                return 0;
            }
        }
        if (*str == '}') {
            if (isEmpty (&s) || pop1 (&s) != 3) {
                return 0;
            }
        }
        str ++;
    }
    return isEmpty (&s);
}

void convert (int n)
{
    ArrayStack s;
    initStack (&s);
    while (n != 0) {
        push (&s, n % 2);
        n /= 2;
    }
    printStack (&s);
}


