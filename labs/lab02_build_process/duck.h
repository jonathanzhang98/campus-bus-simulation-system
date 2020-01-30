//
//  duck.h
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef DUCK_H
#define DUCK_H

#include <string>

class QuackBehavior;


class Duck {
public:
    Duck();
    virtual ~Duck() {};

    virtual void PerformQuack();

    virtual std::string get_description() = 0;

    std::string get_name() {return name_;}
    void set_name(std::string name ) {name_ = name;}
    void set_quack_behavior(QuackBehavior * behavior);
protected:
    std::string name_;

    QuackBehavior * quack_behavior_;

};

#endif
