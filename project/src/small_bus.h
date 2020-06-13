/**
 * @file small_bus.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the small bus.
 *
 * 
 */
class SmallBus : public Bus {
 public:
 /**
  * @brief Generation of a small bus.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] name
  * @param[in] out
  * @param[in] in
  * @param[in] speed
  *
  * @return Constructor does not return anything.
  */
  SmallBus(std::string name, Route * out, Route * in, double speed = 1)
                                    : Bus(name, out, in, 30, speed) {}

 /**
  * @brief Report the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  void Report(std::ostream&) override;
};

#endif  // SRC_SMALL_BUS_H_
