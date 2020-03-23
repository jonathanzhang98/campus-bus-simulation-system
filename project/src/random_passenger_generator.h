/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"


class Stop;  // forward declaration

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of random passengers.
 *
 * 
 * 
 */
class RandomPassengerGenerator : public PassengerGenerator{
 public:
 /**
  * @brief Randomly generates passengers.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] probs
  * @param[in] stops 
  *
  * @return Constructor does not return anything.
  */
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);

  /**
   * @brief Generate a list of passengers.
   *
   * This function will be used for simulation purposes.
   *
   *
   * @return GeneratePassengers returns the number of passengers generated.
   */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RANDOM_PASSENGER_GENERATOR_H_
