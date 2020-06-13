/**
 * @file large_bus.cc
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#include "src/large_bus.h"

void LargeBus::Report(std::ostream& out) {
  Bus::Report(out);
  out << "Type: LargeBus" << std::endl;
}
