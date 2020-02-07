//
//  overnight.cc
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#include <iostream>
#include <string>

#include "overnight.h"

Overnight::Overnight(std::string package) : Delivery(package) {
  std::cout << "Creating an overnight." << std::endl;
  // IncrementCount();
  set_days(1);
}

Overnight::~Overnight() {
  std::cout << "Deleting an overnight." << std::endl;
  // DecrementCount();
}

void Overnight::Transport() {
  std::cout << "This is being transported via airplane." << std::endl;
  std::cout << "It will take " << get_days() << " day(s)." << std::endl;
}
