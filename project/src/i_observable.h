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
 /**
  * @brief Register a new observer.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] observer 
  *
  * @return RegisterObserver does not return anything.
  */
  void RegisterObserver(IObserver * observer);

  /**
  * @brief Clear all observers.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return ClearObserver does not return anything.
  */
  void ClearObserver();

  /**
  * @brief Notify all observers using bus_data.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] bus_data
  *
  * @return NotifyObserver does not return anything.
  */
  void NotifyObserver(BusData * bus_data);

 private:
  std::vector<IObserver *> observer_;
};

#endif  // SRC_I_OBSERVABLE_H_
