//
//  Duck.cpp
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include "duck.h"

#include <iostream>

using std::cout;
using std::endl;

Duck::Duck() : name_("Duck"), array_number_(0) {

}

Duck::Duck(std::string name, int number) : name_(name), array_number_(number) {
}

void Duck::PerformQuack() {
    cout << name_ << " in ducks" << array_number_ << " says Quack." << endl;
}
