//
//  main.cc
//
//  Created by Amy C. Larson on 1/16/19.
//  Copyright (c) 2019 Amy C. Larson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>

#include "delivery.h"
#include "overnight.h"
#include "ground.h"
#include "twoday.h"
#include "object.h"

// A helper function that passes by value.
void Process(Delivery delivery) {
  std::cout << "Processing the package for delivery." << std::endl;
}

// A helper function that passes a pointer (essentially, pass by reference)
void ProcessPointer(Delivery * delivery) {
  std::cout << "Processing the pointer to the package." << std::endl;
}

// Helper Function Declarations (defined below)
void RunStaticDemo();
void RunPointerDemo();
void RunMemoryDemo();

// Static Class Variable initialization
int Delivery::delivery_count_ = 0;
int Object::object_count_ = 0;

// ./delivery must be executed with 1 of 3 arguments: static, pointer, memory
int main(int argc, char * argv[]) {
  if (1 == argc) {
    std::cout << "No arguments given." << std::endl;
    return 0;
  }
  std::string demo(argv[1]);
  if (0 == demo.compare("static")) {
    RunStaticDemo();
    return 0;
  }
  if (0 == demo.compare("pointer")) {
    RunPointerDemo();
    return 0;
  }
  if (0 == demo.compare("memory")) {
      RunMemoryDemo();
      return 0;
  }
  std::cout << "Command line argument " << demo << " not recognized.";
  std::cout << std::endl;
}

void PrintCount() {
  std::cout << std::endl;
  std::cout << "I have " << Delivery::get_count() << " deliveries to make.";
  std::cout << std::endl << std::endl;
}

void RunStaticDemo() {
  // *****   THIS LOOKS AT POLYMORPHISM AND STATIC ARRAYS   ******* //
  std::cout << std::endl << std::endl;
  std::cout << "______  CREATING ARRAY AND SPECIAL DELIVERY _______";
  std::cout << std::endl;
  Delivery deliveries[4];
  Delivery special_delivery;

  PrintCount();

  std::cout << "______  ASSIGNING ARRAY _______" << std::endl;
  deliveries[0] = Overnight("Very Important Package!");
  deliveries[1] = Ground("your average package.");
  deliveries[2] = TwoDay("Kind of important.");

  PrintCount();

  std::cout << "______  PROCESSING DELIVERIES _______" << std::endl;
  // This function call will highlight the need for a copy constructor.
  Process(special_delivery);
  Process(special_delivery);

  PrintCount();

  std::cout << "______  REPORTING ON DELIVERIES _______" << std::endl;
  // How does it look? Everything as it should be? No, it isn't!
  for (int i = 0; i<4; i++) {
    std::cout << std::endl;
    std::cout << "Delivery #" << i+1 << "..." << std::endl;
    deliveries[i].Transport();
    deliveries[i].Deliver();
  }
  std::cout << std::endl;
  std::cout << "Special Delivery" << "..." << std::endl;
  special_delivery.Transport();
  special_delivery.Deliver();
  std::cout << std::endl;
}

void RunPointerDemo() {

  // *******   OKAY, Let's try polymorphism with Dynamic Allocation **** //
  std::cout << std::endl << std::endl;
  std::cout << "______  CREATING ARRAY OF POINTERS OF DELIVERIES _______" << std::endl;
  Delivery * more_deliveries[4];
  more_deliveries[0] = new Overnight("Very Important Package!");
  more_deliveries[1] = new Ground("your average package.");
  more_deliveries[2] = new TwoDay("Kind of important.");
  more_deliveries[3] = new Delivery;

  // This function call will highlight the need for a copy constructor.
  Process(*more_deliveries[0]);
  ProcessPointer(more_deliveries[0]);

  // How is this looking? Better, but what about the days?
  PrintCount();

  for (int i = 0; i<4; i++) {
    std::cout << std::endl;
    std::cout << "Delivery #" << i+1 << "..." << std::endl;
    more_deliveries[i]->Transport();
    more_deliveries[i]->Deliver();
  }
}

// A helper function that creates objects dynamically
void ReadyForTransport(Object ** dynamic, Object ** local ) {
  // A function to help demonstrate memory leaks and dangling pointers.

  std::cout << "Entered ReadyForTransport()." << std::endl;
  std::cout << "Objects have an array of 2 overnight deliveries" << std::endl;
  std::cout << "About to create dynamic object." << std::endl;
  *dynamic = new Object;
  std::cout << std::endl;
  std::cout << "About to create local object." << std::endl;
  Object local_object;
  std::cout << std::endl;
  std::cout << "About to copy local object into passed object." << std::endl;
  *local = &local_object;
  std::cout << "When uncommented, about to delete." << std::endl;
  // delete *dynamic;
  // delete dynamic;
  // delete *local;
  // delete local;
}

void RunMemoryDemo() {
  std::cout << std::endl << std::endl;
  std::cout << "______  EXPLORING MEMORY MANAGEMENT _______" << std::endl;

  Object * dyn_object = NULL;
  Object * local_object = NULL;

  // ******  NOW, Let's see what happens when we manage memory poorly
  for (int i=0; i<2; i++) {
    ReadyForTransport(&dyn_object, &local_object);
    std::cout << std::endl;
    std::cout << "Returned from ReadyForTransport()" << std::endl;
    std::cout << "dyn address " << dyn_object->get_address() << std::endl;
    std::cout << "local address " << local_object->get_address() << std::endl;
    std::cout << "dyn_object address " << (int64_t) dyn_object << std::endl;
    std::cout << std::endl;
  }
  // delete dyn_object;
  // delete &dyn_object;
  // delete local_object;
  // delete &local_object;
}
