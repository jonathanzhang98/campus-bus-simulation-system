/**
 * @file mainpage.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! \mainpage Bus Simulator
 *
 * \section A Getting started with the Bus Simulator
 * 1. Obtaining the code
 *
 *    All the code that's relavent to the bus simulator is in the project folder.
 *
 *      The src directory contains the source code of all the real-world objects in the simulation.
 *
 *      The web_code directory contains the source code of the server.
 *
 *      The web_graphics directory contains the source code of the client.
 *
 *      The tests directory contains the automated unit testing.
 *
 *      The build directory contains all the target files (.o, exe) generated by the compiler.
 *
 *      The docs directory contains all the documentation files for the simulator.
 *
 * 2. Configuration
 *
 *    In the config directory of the project folder, there's a config.txt file while contains all the information concerning the routes in this simulation.
 *    By modifying the config.txt file, you can add, delete, or modify routes and the stops of these routes.
 *
 * 3. Compilation
 *
 *    Step 1: navigate to the src directory in the project folder in your terminal
 *
 *    Step 2: type the "make" command
 * 
 * 4. Executaion
 *
 *    Step 1: After you successfully compiledd the simulation, you can navigate back to your project directy and run the following command:
 *          ./build/bin/vis_sim <port_number> 
 *          Note: the port_number must be larger than 8000, and the last 3 digits can be chosen randomly
 *      
 *    Step 2: After this, your terminal should be showing the message: "starting server..."
 *
 *    Step 3: Now, you can open your brower can go to the following URL:
 *          http://127.0.0.1:<port_number>/web_graphics/project.html
 *          Note: <port_number> is just the port number you typed in step 1
 *
 *    Step 4: You can then start the simulation by clicking the start button, and while the simulation is running, you can click the pause/resume button to pause or resume the simulation.
 *
 *
 * \section B The Design of Bus Factory
 * The bus factory can be implemented as both a concrete factory or an abstract factory.
 * 
 * A concrete bus factory uses a static function to create and return a bus object, while an abstract factory create an interface for specific concrete factories that will inherite from it.
 * 
 * When comparing to an abstract factory, a concrete bus factory is easier to implements since there is only one class to create in a concrete bus factory. In an abstract factory instead, there are at least 4 classes needed to be created which add some complexities.
 * However, a concrete bus factory cannot provides only one layer of abstraction. It only classify our concrete bus objects in terms of one attribute.
 * 
 * An abstract factory, on the other hand, can classify buses using two different attributes, such as capacity and which campus the bus is in. For example, using an abstract factory, we can differentiate small buses in the Twin Cities campus from small buses in the Duluth campus.
 * Nevertheless, this extra layer of an abstract factory adds much more complexity to the implementation process of it. Typically an abstract factory requires more classes to be implemented to achieve the same functionality of an concrete factory. 
 * 
 * In the context of this simulation, there's no need to an extra layer of complexity since we only need to classify our buses in terms of their capacity. In this case, a concrete bus factory will be much easier to implement and reduces the complexity of our simulation.
 */
#endif  // SRC_MAINPAGE_H_