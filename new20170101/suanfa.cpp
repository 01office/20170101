//
//  suanfa.cpp
//  new20170101
//
//  Created by heyong on 2017/1/2.
//  Copyright © 2017年 heyong. All rights reserved.
//

#include "suanfa.hpp"
#include <stdexcept>

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


TreeNode *ClassTree::construct_tree(int *preOrder, int *inOrder, int length)
{
    if (preOrder == NULL || inOrder == NULL || length <= 0) {
        return NULL;
    }
    
    return consrtuct_tree_core(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

TreeNode *ClassTree::consrtuct_tree_core(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
{
    int rootValue = startPreOrder[0];   // 前序遍历的第一个是根结点
    TreeNode *root = new TreeNode;
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    
    if (startPreOrder == endPreOrder) {
        if (*startPreOrder == *endPreOrder) {
            return root;
        }// else {
         //   throw std::exception("Invalid input.");
        //}
    }
    
    int *rootInorder = startPreOrder;
    while (rootInorder <= endInOrder && *rootInorder != rootValue) {
        rootInorder++;
    }
    
    int leftLength = rootInorder - startInOrder;
    int *leftPreorderEnd = startPreOrder + leftLength;
    
    if (leftLength > 0) {
        root->m_pLeft = consrtuct_tree_core(startPreOrder + 1, leftPreorderEnd, startInOrder, rootInorder - 1);
    }
    
    if (leftLength < endPreOrder - startPreOrder) {
        root->m_pRight = consrtuct_tree_core(leftPreorderEnd + 1, endPreOrder, rootInorder + 1, endInOrder);
    }
    
    return root;
}
