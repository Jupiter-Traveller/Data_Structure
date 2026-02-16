#define MAX_SIZE 6
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;   
} ArrayQueue;

void initQueue (ArrayQueue *q);
int isEmpty (ArrayQueue *q);
int isFull (ArrayQueue *q);
int getSize (ArrayQueue *q);
void enqueue (ArrayQueue *q, int data);
int dequeue (ArrayQueue *q);
int front (ArrayQueue *q);
void printQueue (ArrayQueue *q);