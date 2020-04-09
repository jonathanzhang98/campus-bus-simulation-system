/**
 * @file i_observable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_I_OBSERVABLE_H_
#define SRC_I_OBSERVABLE_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "src/i_observer.h"
#include "src/data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the IObserver.
 *
 * 
 */
class IObservable {
 public:
  void RegisterObserver(IObserver * observer);
  void ClearObserver();
  void NotifyObserver(BusData * bus_data);
 private:
  std::vector<IObserver *> observer_;
};

#endif  // SRC_I_OBSERVABLE_H_
