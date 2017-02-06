//
//  adapter.cpp
//  new20170101
//
//  Created by heyong on 2017/2/6.
//  Copyright © 2017年 heyong. All rights reserved.
//

#include "adapter.hpp"

Adaptee::Adaptee(){}
Adaptee::~Adaptee(){}
void Adaptee::special_request()
{
    std::cout << "Adpater Pattern" << std::endl;
}

Target::Target(){}
Target::~Target(){}
void Target::request(){}

Adapter::Adapter(Adaptee *adp)
{
    m_pAdaptee = adp;
}

Adapter::~Adapter(){}

void Adapter::request()
{
    m_pAdaptee->special_request();
}
