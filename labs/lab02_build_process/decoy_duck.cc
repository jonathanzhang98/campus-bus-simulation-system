//
//  decoy_duck.cpp
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include "decoy_duck.h"
#include "mute_quack.h"

using std::cout;
using std::endl;
using std::string;

DecoyDuck::DecoyDuck() {
    set_quack_behavior(new MuteQuack);
}

DecoyDuck::~DecoyDuck() {}

string DecoyDuck::get_description() {
    string description_text = "a plastic decoy duck";
    return description_text;
}
