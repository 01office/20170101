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

#endif /* suanfa_hpp */
