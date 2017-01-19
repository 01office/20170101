//
//  suanfa.cpp
//  new20170101
//
//  Created by heyong on 2017/1/2.
//  Copyright © 2017年 heyong. All rights reserved.
//

#include "suanfa.hpp"

int b_search(int a[], int n, int v)
{
    int left = 0, right = n - 1, middle;
    
    while (left <= right) {
        middle = (left + ((right - left) >> 1));
        
        if (v == a[middle]) {
            return middle;
        }
        else if (v < a[middle]) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    
    return -1;
}


void quick_sort(int a[], int left, int right)
{
    if (left < right) {
        int i = left, j = right, tmp = a[i];
        
        while (i < j) {
            while (i < j && tmp <= a[j]) {
                j--;
            }
            if (i < j) {
                a[i++] = a[j];
            }
        
            while (i < j && tmp > a[i]) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        
        a[i] = tmp;
        quick_sort(a, left, i - 1);
        quick_sort(a, i + 1, right);
    }
}


__thread int i = 1;

void *th1(void *arg)
{
    std::cout << ++i << std::endl;      // 2
    return NULL;
}

void *th2(void *arg)
{
    sleep(2);                           // after th1
    std::cout << ++i << std::endl;      // 2, not 3
    return NULL;
}
