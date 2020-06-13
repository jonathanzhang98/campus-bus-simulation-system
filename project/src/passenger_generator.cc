/**
 * @file passenger_generator.cc
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */

#include "src/passenger_generator.h"

#include "src/passenger.h"

PassengerGenerator::PassengerGenerator(std::list<double> probs,
   std::list<Stop *> stops) {
  generation_probabilities_ = probs;
  stops_ = stops;
}
