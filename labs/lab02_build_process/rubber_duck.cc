//
//  RubberDuck.cpp
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include "rubber_duck.h"
#include "squeak_quack.h"

using std::cout;
using std::endl;
using std::string;

RubberDuck::RubberDuck() {
    set_quack_behavior(new SqueakQuack);
}

RubberDuck::~RubberDuck() {}

string RubberDuck::get_description() {
    string description_text = "a yellow rubber ducky";
    return description_text;
}
