typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode (int data);
void insertAtHead1 (Node **head, int data);
Node *insertAtHead2 (Node *head, int data);
void insertAtEnd1 (Node **head, int data);
Node *insertAtEnd2 (Node *head, int data);
void insertAtPosition1 (Node **head, int data, int position);
Node *insertAtPosition2 (Node *head, int data, int position);
void deletValue1 (Node **head, int value);
Node *deletValue2 (Node *head, int value);
int search (Node *head, int data);
int getLength (Node *head);
void printList (Node *head);
void freeList (Node **head);
void reverseList (Node **head);
