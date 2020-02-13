/**
 * @file main.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */


/*******************************************************************************
  * Includes
******************************************************************************/

#include <iostream>
#include <vector>

#include "passenger.h"


/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main() {

  std::vector<Passenger *> passengers;

  passengers.push_back(new Passenger(33, "Zoe"));
  passengers.push_back(new Passenger(42, "Kaylee"));
  passengers.push_back(new Passenger(50, "Wash"));
  passengers.push_back(new Passenger(10, "Mal"));
  passengers.push_back(new Passenger(23, "Jayne"));


  int time = 0;

  while (time < 60) {

    std::cout << "/***********/" << std::endl;
    //std::cout << "/*         */" << std::endl;
    std::cout << "/* TIME ";
    if (time < 10) { std::cout << "0"; }
    std::cout << time;
    std::cout << " */" << std::endl;
    //std::cout << "/*         */" << std::endl;
    std::cout << "/***********/" << std::endl;

    if (time == 2) {
      passengers[0]->GetOnBus();
    }
    else if (time == 5) {
      passengers[1]->GetOnBus();
    }
    else if (time == 8) {
      passengers[2]->GetOnBus();
    }
    else if (time == 9) {
      passengers[3]->GetOnBus();
    }
    else if (time == 11) {
      passengers[4]->GetOnBus();
    }

    for(std::vector<Passenger *>::iterator it = passengers.begin(); it != passengers.end(); it++) {
      if ((*it)->GetDestination() != time) {
        (*it)->Update();
      }
      else {
        Passenger * departing_passenger = *it;
        departing_passenger->Report();

        //When removing the passenger, the iterator gets incremented to the next element.
        //We need to push it back so that the for loop increment places the iterator at
        // the correct next element.
        it = passengers.erase(it);
        it--;
        delete departing_passenger;
      }
    }

    time++;
  }

  return 0;
}
