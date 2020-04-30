/**
 * @file bus_decorator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
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
  virtual bool IsTripComplete() { return bus->IsTripComplete(); }
  virtual bool LoadPassenger(Passenger * passenger) { return bus->LoadPassenger(passenger); }
  virtual bool Move() { return bus->Move(); }
  virtual void Update() { bus->Update(); }
  virtual void Report(std::ostream& out) { bus->Report(out); }
  virtual void UpdateBusData() { bus->UpdateBusData(); }

  BusDecorator(IBus * baseBus): bus(baseBus) {}
  
  virtual BusData GetBusData() const { return bus->GetBusData(); }
  virtual std::string GetName() const { return bus->GetName(); }
  virtual Stop * GetNextStop() const { return bus->GetNextStop(); }
  virtual size_t GetNumPassengers() const { return bus->GetNumPassengers(); }
  virtual int GetCapacity() const { return bus->GetCapacity(); }
  virtual int GetTotalPassengers() const { return bus->GetTotalPassengers(); }
  virtual void skip() { bus->skip(); }
  virtual Route * GetIncomingRoute() const { return bus->GetIncomingRoute(); }
  virtual Route * GetOutgoingRoute() const { return bus->GetOutgoingRoute(); }
 protected:
  IBus * bus;
};
#endif  // SRC_BUS_DECORATOR_H_