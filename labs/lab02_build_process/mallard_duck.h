//
//  mallard_duck.h
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//


#ifndef MALLARD_DUCK_H
#define MALLARD_DUCK_H

#include <string>
#include "duck.h"

class MallardDuck : public Duck {
public:
    MallardDuck();
    ~MallardDuck();

    std::string get_description();
};

#endif
