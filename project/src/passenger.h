/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for passengers.
 *
 * 
 */
class Passenger {  // : public Reporter {
 public:
 /**
  * @brief Construct a Passenger obejct with a destination_stop_id and a name.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] destination_stop_id 
  * @param[in] name 
  *
  * @return Constructor does not return anything.
  */
  explicit Passenger(int = -1, std::string = "Nobody");

 /**
  * @brief Updates the states of the passenger.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  void Update();

 /**
  * @brief Get the passenger on bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetOnBus does not return anything.
  */
  void GetOnBus();

 /**
  * @brief Get the passenger's total weight time
  *
  * This function will be used for simulation purposes.
  *
  * @return GetTotalWait returns the passenger's total weight time.
  */
  int GetTotalWait() const;

 /**
  * @brief Check if the passenger is on the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return IsOnBus returns a bool representing if the passenger is on the bus.
  */
  bool IsOnBus() const;

 /**
  * @brief Get the destination id of the passenger.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetDestination returns the destination of the passenger as an integer id.
  */
  int GetDestination() const;

 /**
  * @brief Report prints out the status of a passenger to the output stream.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] output stream 
  *
  * @return Report does not return anything.
  */
  void Report(std::ostream&) const;
 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
