//
//  main.c
//  BFBaseAlgorithm_C
//
//  Created by BFAlex on 2018/4/2.
//  Copyright © 2018年 BFAlex. All rights reserved.
//

#include <stdio.h>


#pragma mark - Sorting
#pragma mark Quick Sort

void printNumArray(int num[], int length) {
    
    printf("当前数组【");
    for (int i = 0; i < length; i++) {
        printf("%d, ", num[i]);
    }
    printf("】\n");
}

/**
 快速排序(升序)
 */
void bf_quickSort(int num[], int left, int right) {
    
    if (left >= right) { return; }
    
    int lx = left, ry = right;
    int temp = num[lx];
    
    while (lx < ry) {
        
        // 从右到左查询第一个比temp小的数，且索引不能小于temp对应的索引
        while (lx < ry && num[ry] >= temp) {
            ry--;
        }
        if (lx < ry) {
            num[lx] = num[ry];
        }
        
        // 从左到右查询一个比temp大的数，且索引号不能大于ry
        while (lx < ry && num[lx] <= temp) {
            lx++;
        }
        if (lx < ry) {
            num[ry] = num[lx];
        }
        
        num[lx] = temp;
        // 采用递归方法对lx两边数据分别排序
        bf_quickSort(num, left, lx-1);
        bf_quickSort(num, lx+1, right);
    }
}

/**
 冒泡排序(升序)
 */
void bf_BubbleSort(int num[], int num_length) {
    
    for (int i = 0; i < num_length; i++) {
        for (int j = i + 1; j < num_length; j++) {
            if (num[i] > num[j]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}

/**
 阶乘
 */
int bf_Factorial(int num) {
    
    if (num == 1 || num == 0) {
        return 1;
    }
    
    return num * bf_Factorial(num - 1);
}

/**
 最大公约数
 */
int bf_GreatestCommonDivisor(int a, int b) {
    
    int temp = 0;
    
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

/**
 二分查找
 */
int bf_BinarySearch(int* num, int num_length, int goal_num) {
    
    int leftIndex = 0;
    int rightIndex = num_length - 1;
    while (leftIndex <= rightIndex) {
        
        int middleIndex = (rightIndex - leftIndex) / 2 + leftIndex;
        if (num[middleIndex] == goal_num) {
            return middleIndex;
        }
        
        if (goal_num < num[middleIndex]) {
            rightIndex = middleIndex - 1;
        }
        
        if (goal_num > num[middleIndex]) {
            leftIndex = middleIndex + 1;
        }
    }
    
    return -1;
}

/**
 字符串逆序
 */
void bf_StringReverseOrder(char str[]) {
    
//    char* startIndex = str;
//    char* endIndex = str;
//    while ('\0' != *endIndex) {
//        endIndex++;
//    }
//    endIndex--;
//    
//    // 在两个指针相交前，进行靠近移动交换
//    while (startIndex < endIndex) {
//        char tempStart = *startIndex;
//        char tempEnd = *endIndex;
//        *startIndex = tempEnd;
//        *endIndex = tempStart;
//        
//        startIndex++;
//        endIndex--;
//    }
    
    int str_Length = sizeof(str) / sizeof(char) - 1;
    int leftIndex = 0;
    int rightIndex = str_Length - 1;
    while (leftIndex < rightIndex) {
        char tempChar = str[leftIndex];
        str[leftIndex] = str[rightIndex];
        str[rightIndex] = tempChar;
        
        leftIndex++;
        rightIndex--;
    }
    

}

#pragma mark - Test

void test_Sorting() {
    
    int num[] = {2, 1, 5, 7, 3, 6, 9, 8, 4, 0, 11, 12, 10};
    int num_length = sizeof(num)/sizeof(int);
    
    //    printf("快排");
    //    bf_quickSort(num, 0, num_length);
    
    printf("冒泡排序");
    bf_BubbleSort(num, num_length);
    
    printNumArray(num, num_length);
}

void test_Factorial() {
    
    int num = 5;
    int result = bf_Factorial(num);
    printf("%d的阶乘结果：%d\n", num, result);
}

void test_GCD() {
    
    int a = 10, b = 6;
    int gcd = bf_GreatestCommonDivisor(a, b);
    printf("%d 和 %d 的最大公约数：%d\n", a, b, gcd);
}

void test_BinarySearch() {
    
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_length = sizeof(num) / sizeof(int);
    int goal_Num = 6;
    int result = bf_BinarySearch(num, num_length, goal_Num);
    
    printf("二分查找目标数 %d 对应的索引号是：%d\n", goal_Num, result);
    
    int num_size = sizeof(num);
    printf("num数组内存大小: %d\n", num_size);
}

void test_StringReverseOrder() {
    
    char* str = "ABCDEFG";
    bf_StringReverseOrder(str);
    
    printf("逆序字符串结果：%s\n", str);
}

#pragma mark - Main

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    test_Sorting();
//    test_Factorial();
//    test_GCD();
    test_BinarySearch();
//    test_StringReverseOrder();
    
    return 0;
}
