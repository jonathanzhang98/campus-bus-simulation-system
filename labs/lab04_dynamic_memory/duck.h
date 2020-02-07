//
//  Duck.h
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef DUCK_H_
#define DUCK_H_

#include <string>
#include <iostream>

using std::cout;
using std::endl;

class Duck {
public:
    // Constructors and Destructor
    Duck();
    Duck(std::string name, int number=0);
    ~Duck() {
      cout << name_ << " in ducks" << array_number_ << " is being destroyed.\n";
    }
    // Mutators and Accessors
    void PerformQuack();
    std::string get_name() {return name_;}
    void set_name(std::string name ) {name_ = name;}
    void set_number(int number) {array_number_ = number;}
private:
    std::string name_;
    int array_number_;
};

#endif
