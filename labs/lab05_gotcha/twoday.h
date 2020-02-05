//
//  twoday.h
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#ifndef TWODAY_H_
#define TWODAY_H_

#include "delivery.h"

class TwoDay : public Delivery {
public:
  TwoDay(std::string package);
  ~TwoDay();
  void Transport();
};

#endif  // OVERNIGHT_H_
