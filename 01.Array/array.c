#include "array.h"
#include <stdio.h>
#include <stdlib.h>
//!!!Static Array Operations!!!

//print all the elemtns and information about the array
void printArray (int arr[], int n)
{
    printf ("Static Array size: %d ", n);
    printf ("[");
    for (int i=0; i<n; i++){
        printf ("%d", arr[i]);
        if (i!=n-1) printf (",");
    }
    printf ("]\n");
}

//search a number in a array and return its index
//if this number don't exsit in the arry, then return -1
//last version:
// int linearSearch (int arr[], int n, int target)
// {
//     int sign=0, i;
//     for (i=0; i<n; i++){
//         if (arr[i]==target){
//             sign=1;
//             break;
//         }
//     }
//     if (sign) return i;
//     else return -1;
// }

//improve version:
int linearSearch (int arr[], int n, int target)
{
    for (int i=0; i<n; i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}

//insert a number at the end of array
void insertAtEnd(int arr[], int *n, int value, int capacity)
{
    if (*n>=capacity) {
        printf ("Can't insert at the end because the capacity is full!\n");
        return ;
    }
    arr[*n]=value;
    (*n)++;
}

//insert a number on the index of array
void insertAtIndex (int arr[], int *n, int index, int value, int capacity)
{
    if (index<0 || index>*n) {
        printf ("Can't insert because index is invalid!\n");
        return ;
    }
    if (*n>=capacity){
        printf ("Can't inset because capacity is full!\n");
        return ;
    }
    (*n)++;
    for (int i=*n-1; i>index; i--){
        arr[i]=arr[i-1];
    }
    arr[index]=value;
}

//delet a element on the index of array 
void deleteAtIndex(int arr[], int *n, int index)
{
    if (index<0 || index>=*n){
        printf ("Can't delet because index is invalid!\n");
        return ;
    }
    for (int i=index; i<*n-1; i++){
        arr[i]=arr[i+1];
    }
    (*n)--;
}

//reverse all the elements in an array
void reverseArray (int arr[], int n)
{
    int left=0, right=n-1, temp;
    while (left<right){
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
}

//find the max element in an array
int findMax (int arr[], int n)
{
    int max=arr[0];
    for (int i=0; i<n; i++){
        if (arr[i]>max) max=arr[i];
    }
    return max;
}

//find the min element in an array
int findMin (int arr[], int n)
{
    int min=arr[0];
    for (int i=0; i<n; i++){
        if (arr[i]<min) min=arr[i];
    }
    return min;
}



// !!!Dynamic Array Operations!!!

//Define a Dynamic Arryay

// typedef struct {
//     int *data;
//     int size;
//     int capacity;
// } DynamicArray;

//create a dynamic array with no element
DynamicArray *createDynamicArray (int capacity)
{
    DynamicArray *arr=(DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr==NULL){
        printf ("error");
        return NULL;
    }
    arr->data=(int *)malloc(sizeof(int)*capacity);
    if (arr->data==NULL){
        printf ("error");
        return NULL;
    }
    arr->size=0;
    arr->capacity=capacity;
    return arr;
}

//resize the capacity of a dynamic array
void resize (DynamicArray *arr, int new_capacity)
{
    int *new_data=(int *)malloc(sizeof(int)*new_capacity);
    if (new_data==NULL) {
        printf ("resize fail!\n");
        return ;
    }
    for (int i=0; i<arr->size; i++) {
        new_data[i]=arr->data[i];
    }
    free (arr->data);
    arr->capacity=new_capacity;
    arr->data=new_data;
}

//append  a number at the end of a dynamica array
void append (DynamicArray *arr, int value)
{
    if (arr->size>=arr->capacity) {
        resize (arr, 2*arr->capacity);
    }
    arr->data[arr->size]=value;
    (arr->size)++;
}

//return 1 indicate get successfully and return 0 indicate failure
//return value by pointer argument
int get(DynamicArray *arr, int index, int *value)
{
    if (index<0 || index>=arr->size){
        printf ("Can't get the element because index is invalid!\n");
        return 0;
    }
    *value=arr->data[index];
    return 1;
}

//set a number to an dynamic array by index 
void set(DynamicArray *arr, int index, int value)
{
    if (index<0 || index>=arr->size){
        printf ("Can't set this value because index is invalid!\n");
        return ;
    }
    arr->data[index]=value;
}

//print the elements and informations about a dymanic array
void printDynamicArray(DynamicArray *arr)
{
    printf ("Dynamic Array size: %d capacity: %d", arr->size, arr->capacity);
    printf ("[");
    for (int i=0; i<arr->size; i++){
        printf ("%d", arr->data[i]);
        if (i!=arr->size-1) printf (",");
    }
    printf ("]");
}

//free the memory which held the dynamic array
void destroyDynamicArray(DynamicArray *arr)
{
    free (arr->data);
    free (arr);
}



