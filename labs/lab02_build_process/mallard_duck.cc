//
//  MallardDuck.cpp
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include <iostream>
#include <string>
#include "mallard_duck.h"

//#include "quack_quack.h"

using std::cout;
using std::endl;
using std::string;

MallardDuck::MallardDuck() {

}

MallardDuck::~MallardDuck() {}

string MallardDuck::get_description() {
    string description_text = "a mallard duck";
    return description_text;
}
