/**
 * @file bus_decorator.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#ifndef SRC_BUS_DECORATOR_H_
#define SRC_BUS_DECORATOR_H_


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
 * @brief The main class for the IBus interface.
 *
 * 
 *
 */
class BusDecorator : public IBus {
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
  virtual bool IsTripComplete() { return bus->IsTripComplete(); }

 /**
  * @brief Load a passenger onto the bus.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] passenger 
  *
  * @return LoadPassenger returns if the passenger is loaded on bus successfully.
  */
  virtual bool LoadPassenger(Passenger * passenger)
    { return bus->LoadPassenger(passenger); }

 /**
  * @brief Move the bus if possible.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Move returns if the bus actually moved.
  */
  virtual bool Move() { return bus->Move(); }

 /**
  * @brief Updates the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  virtual void Update() { bus->Update(); }

 /**
  * @brief Report the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  virtual void Report(std::ostream& out) { bus->Report(out); }

 /**
  * @brief Updates the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return UpdateBusData does not return anything.
  */
  virtual void UpdateBusData() { bus->UpdateBusData(); }

 /**
  * @brief Construct a BusDecorator obejct with a destination_stop_id and a name.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] baseBus
  *
  * @return Constructor does not return anything.
  */
  explicit BusDecorator(IBus * baseBus): bus(baseBus) {}

 /**
  * @brief Get the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetBusData returns the data concerning the bus as a BusData struct.
  */
  virtual BusData GetBusData() const { return bus->GetBusData(); }

 /**
  * @brief Get the name of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetName returns the name of the bus as string.
  */
  virtual std::string GetName() const { return bus->GetName(); }

 /**
  * @brief Get the next stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNextStop return the next stop as a Stop object.
  */
  virtual Stop * GetNextStop() const { return bus->GetNextStop(); }

 /**
  * @brief Get the number of passengers on the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNumPassengers returns the number of passengers on the bus as a size_t struct.
  */
  virtual size_t GetNumPassengers() const { return bus->GetNumPassengers(); }

 /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  virtual int GetCapacity() const { return bus->GetCapacity(); }

  /**
  * @brief Get the capacity of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetCapacity returns the capacity of the bus.
  */
  virtual int GetTotalPassengers() const { return bus->GetTotalPassengers(); }

 /**
  * @brief Skip prints "skip" if the next stop should be skipped.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  virtual void skip() { bus->skip(); }

/**
  * @brief Get the incoming route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetIncomingRoute returns the incoming route.
  */
  virtual Route * GetIncomingRoute() const { return bus->GetIncomingRoute(); }

  /**
  * @brief Get the outgoing route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetOutgoingRoute returns the outgoing route.
  */
  virtual Route * GetOutgoingRoute() const { return bus->GetOutgoingRoute(); }

 protected:
  IBus * bus;
};
#endif  // SRC_BUS_DECORATOR_H_
