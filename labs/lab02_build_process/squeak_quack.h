//
//  squeak.h
//
//  Created by Seth Johnson on 2/5/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef SQUEAK_H
#define SQUEAK_H

#include "quack_behavior.h"

class SqueakQuack : public QuackBehavior {
public:
    SqueakQuack() {};
    ~SqueakQuack() {}
    void Quack();
};

#endif
