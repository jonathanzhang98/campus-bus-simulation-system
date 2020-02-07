//
//  twoday.cc
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#include <iostream>
#include <string>

#include "twoday.h"

TwoDay::TwoDay(std::string package) : Delivery(package) {
  std::cout << "Creating a twoday." << std::endl;
  //IncrementCount();
  set_days(2);
  protected_variable_ = 10;
}

TwoDay::~TwoDay() {
  std::cout << "Deleting a twoday." << std::endl;
  //DecrementCount();
}

void TwoDay::Transport() {
  std::cout << "Transport mode depends on distance." << std::endl;
  std::cout << "TwoDay has set the protected variable to ";
  std::cout << protected_variable_ << std::endl;
  std::cout << "It will take " << get_days() << " day(s)." << std::endl;
}
