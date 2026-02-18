#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "browser_history.h"

Node *current_page = NULL;

void visit (int url)
{
    if (current_page == NULL) {
        current_page = createNode (url);
        return ;
    }
    Node *temp;
    Node *current = current_page->next;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free (temp);
    }
    current = createNode (url);
    current->next = NULL;
    current->prev = current_page;
    current_page->next = current;
    current_page = current;
}

void back (int steps)
{
    while (steps > 0 && current_page->prev != NULL) {
        current_page = current_page->prev;

        steps --;
    }
}
void forward (int steps)
{
    while (steps >0 && current_page->next != NULL) {
        current_page = current_page->next;
        steps --;
    }
}