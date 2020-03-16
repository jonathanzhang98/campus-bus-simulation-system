/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

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
TEST_F(PassengerTests, Constructor) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
};
