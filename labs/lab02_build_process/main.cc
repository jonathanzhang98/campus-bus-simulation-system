//
//  main.cpp
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include <iostream>
#include "mallard_duck.h"
#include "rubber_duck.h"
#include "decoy_duck.h"
#include "mute_quack.h"

#include <vector>

using std::cout;
using std::endl;
using std::vector;

void IntroduceDuck(Duck* duck);
void ShushDuck(Duck* duck);

int main(int argc, const char * argv[]) {

    // Create Ducks
    Duck * steve = new MallardDuck;
    Duck * charles = new RubberDuck;
    Duck * edmund = new DecoyDuck;

    steve->set_name("Steve");
    charles->set_name("Charles");
    edmund->set_name("Edmund");

    Duck ** duck_array = new Duck* [10]; // Make room for 10 ducks
    int duck_count = 0; // This will increase by one everytime we add a
    duck_array[duck_count++] = steve;
    duck_array[duck_count++] = charles;
    //duck_array[duck_count++] = edmund;


    // Introduce all the ducks
    cout << "\nHere we have " << duck_count << " ducks." << endl;
    for (int i = 0; i < duck_count; i++) {
        Duck* current_duck = duck_array[i];
        IntroduceDuck(current_duck);
    }

    // Tell steve to be quiet
    cout << endl;
    ShushDuck(steve);

    // Re-introduce all the ducks
    cout << "\nHere we have " << duck_count << " ducks." << endl;
    for (int i = 0; i < duck_count; i++) {
        Duck* current_duck = duck_array[i];
        IntroduceDuck(current_duck);
    }

    return 0;
}

void IntroduceDuck(Duck* duck) {
    cout << duck->get_name() << " is " << duck->get_description() << " who says: ";
    duck->PerformQuack();
}

void ShushDuck(Duck* duck) {
    cout << "\"Shhhh, " << duck->get_name() << "!\"" << endl;
    duck->set_quack_behavior(new MuteQuack);
}
