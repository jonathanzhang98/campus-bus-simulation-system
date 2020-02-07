//
//  delivery.h
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#ifndef OVERNIGHT_H_
#define OVERNIGHT_H_

#include "delivery.h"

class Overnight : public Delivery {
public:
  Overnight(std::string package);
  Overnight(const Overnight &on) {
    std::cout << "making a copy of overnight" << std::endl;
  }
  ~Overnight();
  void Transport();
};

#endif  // OVERNIGHT_H_
