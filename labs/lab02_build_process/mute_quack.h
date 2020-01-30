//
//  mute_quack.h
//
//  Created by Seth Johnson on 2/5/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef MUTE_QUACK_H
#define MUTE_QUACK_H

#include "quack_behavior.h"

class MuteQuack : public QuackBehavior {
public:
    MuteQuack() {};
    ~MuteQuack() {};
    void Quack();
};

#endif
