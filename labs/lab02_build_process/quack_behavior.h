//
//  quack_behavior.h
//
//  Created by Seth Johnson on 2/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef QUACK_BEHAVIOR_H
#define QUACK_BEHAVIOR_H

#include <stdio.h>

class QuackBehavior {
public:
    QuackBehavior() {};
    virtual ~QuackBehavior() {}
    virtual void Quack() = 0;
};
#endif 
