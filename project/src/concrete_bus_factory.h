/**
 * @file concrete_bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONCRETE_BUS_FACTORY_H_
#define SRC_CONCRETE_BUS_FACTORY_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"
#include "src/route.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of buses.
 *
 * Calls to \ref Generate function to get a new instance of a passenger.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class ConcreteBusFactory {
 public:
 /**
  * @brief Generation of a bus.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] id
  * @param[in] outbound
  * @param[in] inbound
  * @param[in] busType
  * @param[in] speed
  *
  * @return GenerateBus returns a bus pointer.
  */
  static Bus * GenerateBus(string id, Route * outbound, Route * inbound
                                      , int busType, double speed = 1);
};
#endif  // SRC_CONCRETE_BUS_FACTORY_H_
