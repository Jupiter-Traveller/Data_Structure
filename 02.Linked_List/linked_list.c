#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//creater a new node with specific data
Node *createNode (int data)
{
    Node *new_node=(Node *) malloc (sizeof(Node));
    if (new_node==NULL) {
        printf ("Memory Allocation Fail!\n");
        return NULL;
    }
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

//insert a new node at the head
//pass a pointer to the head pointer
void insertAtHead1 (Node **head, int data)
{
    Node *new_node=createNode (data);
    new_node->next=*head;
    *head=new_node;
}

//insert a new node at head
//pass head pointer and return new head pointer
Node *insertAtHead2 (Node *head, int data)
{
    Node *new_node=createNode (data);
    new_node->next=head;
    return new_node;
}

//insert a new node at the end
//pass a pointer to the head pointer
void insertAtEnd1 (Node **head, int data)
{
    Node *new_node=createNode (data);
    if (*head==NULL) {
        *head=new_node;
        return ;
    }
    Node *current=*head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=new_node;
}

//insert a new node at the end
//pass head pointer and return new head pointer
Node *insertAtEnd2 (Node *head, int data)
{
    Node *new_node=createNode (data);
    if (head==NULL) {
        head=new_node;
        return head;
    }
    Node *current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=new_node;
    return head;
}

//insert a new node at specified location by index
//pass a pointer to head pointer
void insertAtPosition1 (Node **head, int data, int position) {
    if (position==0) {
        insertAtHead1 (head, data);
    }
    Node *current=*head;
    for (int i=0; i<position-1; i++) {
        if (current==NULL) {
            printf ("%d location exceeds the length of linked list!\n", position);
            return ;
        }
        current=current->next;
    }
    if (current==NULL) {
        printf ("%d location exceed the length of linked list!\n", position);
        return ;
    }
    Node *new_node=(Node *) malloc (sizeof(Node));
    new_node->next=current->next;
    current->next=new_node;
}

//insert a new node at specified location by index
//pass head pointer and return new head pointer
Node *insertAtPosition2 (Node *head, int data, int position)
{
    if (position==0) {
        insertAtHead1 (&head, data);
        return head;
    }
    Node *current=head;
    for (int i=0; i<position-1; i++) {
        if (current==NULL) {
        printf ("%d location exceed the length of linked list!\n", position);
        return head;
        }
        current=current->next;
    }
    if (current==NULL) {
        printf ("%d location exceed the length of linked list!\n", position);
        return head;
    }
    Node *new_node=(Node *) malloc (sizeof(Node));
    new_node->next=current->next;
    current->next=new_node;
    return head;
}

//delet specified node by value
//pass pointer to head pointer
void deletValue1 (Node **head, int value)
{
    if (*head==NULL) {
        printf ("This is a null linked list , can't delet");
        return ;
    }
    if ((*head)->data==value) {
        Node *temp=*head;
        *head=(*head)->next;
        free (temp);
        return ;
    }
    Node *current=*head;
    while (current->next!=NULL && current->next->data!=value) {
        current=current->next;
    }
    if (current->next==NULL) {
        printf ("The value %d don't exsit in the linked list!\n", value);
        return ;
    }
    Node *temp=current->next;
    current->next=temp->next;
    free (temp);
}

//delet specified node by value
//pass head pointer and return new head pointer
Node *deletValue2 (Node *head, int value)
{
    if (head==NULL) {
        printf ("This is a null linked list , can't delet");
        return head;
    }
    if (head->data==value) {
        Node *temp=head;
        head=head->next;
        free (temp);
        return head;
    }
    Node *current=head;
    while (current->next!=NULL && current->next->data!=value) {
        current=current->next;
    }
    if (current->next==NULL) {
        printf ("The value %d don't exsit in the linked list!\n", value);
        return head;
    }
    Node *temp=current->next;
    current=temp->next;
    free (temp);
    return head;
}

//search node by value and return its loaction
//if not found then return -1
int search (Node *head, int data)
{
    int location=0;
    while (head!=NULL) {
        if (head->data==data) {
            return location;
        }
        head=head->next;
        location++;
    }
    return -1;
}

//get the length of a linked list
int getLength (Node *head)
{
    int count=0;
    while (head!=NULL) {
        count++;
        head=head->next;
    }
    return count;
}

//print all the node data of a linked list
void printList (Node *head)
{
    if (head==NULL) {
        printf ("This is a null linked list!\n");
        return ;
    }
    while (head!=NULL) {
        printf ("[%d]->", head->data);
        head=head->next;
    }
    printf ("NULL");
}

//free all the memory which held the linked list
void freeList (Node **head)
{
    Node *current=*head, *temp;
    while (current!=NULL) {
        temp=current;
        current=temp->next;
        free (temp);
    }
}

//reverse a linked list
void reverseList (Node **head)
{
    Node *prev, *current, *next;
    prev=current=next=NULL;
    if (*head==NULL || (*head)->next==NULL) {
        return ;
    }
    current=*head;
    next=current->next;
    while (next!=NULL) {
        current->next=prev;
        prev=current;
        current=next;
        next=current->next;
    }
    current->next=prev;
    *head=current;
}

