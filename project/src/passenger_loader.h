/**
 * @file passenger_loader.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#ifndef SRC_PASSENGER_LOADER_H_
#define SRC_PASSENGER_LOADER_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "./passenger.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the loading of passengers.
 *
 * 
 * 
 */
class PassengerLoader {
 public:
 /**
  * @brief Load passengers.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] new_passenger
  * @param[in] max_pass 
  * @param[in] passengers 
  *
  * @return LoadPassenger returns the number of passengers loaded.
  */
  // LoadPassenger returns the number of passengers added to the bus.
  // Currently this is either one or zero: either passenger was added or they
  // weren't.
  // This was a design decision. We don't know if we should allow the adding of
  // multiple passengers at a time
  // This allows us to change the Passenger Loader without having to change
  // the Bus.
  int LoadPassenger(Passenger * new_passenger, int max_pass,
                    std::list<Passenger *> * passengers);
};
#endif  // SRC_PASSENGER_LOADER_H_
