//
//  delivery.h
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#ifndef DELIVERY_H_
#define DELIVERY_H_

#include <string>

class Delivery {
  static int delivery_count_;
public:
  Delivery(std::string package = "Default Package.");
  virtual ~Delivery();
  virtual void Transport();
  void Deliver();
  static void IncrementCount() { delivery_count_++; }
  static void DecrementCount() { delivery_count_--; }

  void set_days(int d) {days_to_deliver_ = d;}
  int get_days() { return days_to_deliver_; }
  static int get_count() { return delivery_count_;}

protected:
  int protected_variable_;

private:
  std::string package_;
  int days_to_deliver_;
};

#endif  // DELIVERY_H_
