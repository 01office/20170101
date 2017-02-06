//
//  main.cpp
//  new20170101
//
//  Created by heyong on 2017/1/2.
//  Copyright © 2017年 heyong. All rights reserved.
//

#include <iostream>
#include <queue>

#include "suanfa.hpp"
#include "learnboost.hpp"

using namespace std;

int main() {
    int a[] = {3, 5, 2, 4, 6, 9, 7};
    quick_sort(a, 0, 6);
    
    for (int i = 0; i < 7; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << b_search(a, 7, 6) + 1 << endl;
    
    std::vector<boost::any> store_anything;
    store_anything.push_back(A());
    store_anything.push_back(B());
    store_anything.push_back(std::string("This is fantastic."));
    store_anything.push_back(7);
    std::for_each(store_anything.begin(), store_anything.end(), print_any);
    
    pthread_t pt1, pt2;
    pthread_create(&pt1, NULL, th1, NULL);
    pthread_create(&pt2, NULL, th2, NULL);
    pthread_join(pt1, NULL);
    pthread_join(pt2, NULL);
    
    MergeSort ms;
    ms.merge_sort(a, 7);
    
    priority_queue<int> pq;
    
    return 0;
}
