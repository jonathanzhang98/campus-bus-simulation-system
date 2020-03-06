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
#include "../src/bus.h"
#include "../src/route.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Bus *bus, *bus1, *bus2;
    
  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete bus;
    delete bus1;
    delete bus2;
    bus = NULL;
    bus1 = NULL;
    bus2 = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
/*
* Test Constructor only for those values that have getters/setters
* 1. passengers_
* 2. passenger_max_capacity_
* 3. name_
* 4. next_stop_
* 5. bus_data_
*/

// Test Constructor passengers_
TEST_F(BusTests, ConstructorPassengers) {
  
};

// Test Constructor passenger_max_capacity_
TEST_F(BusTests, ConstructorPassengerMaxCapacity) {
  
};

// Test Constructor name_
TEST_F(BusTests, ConstructorName) {
  bus = new Bus("AT-AT", nullptr, nullptr);
  bus1 = new Bus("Speeder", nullptr, nullptr);
  bus2 = new Bus("Skyhopper", nullptr, nullptr);

  EXPECT_EQ(bus->GetName(), "AT-AT");
  EXPECT_EQ(bus1->GetName(), "Speeder");
  EXPECT_EQ(bus2->GetName(), "Skyhopper");
};

// Test Constructor next_stop_
TEST_F(BusTests, ConstructorNextStop) {
  
};

// Test Constructor bus_data_
TEST_F(BusTests, ConstructorBusData) {
  
};