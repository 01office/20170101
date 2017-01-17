//
//  main.cpp
//  new20170101
//
//  Created by heyong on 2017/1/2.
//  Copyright © 2017年 heyong. All rights reserved.
//

#include <iostream>

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
    
    return 0;
}
