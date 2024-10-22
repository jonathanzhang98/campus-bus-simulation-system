/**
 * @file passenger_loader.cc
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#include "src/passenger_loader.h"

int PassengerLoader::LoadPassenger(Passenger * new_passenger, int max_pass,
                                   std::list<Passenger *> * passengers) {
  // Normally would use a boolean, but for extensibility,
  // using count of those added_passenger
  // Currently, only one could be added, so possible values are 0 or 1.
  int added_passenger = 0;
  if (static_cast<int>((*passengers).size()) < max_pass) {
    (*passengers).push_back(new_passenger);
    new_passenger->GetOnBus();
    added_passenger = 1;
  }
  return added_passenger;
}
