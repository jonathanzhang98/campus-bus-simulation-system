/**
 * @file concrete_bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/concrete_bus_factory.h"
// #include "src/strategies.h"


ConcreteStrategyA ConcreteBusFactory::s1;
ConcreteStrategyB ConcreteBusFactory::s2;
ConcreteStrategyC ConcreteBusFactory::s3;

// Bus * ConcreteBusFactory::GenerateBus(string id, Route * outbound,
//                     Route * inbound, int busType, double speed) {
Bus * ConcreteBusFactory::GenerateBus(string id, Route * outbound,
                    Route * inbound, double speed) {
  // generate strategy
  time_t theTime = time(NULL);
  struct tm *aTime = localtime(&theTime);
  int hour = aTime->tm_hour;
  int busType = 0;

  std::cout << "~~~~~~~~~~~~~~Current Day, Date and Time is = "
             << asctime(aTime) << "~~~~~~~~~~~~~~" << std::endl;

  if (6 <= hour && hour < 8) {
    busType = ConcreteBusFactory::s1.DoAlgorithm();
    std::cout << "~~~~~~~~~~~~~~We are using Strategy 1~~~~~~~~~~~~~~"
     << std::endl;
  } else if (8 <= hour && hour < 15) {
    busType = ConcreteBusFactory::s2.DoAlgorithm();
    std::cout << "~~~~~~~~~~~~~~We are using Strategy 2~~~~~~~~~~~~~~"
     << std::endl;
  } else if (15 <= hour && hour < 20) {
    busType = ConcreteBusFactory::s3.DoAlgorithm();
    std::cout << "~~~~~~~~~~~~~~We are using Strategy 3~~~~~~~~~~~~~~"
     << std::endl;
  } else {
    busType = 1;
  }

  std::cout << "~~~~~~~~~~~~~~The Bus Type is :" << busType << "~~~~~~~~~~~~~~"
   << std::endl;


  // generate bus
  if (busType == 1)
    return new SmallBus(id, outbound, inbound, speed);
  else if (busType == 2)
    return new RegularBus(id, outbound, inbound, speed);
  else if (busType == 3)
    return new LargeBus(id, outbound, inbound, speed);
  else
    return NULL;
}
