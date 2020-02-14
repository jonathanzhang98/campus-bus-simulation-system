#include "passenger.h"

#include <iostream>
#include <string>


int Passenger::count_ = 0;

//Passenger::Passenger(Stop * dest = NULL, std::string name = "Nobody") {
Passenger::Passenger(int destination_stop_id, std::string name): name_(name), destination_stop_id_(destination_stop_id), wait_at_stop_(0), time_on_bus_(0), id_(count_) {
  count_++;
}

void Passenger::Update() {
  wait_at_stop_++;
}

void Passenger::GetOnBus() {
  time_on_bus_ = 1;
}

int Passenger::GetTotalWait() const {
  return wait_at_stop_;
}

bool Passenger::IsOnBus() const {
  return false;
}

int Passenger::GetDestination() const {
  return destination_stop_id_;
}

void Passenger::Report() const {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Destination: " << destination_stop_id_ << std::endl;
  std::cout << "Total Wait: " << GetTotalWait() << std::endl;
  std::cout << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  std::cout << "\tTime on bus: " << time_on_bus_ << std::endl;
}
