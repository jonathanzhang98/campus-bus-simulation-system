/**
 * @file passenger_unloader.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_UNLOADER_H_
#define SRC_PASSENGER_UNLOADER_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "src/passenger.h"
#include "src/stop.h"
class Stop;
class Passenger;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the unloading of passengers.
 *
 * 
 * 
 */
class PassengerUnloader {
 public: 
 /**
  * @brief Unload passengers.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] new_passenger
  * @param[in] max_pass 
  * @param[in] passengers 
  *
  * @return UnloadPassenger returns the number of passengers unloaded.
  */
  // UnloadPassengers returns the number of passengers removed from the bus.
  int UnloadPassengers(std::list<Passenger*>* passengers, Stop * current_stop);
};
#endif  // SRC_PASSENGER_UNLOADER_H_


