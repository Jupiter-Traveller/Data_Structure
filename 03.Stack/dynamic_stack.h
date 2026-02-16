typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} LinkedStack;

void Dynamic_initStack (LinkedStack *s);
int Dynamic_isEmpty (LinkedStack *s);
void Dynamic_push (LinkedStack *s, int data);
int Dynamic_pop (LinkedStack *s);
int Dynamic_peek (LinkedStack *s);
void Dynamic_printStack (LinkedStack *s);
void freeStack (LinkedStack *s);