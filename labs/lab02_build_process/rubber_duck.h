//
//  rubber_duck.h
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef RUBBER_DUCK_H
#define RUBBER_DUCK_H

#include <string>
#include "duck.h"

class RubberDuck : public Duck {
public:
    RubberDuck();
    ~RubberDuck();

    std::string get_description();
};

#endif
