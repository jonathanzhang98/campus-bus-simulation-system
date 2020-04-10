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

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 * 
 */

class Strategy {
 public:
    // generate int buytype and update strategy statte
    virtual int DoAlgorithm() = 0;

};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Strategy Concrete class implements the Strategy interface.
 * 
 */
class ConcreteStrategyA : public Strategy {
 public:
  /**
  * @brief Generate busType base on current state.
  *
  *
  * @return DoAlgorithm return a busType.
  */
  int DoAlgorithm() override {
   int bus_type = state;
   state = (state + 1) % 2;
   return bus_type + 1;
  }
 private:
  int state = 0;
};
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Strategy Concrete class implements the Strategy interface.
 * 
 */
class ConcreteStrategyB : public Strategy {
 public:
 /**
  * @brief Generate busType base on current state.
  *
  *
  * @return DoAlgorithm return a busType.
  */
  int DoAlgorithm() override {
   int bus_type = state;
   state = (state + 1) % 2;
   return bus_type + 2;
  }
 private:
  int state = 0;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Strategy Concrete class implements the Strategy interface.
 * 
 */
class ConcreteStrategyC : public Strategy {
 public:
 /**
  * @brief Generate busType base on current state.
  *
  *
  * @return DoAlgorithm return a busType.
  */
  int DoAlgorithm() override {
   int bus_type = state;
   state = (state + 1) % 3;
   return bus_type + 1;
  }
 private:
  int state = 0;
};

#endif  // SRC_STRATEGIES_H_
