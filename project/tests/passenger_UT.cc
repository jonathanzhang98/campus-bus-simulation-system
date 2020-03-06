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
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;
    
  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
/*
* Test Constructor only for those values that have getters/setters
* 1. destination_stop_id_
* 2. wait_at_stop_
* 3. time_on_bus_
*/

// Test Constructor destination_stop_id_
TEST_F(PassengerTests, ConstructorDestinationStopId) {
  passenger = new Passenger();
  
  passenger->GetOnBus();
  
};


// Test Constructor wait_at_stop_
TEST_F(PassengerTests, ConstructorWaitAtStop) {
  // test wait_at_stop_ is initialized to 0 (Use GetTotalWait, Report)
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);

  // test wait_at_stop_ is still 0 after GetOnBus() is called (Use GetTotalWait, Report)
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
};

// Test Constructor time_on_bus_
TEST_F(PassengerTests, ConstructorTimeOnBus) {
  // test time_on_bus_ is initialized to 0 (Use IsOnBus)
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);

  // test time_on_bus_ is incremented correctly (Use IsOnBus)
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
};


// Test Update()
TEST_F(PassengerTests, Update) {

};


// Test GetOnBus()
TEST_F(PassengerTests, GetOnBus) {

};


// Test GetTotalWait()
TEST_F(PassengerTests, GetTotalWait) {

};


// Test IsOnBus
TEST_F(PassengerTests, IsOnBus) {

};


// Test GetDestination()
TEST_F(PassengerTests, GetDestination) {

};


// Test Report()
TEST_F(PassengerTests, Report) {

};