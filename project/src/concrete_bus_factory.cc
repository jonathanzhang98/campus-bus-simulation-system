/**
 * @file concrete_bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/concrete_bus_factory.h"

Bus * ConcreteBusFactory::GenerateBus(string id, Route * outbound, Route * inbound, int busType, double speed) {
  if (busType == 1) 
    return new SmallBus(id, outbound, inbound, speed); 
  else if (busType == 2) 
    return new RegularBus(id, outbound, inbound, speed); 
  else if (busType == 3) 
    return new LargeBus(id, outbound, inbound, speed); 
  else return NULL; 
}