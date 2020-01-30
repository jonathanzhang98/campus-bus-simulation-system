//
//  quack_quack.h
//
//  Created by Seth Johnson on 2/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef QUACK_QUACK_H
#define QUACK_QUACK_H

#include "quack_behavior.h"

class QuackQuack : public QuackBehavior {
public:
    QuackQuack() {};
    ~QuackQuack() {};
    void Quack();
};

#endif
