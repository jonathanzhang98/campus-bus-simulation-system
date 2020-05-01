/**
 * @file bus_color_decorator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_INTENSITY_DECORATOR_H_
#define SRC_BUS_INTENSITY_DECORATOR_H_


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
#include "src/bus_decorator.h"

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
class BusIntensityDecorator : public BusDecorator {
 public:
//   virtual Bus(std::string name, Route * out, Route * in, int capacity = 60,
//                                                  double speed = 1) = 0;
 /**
  * @brief Construct a BusDecorator obejct with a destination_stop_id and a name.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] baseBus
  *
  * @return Constructor does not return anything.
  */
  explicit BusIntensityDecorator(IBus * baseBus): BusDecorator(baseBus) {}
  // virtual bool IsTripComplete() = 0;
  // virtual bool LoadPassenger(Passenger *) = 0;
  // virtual bool Move() = 0;
  // virtual void Update() = 0;
  // virtual void Report(std::ostream&) = 0;
  // virtual void UpdateBusData() = 0;

 /**
  * @brief Get the data concerning the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetBusData returns the data concerning the bus as a BusData struct.
  */
  virtual BusData GetBusData() const;

  // virtual std::string GetName() const = 0;
  // virtual Stop * GetNextStop() const = 0;
  // virtual size_t GetNumPassengers() const = 0;
  // virtual int GetCapacity() const = 0;
  // virtual int GetTotalPassengers() const = 0;
  // virtual void skip() = 0;
};
#endif  // SRC_BUS_INTENSITY_DECORATOR_H_
