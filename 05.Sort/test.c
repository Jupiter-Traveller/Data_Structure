#include <stdio.h>
#include "sort.h"

void test ()
{
    int data1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(data1) / sizeof(data1[0]);

    int data2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(data2) / sizeof(data2[0]);
    
    int data3[] = {64, 34, 25, 12, 22, 11, 90};
    int n3 = sizeof(data3) / sizeof(data3[0]);

    int data4[] = {64, 34, 25, 12, 22, 11, 90};
    int n4 = sizeof(data4) / sizeof(data4[0]);

    int data5[] = {64, 34, 25, 12, 22, 11, 90};
    int n5 = sizeof(data5) / sizeof(data5[0]);

    int data6[] = {64, 34, 25, 12, 22, 11, 90};
    int n6 = sizeof(data6) / sizeof(data6[0]);

    printf("原始数组: \n");
    printArray(data1, n1);

    printf("\n--- 冒泡排序 ---\n");
    bubbleSort(data1, n1);
    printArray(data1, n1);

    printf("\n--- 选择排序 ---\n");
    selectionSort(data2, n2);
    printArray(data2, n2);

    printf("\n--- 插入排序 ---\n");
    insertionSort(data3, n3);
    printArray(data3, n3);

    printf("\n--- 归并排序 ---\n");
    mergeSort(data4, 0, n4 - 1);    
    printArray(data4, n4);

    printf("\n--- 快速排序 ---\n");
    quickSort (data5, 0, n5 - 1);    
    printArray(data5, n5);

    printf("\n--- 混合排序 ---\n");
    quickSort (data6, 0, n6 - 1);    
    printArray(data6, n6);
}

void test_even ()
{
    int data1[] = {12, 34, 45, 9, 8, 90, 3};
    int n1 = sizeof (data1) / sizeof (data1[0]);
    int data2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof (data2) / sizeof (data2[0]);

    printf("原始数组: \n");
    printArray(data1, n1);

    printf("\n--- 排序后 ---\n");
    segregateOddEven (data1, n1);
    printArray (data1, n1);

    printf("原始数组: \n");
    printArray(data2, n2);

    printf("\n--- 排序后 ---\n");
    segregateOddEven (data2, n2);
    printArray (data2, n2);
    
}

void test_student ()
{
    int n = 5;
    Student arr[5];
    for (int i = 0; i < n; i ++) {
        printf ("Please enter id: ");
        scanf ("%d", &(arr[i].id));
        printf ("Please enter score: ");
        scanf ("%f", &(arr[i].score));
    }
    sortStudents (arr, n);
    printStudent (arr, n);
}