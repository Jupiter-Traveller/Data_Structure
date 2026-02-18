#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void printArray (int arr[], int size)
{
    printf ("ouput: ");
    for (int i = 0; i < size; i ++) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort (int arr[], int n)
{
    for (int i = 0; i < n - 1; i ++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j ++) {
            if (arr[j] > arr[j+1]) {
                swapped = 1;
                swap (&arr[j], &arr[j+1]);
            }
        }
        if (swapped == 0) return ;
    }
}

void selectionSort (int arr[], int n)
{
    for (int i = 0; i < n - 1; i ++) {
        int min = i;
        for (int j = i + 1; j < n; j ++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap (&arr[min], &arr[i]);
    }
}
void insertionSort (int arr[], int n)
{
    for (int i = 1; i < n; i ++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }
}

int isEven (int n)
{
    return n % 2 == 0;
}

void segregateOddEven (int arr[], int n)
{
    for (int i = 0; i < n - 1; i ++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j ++) {
            if (isEven (arr[j]) && !isEven (arr[j+1])) {
                swapped = 1;
                swap (&arr[j], &arr[j+1]);
            }
        }
        if (swapped == 0) return ;
    }
}

void sortStudents (Student arr[], int n)
{
    for (int i = 1; i < n; i ++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && key.score > arr[j].score) {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }
}

void printStudent (Student arr[], int n)
{
    printf ("output:\n");
    for (int i = 0; i < n; i ++) {
        printf ("id: %d score: %lf\n", arr[i].id, arr[i].score);
    }
}

void mergeSort (int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        //printf("Splitting: %d to %d\n", l, r);
        mergeSort (arr, l, m);
        mergeSort (arr, m + 1, r);
        
        merge (arr, l, m, r);
    }
}

void merge (int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *) malloc (n1 * sizeof (int));
    int *R = (int *) malloc (n2 * sizeof (int));

    for (i = 0; i < n1; i ++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j ++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i ++;
        }
        else {
            arr[k] = R[j];
            j ++;
        }
        k ++;
    }

    while (i < n1) {
        arr[k] = L[i];
        k ++;
        i ++;
    }
    while (j < n2) {
        arr[k] = R[j];
        k ++;
        j ++;
    }

    free (R);
    free (L);
}

void mergeArrays(int a[], int n, int b[], int m, int result[])
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            result[k] = a[i];
            i ++;
        }
        else {
            result[k] = b[j];
            j ++;
        }
        k ++;
    }
    while (i < n) {
        result[k] = a[i];
        i ++;
        k ++;
    }
    while (j < m) {
        result[k] = b[j];
        j ++;
        k ++;
    }
}

void quickSort (int arr[], int low, int high)
{
    if (low < high) {
        int location = partition (arr, low , high);
        //printArray (arr, high - low + 1);
        quickSort (arr, low, location - 1);
        quickSort (arr, location + 1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j ++) {
        if (arr[j] > pivot) {
            i ++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i+1], &arr[high]);
    //printArray (arr, high - low + 1);
    return i + 1;
}

void hybridSort (int arr[], int low, int high)
{
    if (low < high) {
        if (high - low + 1 < 10) {
            insertionSort (&arr[low], high - low + 1);
        }
        else {
            int location = partition (arr, low, high);
            hybridSort (arr, low, location - 1);
            hybridSort (arr, location + 1, high);
        }
    }
}