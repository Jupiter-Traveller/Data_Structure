typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode (int data);
void push (Node **head, int data);
void append (Node **head, int data);
void deleteNode (Node** head, Node* del);
void printList(Node* node);

void sortedInsert(Node** head, Node* new_node);