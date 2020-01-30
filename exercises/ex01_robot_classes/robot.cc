#include <cmath>
#include <iostream>

#include "robot.h"

void Robot::MoveForward(int distance) {
  position_[0] = position_[0] + distance*cos(direction_angle_);
  position_[1] = position_[1] + distance*sin(direction_angle_);
}

void Robot::Display() {
  std::cout
  << "Pos [" << position_[0] << " " << position_[1] << "]. angle "
  << direction_angle_ << std::endl;
}
