/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger_generator.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/bus.h"
#include "../src/data_structs.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Route *route, *route1, *route2;
  Stop *stop, *stop1, *stop2;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    stop = new Stop(1);
    stop1 = new Stop(2);
    stop2 = new Stop(3);
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    pass_loader = NULL;
    pass_unloader = NULL;
    delete passenger;
    delete passenger1;
    delete passenger2;
    passenger = NULL;
    passenger1 = NULL;
    passenger2 = NULL;
    delete stop;
    delete stop1;
    delete stop2;
    stop = NULL;
    stop1 = NULL;
    stop2 = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
/*
* Test Constructor only for those values that have getters/setters
* 1. name_
* 2. stops_
* 3. route_data_
* 4. destination_stop_
* 5. 
*/

// Test Constructor
TEST_F(RouteTests, Constructor) {

};