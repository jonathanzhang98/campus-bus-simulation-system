//
//  ground.h
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#ifndef GROUND_H_
#define GROUND_H_

#include <iostream>
#include <string>

#include "delivery.h"

class Ground : public Delivery {
public:
  Ground(std::string package);
  ~Ground();
  void Transport();
private:
  int days_to_deliver_;
};

#endif  // GROUND_H_
