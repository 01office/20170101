//
//  learnboost.hpp
//  new20170101
//
//  Created by heyong on 2017/1/16.
//  Copyright © 2017年 heyong. All rights reserved.
//

#ifndef learnboost_hpp
#define learnboost_hpp

#include <iostream>
#include <vector>
#include <string>
#include <boost/any.hpp>

class A
{
public:
    void a_func();
};

class B
{
public:
    void b_func();
};

void print_any(boost::any &m);

#endif /* learnboost_hpp */
