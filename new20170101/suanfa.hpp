//
//  suanfa.hpp
//  new20170101
//
//  Created by heyong on 2017/1/2.
//  Copyright © 2017年 heyong. All rights reserved.
//

#ifndef suanfa_hpp
#define suanfa_hpp

#include <iostream>
#include <pthread.h>
#include <unistd.h>

int b_search(int a[], int n, int v);

void quick_sort(int a[], int left, int right);

void *th1(void *arg);
void *th2(void *arg);

// construct tree via preorder and inorder list
struct TreeNode
{
    int m_nValue;
    TreeNode *m_pLeft;
    TreeNode *m_pRight;
};

class ClassTree
{
public:
    TreeNode *construct_tree(int *preOrder, int *inOrder, int length);
    
private:
    TreeNode *consrtuct_tree_core(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder);
};

class MergeSort
{
public:
    bool merge_sort(int a[], int n);
    
private:
    void merge_sort(int a[], int first, int last, int temp[]);
    void merge_sort(int a[], int first, int middle, int last, int temp[]);
};

#endif /* suanfa_hpp */
