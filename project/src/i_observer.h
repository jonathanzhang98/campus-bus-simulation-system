/**
 * @file i_observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_I_OBSERVER_H_
#define SRC_I_OBSERVER_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the IObserver.
 *
 * 
 */
class IObserver {
 public:
  virtual void UpdateObserver(BusData* info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
