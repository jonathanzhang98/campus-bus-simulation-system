/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/data_structs.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/i_observer.h"
#include "src/i_observable.h"
#include "src/i_bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the buses.
 *
 * 
 *
 */
class Bus : public IBus {
 public:
 /**
  * @brief Construct a Passenger obejct with a destination_stop_id and a name.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] name
  * @param[in] out 
  * @param[in] in 
  * @param[in] capacity 
  * @param[in] speed 
  *
  * @return Constructor does not return anything.
  */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);

 /**
  * @brief Check if the trip is complete.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return IsTripComplete returns if the trip is complete as a bool.
  */
  bool IsTripComplete();

 /**
  * @brief Load a passenger onto the bus.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] passenger 
  *
  * @return LoadPassenger returns if the passenger is loaded on bus successfully.
  */
  bool LoadPassenger(Passenger *);  // returning revenue delta

 /**
  * @brief Move the bus if possible.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Move returns if the bus actually moved.
  */
  bool Move();

 /**
  * @brief Updates the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  void Update();

 /**
  * @brief Report the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  virtual void Report(std::ostream&);

  // Vis Getters
 /**
  * @brief Updates the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return UpdateBusData does not return anything.
  */
  void UpdateBusData();

 /**
  * @brief Get the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetBusData returns the data concerning the bus as a BusData struct.
  */
  BusData GetBusData() const;

 /**
  * @brief Get the name of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetName returns the name of the bus as string.
  */
  std::string GetName() const { return name_; }

 /**
  * @brief Get the next stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNextStop return the next stop as a Stop object.
  */
  Stop * GetNextStop() const { return next_stop_; }

 /**
  * @brief Get the number of passengers on the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNumPassengers returns the number of passengers on the bus as a size_t struct.
  */
  size_t GetNumPassengers() const { return passengers_.size(); }

 /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  int GetCapacity() const { return passenger_max_capacity_; }

  /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  int GetTotalPassengers() const { return total_passsengers_; }

 /**
  * @brief Skip prints "skip" if the next stop should be skipped.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  void skip();

  /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  Route * GetIncomingRoute() const { return incoming_route_; }

  /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  Route * GetOutgoingRoute() const { return outgoing_route_; }

//  /**
//   * @brief Report the states of the bus.
//   *
//   * This function will be used for simulation purposes.
//   *
//   *
//   * @return Report does not return anything.
//   */
//   void NotifyObserver(IObserver * observer) override;

 private:
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  int total_passsengers_;
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete

  // Vis data for bus
  BusData bus_data_;
};
#endif  // SRC_BUS_H_
