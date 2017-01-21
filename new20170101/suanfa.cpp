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

bool MergeSort::merge_sort(int a[], int n)
{
    int first = 0, last = n - 1;
    int *p = new int[n];
    merge_sort(a, first, last, p);
    delete []p;
    return true;
}

void MergeSort::merge_sort(int a[], int first, int last, int tmp[])
{
    if (first < last) {
        int middle = (first + ((last - first) >> 1));
        merge_sort(a, first, middle, tmp);      // 左边有序
        merge_sort(a, middle + 1, last, tmp);   // 右边有序
        merge_sort(a, first, middle, last, tmp);
    }
}

void MergeSort::merge_sort(int a[], int first, int middle, int last, int tmp[])
{
    int i = first, j = middle + 1, k = 0;
    int m = middle, n = last;
    
    while (i < m && j < n) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    
    while (i < m) {
        tmp[k++] = a[i++];
    }
    
    while (j < n) {
        tmp[k++] = a[j++];
    }
    
    for (int i = 0; i < k; k++) {
        a[first + i] = tmp[i];
    }
}
