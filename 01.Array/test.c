#include "array.h"
#include <stdio.h>
#include "test.h"

void testStaticArray() {
    printf("===== 静态数组测试 =====\n\n");
    
    int arr[10] = {1, 3, 5, 7, 9};
    int n = 5;
    
    printf("初始数组:\n");
    printArray(arr, n);
    
    printf("\n测试查找:\n");
    printf("查找5: 索引 = %d\n", linearSearch(arr, n, 5));
    printf("查找10: 索引 = %d\n", linearSearch(arr, n, 10));
    
    printf("\n测试末尾插入:\n");
    insertAtEnd(arr, &n, 11, 10);
    printArray(arr, n);
    
    printf("\n测试指定位置插入:\n");
    insertAtIndex(arr, &n, 2, 99, 10);
    printArray(arr, n);
    
    printf("\n测试删除:\n");
    deleteAtIndex(arr, &n, 2);
    printArray(arr, n);
    
    printf("\n测试反转:\n");
    reverseArray(arr, n);
    printArray(arr, n);
    
    printf("\n测试最值:\n");
    printf("最大值: %d\n", findMax(arr, n));
    printf("最小值: %d\n", findMin(arr, n));
    
    printf("\n测试边界情况:\n");
    printf("尝试越界插入:\n");
    insertAtIndex(arr, &n, 20, 100, 10);
    printf("尝试在满数组插入:\n");
    for (int i = n; i < 10; i++) {
        insertAtEnd(arr, &n, i * 10, 10);
    }
    printArray(arr, n);
    insertAtEnd(arr, &n, 999, 10);  // 应该失败
}

void testDynamicArray() {
    printf("\n\n===== 动态数组测试 =====\n\n");
    
    DynamicArray *arr = createDynamicArray(2);
    printf("创建空数组:\n");
    printDynamicArray(arr);
    printf("\n");
    
    printf("\n测试追加和自动扩容:\n");
    for (int i = 1; i <= 10; i++) {
        printf("追加 %d: ", i * 10);
        append(arr, i * 10);
        printDynamicArray(arr);
        printf("\n");
    }
    
    printf("\n测试获取元素:\n");
    int value;
    if (get(arr, 5, &value)) {
        printf("索引5的值: %d\n", value);
    }
    if (!get(arr, 100, &value)) {
        printf("索引100越界（预期行为）\n");
    }
    
    printf("\n测试设置元素:\n");
    set(arr, 5, 999);
    printf("设置索引5为999: ");
    printDynamicArray(arr);
    printf("\n");
    
    printf("\n销毁数组\n");
    destroyDynamicArray(arr);
}