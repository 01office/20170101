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

#endif /* suanfa_hpp */
