//
//  decoy_duck.h
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef DECOY_DUCK_H
#define DECOY_DUCK_H

#include <string>
#include "duck.h"

class DecoyDuck : public Duck {
public:
    DecoyDuck();
    ~DecoyDuck();

    std::string get_description();
};

#endif
