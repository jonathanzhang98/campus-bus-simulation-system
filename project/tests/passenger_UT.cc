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
    delete passenger1;
    delete passenger2;
    passenger = NULL;
    passenger1 = NULL;
    passenger2 = NULL;
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
  EXPECT_EQ(passenger->GetDestination(), -1);

  passenger1 = new Passenger(10);
  EXPECT_EQ(passenger1->GetDestination(), 10);

  passenger2 = new Passenger(-10, "Luke");
  EXPECT_EQ(passenger2->GetDestination(), -10);
};


// Test Constructor wait_at_stop_
TEST_F(PassengerTests, ConstructorWaitAtStop) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  EXPECT_EQ(passenger->IsOnBus(), true);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
  EXPECT_EQ(passenger->IsOnBus(), true);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 3);
  EXPECT_EQ(passenger->IsOnBus(), true);


  passenger1 = new Passenger();
  EXPECT_EQ(passenger1->GetTotalWait(), 0);
  EXPECT_EQ(passenger1->IsOnBus(), false);

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 1);
  EXPECT_EQ(passenger1->IsOnBus(), false);

  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->GetTotalWait(), 2);
  EXPECT_EQ(passenger1->IsOnBus(), true);

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 3);
  EXPECT_EQ(passenger1->IsOnBus(), true);
};

// Test Constructor time_on_bus_
TEST_F(PassengerTests, ConstructorTimeOnBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger->GetTotalWait(), 1);


  passenger1 = new Passenger();
  EXPECT_EQ(passenger1->GetTotalWait(), 0) << "Not initialized to 0";
  EXPECT_EQ(passenger1->IsOnBus(), false) << "Not initialized to 0 (false)";

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 1) << "Not staying 0";
  EXPECT_EQ(passenger1->IsOnBus(), false) << "Not staying 0 (false)"; 

  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->IsOnBus(), true) << "Not changed to true";
  EXPECT_EQ(passenger1->GetTotalWait(), 2);

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 3) << "Not incremented";
  EXPECT_EQ(passenger1->IsOnBus(), true) << "Still not changed to true";
};


// Test Update() wait_at_stop_
TEST_F(PassengerTests, UpdateWaitAtStop) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  EXPECT_EQ(passenger->IsOnBus(), true);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
  EXPECT_EQ(passenger->IsOnBus(), true);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 3);
  EXPECT_EQ(passenger->IsOnBus(), true);
};

// Test Update() time_on_bus_
TEST_F(PassengerTests, UpdateTimeOnBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
  EXPECT_EQ(passenger->IsOnBus(), true);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 3);
  EXPECT_EQ(passenger->IsOnBus(), true);
};



// Test GetOnBus()
TEST_F(PassengerTests, GetOnBus1) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  EXPECT_EQ(passenger->GetTotalWait(), 0);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger->GetTotalWait(), 1);


  passenger1 = new Passenger();
  EXPECT_EQ(passenger1->IsOnBus(), false);
  EXPECT_EQ(passenger1->GetTotalWait(), 0);

  passenger1->Update();
  EXPECT_EQ(passenger1->IsOnBus(), false);
  EXPECT_EQ(passenger1->GetTotalWait(), 1); 

  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->IsOnBus(), true);
  EXPECT_EQ(passenger1->GetTotalWait(), 2);

  passenger1->Update();
  EXPECT_EQ(passenger1->IsOnBus(), true);
  EXPECT_EQ(passenger1->GetTotalWait(), 3);
};

// Test GetOnBus()
TEST_F(PassengerTests, GetOnBus2) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->Update();
  EXPECT_EQ(passenger->IsOnBus(), false);


  passenger1 = new Passenger();
  EXPECT_EQ(passenger1->IsOnBus(), false);

  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->IsOnBus(), true);

  passenger1->Update();
  EXPECT_EQ(passenger1->IsOnBus(), true); 

  passenger1->Update();
  EXPECT_EQ(passenger1->IsOnBus(), true);
};


// Test GetTotalWait()
TEST_F(PassengerTests, GetTotalWait) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2);

  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 3);


  passenger1 = new Passenger();
  EXPECT_EQ(passenger1->GetTotalWait(), 0);

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 1);

  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->GetTotalWait(), 2);

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 3);
};


// Test IsOnBus
TEST_F(PassengerTests, IsOnBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);

  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);


  passenger1 = new Passenger();
  EXPECT_EQ(passenger1->IsOnBus(), false);

  passenger1->Update();
  EXPECT_EQ(passenger1->IsOnBus(), false); 

  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->IsOnBus(), true);

  passenger1->Update();
  EXPECT_EQ(passenger1->IsOnBus(), true);
};


// Test GetDestination()
TEST_F(PassengerTests, GetDestination) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetDestination(), -1);

  passenger1 = new Passenger(8);
  EXPECT_EQ(passenger1->GetDestination(), 8);

  passenger2 = new Passenger(-5, "Luke");
  EXPECT_EQ(passenger2->GetDestination(), -5);
};


// Test Report() name
TEST_F(PassengerTests, ReportName) {
  passenger = new Passenger(10, "Darth Vader");
  passenger1 = new Passenger(-3, "3CPO");
  passenger2 = new Passenger(5, "Luke Skywalker");
  std::string expected_output_0 = "Name: Darth Vader";
  std::string expected_output_1 = "Name: R2-D2";
  std::string expected_output_2 = "Name: Luke Skywalker";

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output0 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger2->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();

  int p0 = output0.find(expected_output_0);
  int p1 = output1.find(expected_output_1);
  int p2 = output2.find(expected_output_2);

  EXPECT_GE(p0, 0);
  EXPECT_EQ(p1, string::npos);
  EXPECT_GE(p2, 0);
};
