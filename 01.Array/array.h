// Static Array Operations
void printArray (int arr[], int n);
int linearSearch (int arr[], int n, int target);
void insertAtEnd(int arr[], int *n, int value, int capacity);
void insertAtIndex (int arr[], int *n, int index, int value, int capacity);
void deleteAtIndex(int arr[], int *n, int index);
void reverseArray (int arr[], int n);
int findMax (int arr[], int n);
int findMin (int arr[], int n);
// Dynamic Array Operations
typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray (int capacity);
void resize (DynamicArray *arr, int new_capacity);
void append (DynamicArray *arr, int value);
int get(DynamicArray *arr, int index, int *value);
void set(DynamicArray *arr, int index, int value);
void printDynamicArray(DynamicArray *arr);
void destroyDynamicArray(DynamicArray *arr);



