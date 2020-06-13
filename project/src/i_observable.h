/**
 * @file i_observable.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
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
template <typename T>
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
  void RegisterObserver(IObserver<T> * observer) {
    observer_.push_back(observer);
  }

  /**
  * @brief Clear all observers.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return ClearObserver does not return anything.
  */
  void ClearObserver() {
    observer_.erase(observer_.begin(), observer_.end());
  }

  /**
  * @brief Notify all observers using bus_data.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] bus_data
  *
  * @return NotifyObserver does not return anything.
  */
  void NotifyObserver(T * data) {
    for (typename std::vector<IObserver<T>*>::const_iterator
     iter = observer_.begin();
     iter != observer_.end(); ++iter) {
      if (*iter != 0) {
          (*iter)->UpdateObserver(data);
      }
    }
  }

 private:
  std::vector<IObserver<T> *> observer_;
};

#endif  // SRC_I_OBSERVABLE_H_
