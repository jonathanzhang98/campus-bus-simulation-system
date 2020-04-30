/**
 * @file i_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
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
class IBus : public IObservable {
 public:
//   virtual Bus(std::string name, Route * out, Route * in, int capacity = 60,
//                                                  double speed = 1) = 0;
  virtual bool IsTripComplete() = 0;
  virtual bool LoadPassenger(Passenger *) = 0;
  virtual bool Move() = 0;
  virtual void Update() = 0;
  virtual void Report(std::ostream&) = 0;
  virtual void UpdateBusData() = 0;
  virtual BusData GetBusData() const = 0;
  virtual std::string GetName() const = 0;
  virtual Stop * GetNextStop() const = 0;
  virtual size_t GetNumPassengers() const = 0;
  virtual int GetCapacity() const = 0;
  virtual int GetTotalPassengers() const = 0;
  virtual void skip() = 0;
  virtual Route * GetIncomingRoute() const = 0;
  virtual Route * GetOutgoingRoute() const = 0;
};
#endif  // SRC_I_BUS_H_