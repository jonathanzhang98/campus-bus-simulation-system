/**
 * @file regular_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_REGULAR_BUS_H_
#define SRC_REGULAR_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class RegularBus : public Bus {
 public:
  RegularBus(std::string name, Route * out, Route * in, double speed = 1): Bus(name, out, in, 30, speed) {}
  void Report(std::ostream&) override;
};

#endif  // SRC_REGULAR_BUS_H_