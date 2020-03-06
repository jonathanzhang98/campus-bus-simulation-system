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
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;

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
* 1. name_
* 2. stops_
* 3. route_data_
* 4. destination_stop_
* 5. 
*/

// Test Constructor
TEST_F(RouteTests, Constructor) {
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
  
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);

  // test name_
  EXPECT_EQ(CC_EB.GetName(), "Campus Connector - Eastbound");
  EXPECT_EQ(CC_WB.GetName(), "Campus Connector - Westbound");

  // test stops_
  std::list<Stop *> outputList1 = CC_EB.GetStops();
  int i = 0;
  for (std::list<Stop *>::iterator it = outputList1.begin();
                                        it != outputList1.end(); it++) {
    EXPECT_EQ((*it)->GetId(), CC_EB_stops[i]->GetId());
    EXPECT_EQ((*it)->GetLongitude(), CC_EB_stops[i]->GetLongitude());
    EXPECT_EQ((*it)->GetLatitude(), CC_EB_stops[i]->GetLatitude());
    i++;
  }

  std::list<Stop *> outputList2 = CC_WB.GetStops();
  i = 0;
  for (std::list<Stop *>::iterator it = outputList2.begin();
                                        it != outputList2.end(); it++) {
    EXPECT_EQ((*it)->GetId(), CC_WB_stops[i]->GetId());
    EXPECT_EQ((*it)->GetLongitude(), CC_WB_stops[i]->GetLongitude());
    EXPECT_EQ((*it)->GetLatitude(), CC_WB_stops[i]->GetLatitude());
    i++;
  }

  // test destination_stop_
  Stop *outputDestination1 = CC_EB.GetDestinationStop();
  EXPECT_EQ(outputDestination1->GetId(), CC_EB_stops[0]->GetId());
  EXPECT_EQ(outputDestination1->GetLongitude(), CC_EB_stops[0]->GetLongitude());
  EXPECT_EQ(outputDestination1->GetLatitude(), CC_EB_stops[0]->GetLatitude());

  Stop *outputDestination2 = CC_WB.GetDestinationStop();
  EXPECT_EQ(outputDestination2->GetId(), CC_WB_stops[0]->GetId());
  EXPECT_EQ(outputDestination2->GetLongitude(), CC_WB_stops[0]->GetLongitude());
  EXPECT_EQ(outputDestination2->GetLatitude(), CC_WB_stops[0]->GetLatitude());

  // test route_data_
  EXPECT_EQ(CC_EB.GetRouteData().id, "");
  EXPECT_EQ(CC_WB.GetRouteData().id, "");
  int outputSize1 = CC_EB.GetRouteData().stops.size();
  int outputSize2 = CC_WB.GetRouteData().stops.size();
  EXPECT_EQ(outputSize1, 0);
  EXPECT_EQ(outputSize2, 0);

  // test GetTotalRouteDistance()
  int totalSize1 = 0;
  for (int j = 0; j < 5; j++) {
    totalSize1 += CC_EB_distances[j];
  }
  int totalSize2 = 0;
  for (int j = 0; j < 5; j++) {
    totalSize2 += CC_WB_distances[j];
  }
  EXPECT_EQ(CC_EB.GetTotalRouteDistance(), totalSize1);
  EXPECT_EQ(CC_WB.GetTotalRouteDistance(), totalSize2);

  // test GetNextStopDistance()
  EXPECT_EQ(CC_EB.GetNextStopDistance(), 0);
  EXPECT_EQ(CC_WB.GetNextStopDistance(), 0);
};


TEST_F(RouteTests, IsAtEnd) {
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
  
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);

  EXPECT_EQ(CC_EB.IsAtEnd(), false);

  CC_EB.NextStop();
  CC_EB.NextStop();
  CC_EB.NextStop();
  CC_EB.NextStop();
  CC_EB.NextStop();
  CC_EB.NextStop();

  EXPECT_EQ(CC_EB.IsAtEnd(), true);

  EXPECT_EQ(CC_WB.IsAtEnd(), false);

  CC_WB.NextStop();
  CC_WB.NextStop();
  EXPECT_EQ(CC_WB.IsAtEnd(), false);
  CC_WB.NextStop();
  CC_WB.NextStop();
  CC_WB.NextStop();
  EXPECT_EQ(CC_WB.IsAtEnd(), false);
  CC_WB.NextStop();

  EXPECT_EQ(CC_WB.IsAtEnd(), true);
}