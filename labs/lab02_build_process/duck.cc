//
//  duck.cpp
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include "duck.h"

#include <iostream>

#include "quack_behavior.h"
#include "quack_quack.h"

using std::cout;
using std::endl;

Duck::Duck() {
    quack_behavior_ = NULL;
    set_quack_behavior(new QuackQuack);
    set_name("Duck");
}

void Duck::PerformQuack() {
    quack_behavior_->Quack();
}

void Duck::set_quack_behavior(QuackBehavior* behavior) {
    if (quack_behavior_ != NULL)
        delete quack_behavior_;

    quack_behavior_ = behavior;
}
