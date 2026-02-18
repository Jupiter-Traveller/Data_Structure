void printArray (int arr[], int size);
void swap (int *a, int *b);

void bubbleSort (int arr[], int n);
void selectionSort (int arr[], int n);
void insertionSort (int arr[], int n);

int isEven (int n);
void segregateOddEven (int arr[], int n);

typedef struct {
    int id;
    float score;
} Student;

void sortStudents (Student arr[], int n);
void printStudent (Student arr[], int n);

void mergeSort (int arr[], int l, int r);
void merge (int arr[], int l, int m, int r);
void mergeArrays(int a[], int n, int b[], int m, int result[]);

void quickSort (int arr[], int low, int high);
int partition (int arr[], int low, int high);
void hybridSort (int arr[], int low, int high);