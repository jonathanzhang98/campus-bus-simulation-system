/**
 * @file route.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>
#include <string>
#include <vector>

#include "./data_structs.h"

#include "./passenger_generator.h"
#include "./stop.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the routes.
 *
 * 
 * 
 */
class PassengerGenerator;

class Route {
 public:
 /**
  * @brief Construct a Route obejct.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] name
  * @param[in] stops 
  * @param[in] distances 
  * @param[in] num_stops 
  * @param[in] generator 
  *
  * @return Constructor does not return anything.
  */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);

 /**
  * @brief Clone the current route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Clone returns a copy of the route as a pointer.
  */
  Route * Clone();

 /**
  * @brief Updates the states of the route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Update does not return anything.
  */
  void Update();

 /**
  * @brief Report the states of the route.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] outpt stream 
  *
  * @return Report does not return anything.
  */
  void Report(std::ostream&);

  /**
  * @brief Check if the route is at the end.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Move returns if the the route is at the end.
  */
  bool IsAtEnd() const;

  /**
  * @brief Returns stop before destination stop
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return PrevStop returns stop before destination stop
  */
  Stop *  PrevStop();  // Returns stop before destination stop

 /**
  * @brief Change destination_stop_ to next stop
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return ToNextStop does not return anything.
  */
  void ToNextStop();  // Change destination_stop_ to next stop

  /**
  * @brief Get the destination stop of the route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetDestinationStop returns the destination stop of the route.
  */
  Stop * GetDestinationStop() const;    // Get pointer to next stop

  /**
  * @brief Get the total route distance.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetTotalRouteDistance returns the total route distance.
  */
  double GetTotalRouteDistance() const;

  /**
  * @brief Get the distance to the next stop.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetNextStopDistance returns the distance to the next stop.
  */
  double GetNextStopDistance() const;

  // Vis Getters

 /**
  * @brief Get the name of the route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetName returns the name of the route as string.
  */
  std::string GetName() const { return name_; }

 /**
  * @brief Get a list of stops on the route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetStops returns a list of stops.
  */
  std::list<Stop *> GetStops() const { return stops_; }

 /**
  * @brief Update the route data concerning the route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return UpdateRouteData does not return anything.
  */
  void UpdateRouteData();

 /**
  * @brief Get the route data concerning the route.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetRouteData returns the route data concerning the route.
  */
  RouteData GetRouteData() const;

 private:
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  // double trip_time_; // derived data - total distance travelled on route

  RouteData route_data_;
};
#endif  // SRC_ROUTE_H_

