/**
 * @file passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "src/passenger_factory.h"
#include "src/stop.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of passengers.
 *
 * 
 * 
 */
class Stop;  // forward declaration

class PassengerGenerator {
 public:
 /**
  * @brief Generate a PassengerGenerator object.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] probs
  * @param[in] stops
  *
  * @return Constructor does not return anything.
  */
  PassengerGenerator(std::list<double>, std::list<Stop *>);

  /**
  * @brief Generate a list of passengers.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GeneratePassengers returns the number of passengers generated.
  */
  // Makes the class abstract, cannot instantiate and forces subclass override
  virtual int GeneratePassengers() = 0;  // pure virtual

 protected:
  std::list<double> generation_probabilities_;
  std::list<Stop *> stops_;

  // should we be using a singleton here somehow?
  // PassengerFactory * pass_factory;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
