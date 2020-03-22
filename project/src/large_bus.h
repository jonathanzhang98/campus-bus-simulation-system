/**
 * @file large_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class LargeBus : public Bus {
 public:
  LargeBus(std::string name, Route * out, Route * in, double speed = 1): Bus(name, out, in, 90, speed) {}
  void Report(std::ostream&) override;
};

#endif  // SRC_LARGE_BUS_H_