/**
 * @file strategies.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_STRATEGIES_H_
#define SRC_STRATEGIES_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
// #include <iostream>
// #include <list>
// #include <string>
// #include <chrono>
// #include <ctime>
// #include <time.h>

// #include "src/small_bus.h"
// #include "src/regular_bus.h"
// #include "src/large_bus.h"
// #include "src/route.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */
class Strategy {
 public:
    // generate int buytype and update strategy statte
    virtual int DoAlgorithm() = 0;

};

class ConcreteStrategyA : public Strategy {
 public:
  int DoAlgorithm() override {
   int bus_type = state;
   state = (state + 1) % 2;
   return bus_type + 1;
  }
 private:
  int state = 0;
};

class ConcreteStrategyB : public Strategy {
 public:
  int DoAlgorithm() override {
   int bus_type = state;
   state = (state + 1) % 2;
   return bus_type + 2;
  }
 private:
  int state = 0;
};

class ConcreteStrategyC : public Strategy {
 public:
  int DoAlgorithm() override {
   int bus_type = state;
   state = (state + 1) % 3;
   return bus_type + 1;
  }
 private:
  int state = 0;
};

#endif  // SRC_STRATEGIES_H_
