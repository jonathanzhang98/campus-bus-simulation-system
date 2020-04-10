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
#include "../src/random_passenger_generator.h"

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

// Test Constructor name_
TEST_F(BusTests, Constructor) {
  //Stop ** all_stops = new Stop *[12];
  Stop ** CC_EB_stops = new Stop *[6];
  Stop ** CC_WB_stops = new Stop *[6];
  std::list<Stop *> CC_EB_stops_list;  
  std::list<Stop *> CC_WB_stops_list;
  
  //Eastbound stops
  Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
  Stop stop_CC_EB_2(1); //student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_EB_4(3, 45, -94); //before transit
  Stop stop_CC_EB_5(4, 46, -95); //st paul 1
  Stop stop_CC_EB_6(5, 47, -96); //st paul 2
  
  //Westbound stops
  Stop stop_CC_WB_1(6, 47, -96); //st paul 2
  Stop stop_CC_WB_2(7, 46, -95); //st paul 1
  Stop stop_CC_WB_3(8, 45, -94); //before transit
  Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_WB_5(10); //student union station
  Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
  
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_EB_stops_list.push_back(&stop_CC_EB_4);
  CC_EB_stops[3] = &stop_CC_EB_4;
  CC_EB_stops_list.push_back(&stop_CC_EB_5);
  CC_EB_stops[4] = &stop_CC_EB_5;
  CC_EB_stops_list.push_back(&stop_CC_EB_6);
  CC_EB_stops[5] = &stop_CC_EB_6;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_4);
  CC_WB_stops[3] = &stop_CC_WB_4;
  CC_WB_stops_list.push_back(&stop_CC_WB_5);
  CC_WB_stops[4] = &stop_CC_WB_5;
  CC_WB_stops_list.push_back(&stop_CC_WB_6);
  CC_WB_stops[5] = &stop_CC_WB_6;
  
  double * CC_EB_distances = new double[5];
  double * CC_WB_distances = new double[5];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;
  CC_EB_distances[2] = 3;
  CC_EB_distances[3] = 10;
  CC_EB_distances[4] = 6;
  
  CC_WB_distances[0] = 6;
  CC_WB_distances[1] = 10;
  CC_WB_distances[2] = 3;
  CC_WB_distances[3] = 4;
  CC_WB_distances[4] = 5;
  
  
  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15); //WB
  CC_EB_probs.push_back(.3); //CMU
  CC_EB_probs.push_back(.025); //O&W
  CC_EB_probs.push_back(.05); //Pre-transit
  CC_EB_probs.push_back(.05); //STP 1
  CC_EB_probs.push_back(0); //STP 1
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35); //stp 2
  CC_WB_probs.push_back(.05); //stp 1
  CC_WB_probs.push_back(.01); //post-transit
  CC_WB_probs.push_back(.01); //O&W
  CC_WB_probs.push_back(.02); //CMU
  CC_WB_probs.push_back(0); //WB
  
  
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  
  Route CC1_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC1_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  Route CC2_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC2_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  
  int cc1_counter = 10000;
  int cc2_counter = 20000;
  
  Bus campus_connector1(std::to_string(cc1_counter), &CC1_EB, &CC1_WB, 60, 1);
  Bus campus_connector2(std::to_string(cc2_counter), &CC2_WB, &CC2_EB, 60, 1);

  // test passenger_max_capacity_
  EXPECT_EQ(campus_connector1.GetCapacity(), 60);
  EXPECT_EQ(campus_connector2.GetCapacity(), 60);

  // test name_
  EXPECT_EQ(campus_connector1.GetName(), "10000");
  EXPECT_EQ(campus_connector2.GetName(), "20000");

  // test passengers_
  EXPECT_EQ(campus_connector1.GetNumPassengers(), 0);
  EXPECT_EQ(campus_connector2.GetNumPassengers(), 0);
  Passenger passenger1(33, "Zoe");
  Passenger passenger2(42, "Kaylee");
  Passenger passenger3(50, "Wash");
  Passenger passenger4(10, "Mal");
  Passenger passenger5(23, "Jayne");

  campus_connector1.LoadPassenger(&passenger1);
  EXPECT_EQ(campus_connector1.GetNumPassengers(), 1);
  campus_connector1.LoadPassenger(&passenger2);
  EXPECT_EQ(campus_connector1.GetNumPassengers(), 2);
  campus_connector1.LoadPassenger(&passenger3);
  EXPECT_EQ(campus_connector1.GetNumPassengers(), 3);


  campus_connector2.LoadPassenger(&passenger4);
  EXPECT_EQ(campus_connector2.GetNumPassengers(), 1);
  campus_connector2.LoadPassenger(&passenger5);
  EXPECT_EQ(campus_connector2.GetNumPassengers(), 2);

  // test next_stop_
  Stop *nextStop1 = campus_connector1.GetNextStop();
  EXPECT_EQ(nextStop1->GetId(), CC_EB_stops[0]->GetId());
  EXPECT_EQ(nextStop1->GetLongitude(), CC_EB_stops[0]->GetLongitude());
  EXPECT_EQ(nextStop1->GetLatitude(), CC_EB_stops[0]->GetLatitude());

  Stop *nextStop2 = campus_connector2.GetNextStop();
  EXPECT_EQ(nextStop2->GetId(), CC_WB_stops[0]->GetId());
  EXPECT_EQ(nextStop2->GetLongitude(), CC_WB_stops[0]->GetLongitude());
  EXPECT_EQ(nextStop2->GetLatitude(), CC_WB_stops[0]->GetLatitude());

  // test bus_data_
  EXPECT_EQ(campus_connector1.GetBusData().id, "");
  EXPECT_EQ(campus_connector2.GetBusData().id, "");
  EXPECT_EQ(campus_connector1.GetBusData().capacity, 0);
  EXPECT_EQ(campus_connector2.GetBusData().capacity, 0);
  EXPECT_EQ(campus_connector1.GetBusData().num_passengers, 0);
  EXPECT_EQ(campus_connector2.GetBusData().num_passengers, 0);
  EXPECT_EQ(campus_connector1.GetBusData().position.x, 0);
  EXPECT_EQ(campus_connector2.GetBusData().position.x, 0);
  EXPECT_EQ(campus_connector1.GetBusData().position.y, 0);
  EXPECT_EQ(campus_connector2.GetBusData().position.y, 0);
};


TEST_F(BusTests, IsTripComplete) {
  //Stop ** all_stops = new Stop *[12];
  Stop ** CC_EB_stops = new Stop *[6];
  Stop ** CC_WB_stops = new Stop *[6];
  std::list<Stop *> CC_EB_stops_list;  
  std::list<Stop *> CC_WB_stops_list;
  
  //Eastbound stops
  Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
  Stop stop_CC_EB_2(1); //student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_EB_4(3, 45, -94); //before transit
  Stop stop_CC_EB_5(4, 46, -95); //st paul 1
  Stop stop_CC_EB_6(5, 47, -96); //st paul 2
  
  //Westbound stops
  Stop stop_CC_WB_1(6, 47, -96); //st paul 2
  Stop stop_CC_WB_2(7, 46, -95); //st paul 1
  Stop stop_CC_WB_3(8, 45, -94); //before transit
  Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_WB_5(10); //student union station
  Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
  
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_EB_stops_list.push_back(&stop_CC_EB_4);
  CC_EB_stops[3] = &stop_CC_EB_4;
  CC_EB_stops_list.push_back(&stop_CC_EB_5);
  CC_EB_stops[4] = &stop_CC_EB_5;
  CC_EB_stops_list.push_back(&stop_CC_EB_6);
  CC_EB_stops[5] = &stop_CC_EB_6;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_4);
  CC_WB_stops[3] = &stop_CC_WB_4;
  CC_WB_stops_list.push_back(&stop_CC_WB_5);
  CC_WB_stops[4] = &stop_CC_WB_5;
  CC_WB_stops_list.push_back(&stop_CC_WB_6);
  CC_WB_stops[5] = &stop_CC_WB_6;
  
  double * CC_EB_distances = new double[5];
  double * CC_WB_distances = new double[5];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 5;
  CC_EB_distances[2] = 5;
  CC_EB_distances[3] = 5;
  CC_EB_distances[4] = 5;
  
  CC_WB_distances[0] = 5;
  CC_WB_distances[1] = 5;
  CC_WB_distances[2] = 5;
  CC_WB_distances[3] = 5;
  CC_WB_distances[4] = 5;
  
  
  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15); //WB
  CC_EB_probs.push_back(.3); //CMU
  CC_EB_probs.push_back(.025); //O&W
  CC_EB_probs.push_back(.05); //Pre-transit
  CC_EB_probs.push_back(.05); //STP 1
  CC_EB_probs.push_back(0); //STP 1
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35); //stp 2
  CC_WB_probs.push_back(.05); //stp 1
  CC_WB_probs.push_back(.01); //post-transit
  CC_WB_probs.push_back(.01); //O&W
  CC_WB_probs.push_back(.02); //CMU
  CC_WB_probs.push_back(0); //WB
  
  
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  
  Route CC1_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC1_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  Route CC2_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC2_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  
  int cc1_counter = 10000;
  int cc2_counter = 20000;
  
  Bus campus_connector1(std::to_string(cc1_counter), &CC1_EB, &CC1_WB, 60, 5);
  Bus campus_connector2(std::to_string(cc2_counter), &CC2_WB, &CC2_EB, 60, 5);

  EXPECT_EQ(campus_connector1.IsTripComplete(), false);

  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  EXPECT_EQ(campus_connector1.IsTripComplete(), false);
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();
  campus_connector1.Move();

  EXPECT_EQ(campus_connector1.IsTripComplete(), true);

}


TEST_F(BusTests, Move) {
  //Stop ** all_stops = new Stop *[12];
  Stop ** CC_EB_stops = new Stop *[6];
  Stop ** CC_WB_stops = new Stop *[6];
  std::list<Stop *> CC_EB_stops_list;  
  std::list<Stop *> CC_WB_stops_list;
  
  //Eastbound stops
  Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
  Stop stop_CC_EB_2(1); //student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_EB_4(3, 45, -94); //before transit
  Stop stop_CC_EB_5(4, 46, -95); //st paul 1
  Stop stop_CC_EB_6(5, 47, -96); //st paul 2
  
  //Westbound stops
  Stop stop_CC_WB_1(6, 47, -96); //st paul 2
  Stop stop_CC_WB_2(7, 46, -95); //st paul 1
  Stop stop_CC_WB_3(8, 45, -94); //before transit
  Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_WB_5(10); //student union station
  Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
  
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_EB_stops_list.push_back(&stop_CC_EB_4);
  CC_EB_stops[3] = &stop_CC_EB_4;
  CC_EB_stops_list.push_back(&stop_CC_EB_5);
  CC_EB_stops[4] = &stop_CC_EB_5;
  CC_EB_stops_list.push_back(&stop_CC_EB_6);
  CC_EB_stops[5] = &stop_CC_EB_6;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_4);
  CC_WB_stops[3] = &stop_CC_WB_4;
  CC_WB_stops_list.push_back(&stop_CC_WB_5);
  CC_WB_stops[4] = &stop_CC_WB_5;
  CC_WB_stops_list.push_back(&stop_CC_WB_6);
  CC_WB_stops[5] = &stop_CC_WB_6;
  
  double * CC_EB_distances = new double[5];
  double * CC_WB_distances = new double[5];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 5;
  CC_EB_distances[2] = 5;
  CC_EB_distances[3] = 5;
  CC_EB_distances[4] = 5;
  
  CC_WB_distances[0] = 5;
  CC_WB_distances[1] = 5;
  CC_WB_distances[2] = 5;
  CC_WB_distances[3] = 5;
  CC_WB_distances[4] = 5;
  
  
  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15); //WB
  CC_EB_probs.push_back(.3); //CMU
  CC_EB_probs.push_back(.025); //O&W
  CC_EB_probs.push_back(.05); //Pre-transit
  CC_EB_probs.push_back(.05); //STP 1
  CC_EB_probs.push_back(0); //STP 2
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35); //stp 2
  CC_WB_probs.push_back(.05); //stp 1
  CC_WB_probs.push_back(.01); //post-transit
  CC_WB_probs.push_back(.01); //O&W
  CC_WB_probs.push_back(.02); //CMU
  CC_WB_probs.push_back(0); //WB
  
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  
  Route CC1_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC1_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  Route CC2_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC2_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  
  int cc1_counter = 10000;
  int cc2_counter = 20000;
  
  Bus campus_connector1(std::to_string(cc1_counter), &CC1_EB, &CC1_WB, 60, 5);

  for (int j = 0; j < 3; j++) {
    Stop *nextStop = campus_connector1.GetNextStop();
    EXPECT_EQ(campus_connector1.Move(), true);
    EXPECT_EQ(nextStop->GetId(), CC_EB_stops[j]->GetId());
    EXPECT_EQ(nextStop->GetLongitude(), CC_EB_stops[j]->GetLongitude());
    EXPECT_EQ(nextStop->GetLatitude(), CC_EB_stops[j]->GetLatitude());
  }

  Bus campus_connector2(std::to_string(cc2_counter), &CC2_WB, &CC2_EB, 60, -10);
  EXPECT_EQ(campus_connector1.Move(), false);
}


TEST_F(BusTests, LoadPassenger) {
  //Stop ** all_stops = new Stop *[12];
  Stop ** CC_EB_stops = new Stop *[6];
  Stop ** CC_WB_stops = new Stop *[6];
  std::list<Stop *> CC_EB_stops_list;  
  std::list<Stop *> CC_WB_stops_list;
  
  //Eastbound stops
  Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
  Stop stop_CC_EB_2(1); //student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_EB_4(3, 45, -94); //before transit
  Stop stop_CC_EB_5(4, 46, -95); //st paul 1
  Stop stop_CC_EB_6(5, 47, -96); //st paul 2
  
  //Westbound stops
  Stop stop_CC_WB_1(6, 47, -96); //st paul 2
  Stop stop_CC_WB_2(7, 46, -95); //st paul 1
  Stop stop_CC_WB_3(8, 45, -94); //before transit
  Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_WB_5(10); //student union station
  Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
  
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_EB_stops_list.push_back(&stop_CC_EB_4);
  CC_EB_stops[3] = &stop_CC_EB_4;
  CC_EB_stops_list.push_back(&stop_CC_EB_5);
  CC_EB_stops[4] = &stop_CC_EB_5;
  CC_EB_stops_list.push_back(&stop_CC_EB_6);
  CC_EB_stops[5] = &stop_CC_EB_6;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_4);
  CC_WB_stops[3] = &stop_CC_WB_4;
  CC_WB_stops_list.push_back(&stop_CC_WB_5);
  CC_WB_stops[4] = &stop_CC_WB_5;
  CC_WB_stops_list.push_back(&stop_CC_WB_6);
  CC_WB_stops[5] = &stop_CC_WB_6;
  
  double * CC_EB_distances = new double[5];
  double * CC_WB_distances = new double[5];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;
  CC_EB_distances[2] = 3;
  CC_EB_distances[3] = 10;
  CC_EB_distances[4] = 6;
  
  CC_WB_distances[0] = 6;
  CC_WB_distances[1] = 10;
  CC_WB_distances[2] = 3;
  CC_WB_distances[3] = 4;
  CC_WB_distances[4] = 5;
  
  
  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15); //WB
  CC_EB_probs.push_back(.3); //CMU
  CC_EB_probs.push_back(.025); //O&W
  CC_EB_probs.push_back(.05); //Pre-transit
  CC_EB_probs.push_back(.05); //STP 1
  CC_EB_probs.push_back(0); //STP 1
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35); //stp 2
  CC_WB_probs.push_back(.05); //stp 1
  CC_WB_probs.push_back(.01); //post-transit
  CC_WB_probs.push_back(.01); //O&W
  CC_WB_probs.push_back(.02); //CMU
  CC_WB_probs.push_back(0); //WB
  
  
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  
  Route CC1_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC1_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  Route CC2_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC2_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  
  int cc1_counter = 10000;
  int cc2_counter = 20000;
  
  Bus campus_connector1(std::to_string(cc1_counter), &CC1_EB, &CC1_WB, 60, 1);
  Bus campus_connector2(std::to_string(cc2_counter), &CC2_WB, &CC2_EB, 60, 1);

  EXPECT_EQ(campus_connector1.LoadPassenger(new Passenger(0)), true);
  for (int i = 0; i < 59; i++) {
    campus_connector1.LoadPassenger(new Passenger(i));
  }
  EXPECT_EQ(campus_connector1.LoadPassenger(new Passenger(61)), false);
}