//
//  adapter.hpp
//  new20170101
//
//  Created by heyong on 2017/2/6.
//  Copyright © 2017年 heyong. All rights reserved.
//

#ifndef adapter_hpp
#define adapter_hpp

#include <iostream>

class Adaptee
{
public:
    Adaptee();
    ~Adaptee();
    void special_request();
};

class Target
{
public:
    Target();
    ~Target();
    virtual void request();
};

class Adapter : public Target
{
public:
    Adapter(Adaptee *adp);
    ~Adapter();
    virtual void request();
    
private:
    Adaptee *m_pAdaptee;
};

#endif /* adapter_hpp */
