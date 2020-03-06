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

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Stop *stop, *stop1, *stop2;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    passenger = new Passenger(10, "Darth Vader");
    passenger1 = new Passenger(-3, "3CPO");
    passenger2 = new Passenger(5, "Luke Skywalker");
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    pass_loader = NULL;
    pass_unloader = NULL;
    delete stop;
    delete stop1;
    delete stop2;
    stop = NULL;
    stop1 = NULL;
    stop2 = NULL;
    delete passenger;
    delete passenger1;
    delete passenger2;
    passenger = NULL;
    passenger1 = NULL;
    passenger2 = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
/*
* Test Constructor only for those values that have getters/setters
* 1. id_
* 2. longitude_
* 3. latitude_
* 4. passengers_
*/

// Test Constructor id_
TEST_F(StopTests, ConstructorId) {
    stop = new Stop(1);
    stop1 = new Stop(3);
    stop2 = new Stop(-5);

    EXPECT_EQ(stop->GetId(), 1);
    EXPECT_EQ(stop1->GetId(), 3);
    EXPECT_EQ(stop2->GetId(), -5);
};

// Test Constructor longitude_
TEST_F(StopTests, ConstructorLongitude) {
    stop = new Stop(1);
    stop1 = new Stop(2, 77.32);
    stop2 = new Stop(3, -32.9);

    EXPECT_EQ(stop->GetLongitude(), 44.973723);
    EXPECT_EQ(stop1->GetLongitude(), 77.32);
    EXPECT_EQ(stop2->GetLongitude(), -32.9);
};

// Test Constructor latitude_
TEST_F(StopTests, ConstructorLatitude) {
    stop = new Stop(1, 0);
    stop1 = new Stop(2, 0, 56.11);
    stop2 = new Stop(3, 0, 13.40);

    EXPECT_EQ(stop->GetLatitude(), -93.235365);
    EXPECT_EQ(stop1->GetLatitude(), 56.11);
    EXPECT_EQ(stop2->GetLatitude(), 13.40);
};

// Test Constructor passengers_ 
TEST_F(StopTests, ConstructorPassengers) {
    stop = new Stop(1);
    EXPECT_EQ(stop->GetNumPassengersPresent(), 0);
};