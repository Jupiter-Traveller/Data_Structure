#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} ArrayStack;

void initStack (ArrayStack *s);
int isFull (ArrayStack *s);
int isEmpty (ArrayStack *s);
void push (ArrayStack *s, int data);
int pop1 (ArrayStack *s);
int pop2 (ArrayStack *s, int *value);
int peek1 (ArrayStack *s);
int peek2 (ArrayStack *s, int *value);
void printStack (ArrayStack *s);

int isBalanced(char *str);
void convert (int n);