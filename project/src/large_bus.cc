/**
 * @file large_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/large_bus.h"

void LargeBus::Report(std::ostream& out) {
  Bus::Report(out);
  out << "Type: LargeBus" << std::endl;
}