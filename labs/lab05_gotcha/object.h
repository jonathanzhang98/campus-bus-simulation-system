//
//  object.h
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdint.h>

#include "overnight.h"

class Object {
  static int object_count_;
public:
  Object() {
    ++object_count_;
    dummy_var = 10;
    // Dynamically instantiate overnight deliveries to fill array.
    for (int i=0; i<2; i++) {
      packages_[i] = new Overnight("Overnight Package.");
    }
    // Store the address of the array.
    address_ = (int64_t) packages_;
    std::cout << "creating Object with address " << address_ << std::endl;
  }
  ~Object() {
    std::cout << "In ~Object deleting " << address_ << std::endl;
    /*
    for (int i=0; i<2; i++) {
      delete packages_[i];
    }
    delete packages_;
    delete[] packages_;
    */
  }
  int64_t get_address() {return address_;}
  static int get_count() {return object_count_;}

private:
  int dummy_var;
  Overnight * packages_[2];
  int64_t address_;
};

#endif
