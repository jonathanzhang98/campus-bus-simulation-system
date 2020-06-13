/**
 * @file i_observer.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
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
template <typename T>
class IObserver {
 public:
 /**
  * @brief Update current observer base on info.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] info 
  *
  * @return UpdateObserver does not return anything.
  */
  virtual void UpdateObserver(T* info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
