typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef struct {
    Node *front;
    Node *rear;
    int size;
} LinkedQueue;

void initQueue (LinkedQueue *q);
int isEmpty (LinkedQueue *q);
void enqueue (LinkedQueue *q, int data);
int dequeue (LinkedQueue *q);
int front (LinkedQueue *q);
void printQueue (LinkedQueue *q);
void freeQueue (LinkedQueue *q);

void JosephRing (int n, int k);
