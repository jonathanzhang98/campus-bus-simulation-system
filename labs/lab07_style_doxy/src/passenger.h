/**
 * @file passenger_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

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
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  bool IsOnBus() const;
  int GetDestination() const;
  void Report() const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
