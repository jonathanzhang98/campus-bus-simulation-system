/**
 * @file Bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_STOP_H_
#define SRC_STOP_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"
#include "src/i_observable.h"

class Bus;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of passengers.
 *
 * 
 * 
 */
class Stop : public IObservable <StopData> {
 public:
 /**
  * @brief Construct a Passenger obejct with a destination_stop_id and a name.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] id
  * @param[in] latitude 
  * @param[in] longitude 
  *
  * @return Constructor does not return anything.
  */
  explicit Stop(int, double = 44.973723, double = -93.235365);

 /**
  * @brief Removing passengers from stops and onto a bus
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return LoadPassengers returns the number of passengers loaded to a bus.
  */
  int LoadPassengers(Bus *);  // Removing passengers from stop
  // and onto a bus

 /**
  * @brief Add passengers to the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return AddPassengers returns the number of passenger added to the stop.
  */
  int AddPassengers(Passenger *);  // Adding passengers
  // to the stop (from the generator)

 /**
  * @brief Update the states of the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  void Update();

 /**
  * @brief Get the id of the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetId returns the id of the stop.
  */
  int GetId() const;

 /**
  * @brief Report the states of the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  void Report(std::ostream&) const;

  // Vis Getters
 /**
  * @brief Get the longitude of the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetLongitude returns the longitude of the stop.
  */
  double GetLongitude() const { return longitude_; }

 /**
  * @brief Get the latitude of the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetLatitude returns the latitude of the stop.
  */
  double GetLatitude() const { return latitude_; }

 /**
  * @brief Get the number of passengers at the stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNumPassengersPresent returns the number of passengers at the stop.
  */
  size_t GetNumPassengersPresent() { return passengers_.size(); }

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
