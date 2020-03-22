/**
 * @file concrete_bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONCRETE_BUS_FACTORY_H_
#define SRC_CONCRETE_BUS_FACTORY_H_

#include <iostream>
#include <list>
#include <string>

#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"
#include "src/route.h"

using namespace std;

class ConcreteBusFactory {
 public:
  static Bus * GenerateBus(string id, Route * outbound, Route * inbound, int busType, double speed = 1);
};
#endif  // SRC_CONCRETE_BUS_FACTORY_H_