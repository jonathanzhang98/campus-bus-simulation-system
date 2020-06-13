/**
 * @file small_bus.cc
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#include "src/small_bus.h"

void SmallBus::Report(std::ostream& out) {
  Bus::Report(out);
  out << "Type: SmallBus" << std::endl;
}
