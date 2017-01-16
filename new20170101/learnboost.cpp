//
//  learnboost.cpp
//  new20170101
//
//  Created by heyong on 2017/1/16.
//  Copyright © 2017年 heyong. All rights reserved.
//

#include "learnboost.hpp"

void A::a_func()
{
    std::cout << "a function" << std::endl;
}

void B::b_func()
{
    std::cout << "b function" << std::endl;
}

void print_any(boost::any &m)
{
    if (A *pa = boost::any_cast<A>(&m)) {
        pa->a_func();
    } else if (B *pb = boost::any_cast<B>(&m)) {
        pb->b_func();
    }
}
