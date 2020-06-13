/**
 * @file i_bus.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#ifndef SRC_I_BUS_H_
#define SRC_I_BUS_H_


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

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the IBus interface.
 *
 * 
 *
 */
class IBus : public IObservable <BusData> {
 public:
//   virtual Bus(std::string name, Route * out, Route * in, int capacity = 60,
//                                                  double speed = 1) = 0;

 /**
  * @brief Check if the trip is complete.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return IsTripComplete returns if the trip is complete as a bool.
  */
  virtual bool IsTripComplete() = 0;
 
 /**
  * @brief Load a passenger onto the bus.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] passenger 
  *
  * @return LoadPassenger returns if the passenger is loaded on bus successfully.
  */
  virtual bool LoadPassenger(Passenger *) = 0;

 /**
  * @brief Move the bus if possible.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Move returns if the bus actually moved.
  */
  virtual bool Move() = 0;

 /**
  * @brief Updates the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  virtual void Update() = 0;

 /**
  * @brief Report the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  virtual void Report(std::ostream&) = 0;

 /**
  * @brief Updates the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return UpdateBusData does not return anything.
  */
  virtual void UpdateBusData() = 0;

 /**
  * @brief Get the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetBusData returns the data concerning the bus as a BusData struct.
  */
  virtual BusData GetBusData() const = 0;

 /**
  * @brief Get the name of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetName returns the name of the bus as string.
  */
  virtual std::string GetName() const = 0;

 /**
  * @brief Get the next stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNextStop return the next stop as a Stop object.
  */
  virtual Stop * GetNextStop() const = 0;

 /**
  * @brief Get the number of passengers on the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNumPassengers returns the number of passengers on the bus as a size_t struct.
  */
  virtual size_t GetNumPassengers() const = 0;

 /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  virtual int GetCapacity() const = 0;

  /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  virtual int GetTotalPassengers() const = 0;

 /**
  * @brief Skip prints "skip" if the next stop should be skipped.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  virtual void skip() = 0;

/**
  * @brief Get the incoming route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetIncomingRoute returns the incoming route.
  */
  virtual Route * GetIncomingRoute() const = 0;

/**
  * @brief Get the outgoing route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetOutgoingRoute returns the outgoing route.
  */
  virtual Route * GetOutgoingRoute() const = 0;
};
#endif  // SRC_I_BUS_H_
