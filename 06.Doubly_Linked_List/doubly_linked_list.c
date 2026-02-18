#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

Node *createNode (int data)
{
    Node *new_node = (Node *) malloc (sizeof (Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void push (Node **head, int data)
{
    Node *new_node = createNode (data);
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void append (Node **head, int data)
{
    Node *new_node = createNode (data);
    Node *current = *head;
    if (*head == NULL) {
        *head = new_node;
        return ;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void deleteNode (Node** head, Node* del)
{
    if (*head == NULL || del == NULL) {
        return ;
    }
    if (del == *head) {
        *head = (*head)->next;
    }
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    free (del);
}

void printList(Node* node)
{
    Node *last;
    if (node == NULL) {
        printf ("This is a empty linked list!\n");
        return ;
    }
    printf ("正向输出： head -> ");
    while (node != NULL) {
        printf ("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    printf ("tail\n");
    printf ("反向输出： tail -> ");
    while (last != NULL) {
        printf ("%d -> ", last->data);
        last = last->prev;
    }
    printf ("head\n");
}

void sortedInsert(Node** head, Node* new_node)
{
    Node *current = *head;
    Node *node;
    if (*head == NULL) {
        *head = new_node;
        return ;
    }
    while (current != NULL && current->data < new_node->data) {
        node = current;
        current = current->next;
    }

    if (current == NULL) {
        node->next = new_node;
        new_node->prev = node;
    }
    else if (current->prev == NULL) {
        current->prev = new_node;
        new_node->next = current;
        *head = new_node;
    }
    else {
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev = new_node;
        new_node->prev->next = new_node;
    }
}
