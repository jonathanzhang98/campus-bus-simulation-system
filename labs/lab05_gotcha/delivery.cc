//
//  main.cc
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#include <iostream>
#include <string>

#include "delivery.h"
#include "ground.h"

Delivery::Delivery(std::string package) :
  package_(package), days_to_deliver_(7) {
    std::cout << "Creating a delivery." << std::endl;
    //IncrementCount();
    protected_variable_ = 100;
}

Delivery::~Delivery() {
  std::cout << "Deleting a delivery." << std::endl;
  //DecrementCount();
}

void Delivery::Transport() {
  std::cout << "Transportation mode is not yet set." << std::endl;
  std::cout << "This will take at least ";
  std::cout << days_to_deliver_ << " days to deliver." << std::endl;
}

void Delivery::Deliver() {
  std::cout << "DELIVERY: " << package_ << std::endl;
}
