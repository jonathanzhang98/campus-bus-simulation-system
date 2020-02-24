# Base Version of the Transit Simulation Project for 3081W

This lab provides you with the base code (Initial Version) of the transit simulator project for 3081W this semester. The objective of this lab is to get you oriented with the visual version of the transit simulation that you will be working with and on quite a bit for the rest of the semester!

---

### Resources

You will need to refer to these as you work on the project.

- Google Style Guide : https://google.github.io/styleguide/cppguide.html
- cpplint : https://github.com/google/styleguide/tree/gh-pages/cpplint

### Directory Structure

The directory structure for this lab is identical to that of the project.

- `project`:
   - directory that contains all the project subdirectories. The project subdirectories contain the source code, tests, executables, configuration file, and documentation for the transit simulator project.

- `project/src`:
  - Most of the source code (.cc AND .h files) for the transit simulation portion of the project is located here.

- `project/src/makefile`:
  - Used to create the simulation executable and executable 'driver' programs  that can be used to regression test individual components .
  - Type `make` to create the visual simulation in  `build/bin/vis_sim.exe`
  - Type `make <classname>_test` to make executables that tests (that is "drives" each of the major entitites being simulated by the transit simulation (substitute the name bus, stop, passengers, or route for **<classname>** to make the driver executable. For example, `make bus_test` will create the bus_test in the `project/build/bin` directory/folder.
  - Type `make check-style-cse` to run cpplint on the class header (\*.h) and class implementation files (\*.cc) in the `project\src` directory
  - Type `make clean` to remove all existing object, executable, and test files

- `project/build`: Created by the Makefiles. **Make sure it is in your `.gitignore` file in the `project` directory.**
  - `bin`: All executables generated for the project will reside in this directory
   - **NOTE: Do not push the build folder to your repo**

- `project/drivers`: Contains the source code with the main function that is used to create the driver files for each of the major entitites being simulated by the transit simulation (substitute the name bus, stop, passengers, and route)

- `project/web_code/web`: C++ source code for the web server used to enable communication between the visualization component of the vis_sim and the portion of the simulation that simulates the operation and activities of busses, passengers, stops and routes

- `project/web_graphics`: HTML / CSS / and JavaScript code used by your browser - When loaded by the browser with the web-server running, it enables you to configure and run the transit simulation from your browser.

- `project/tests` : directory where you will create and build your unit tests using google test.

- `project/config` : contains the file config.txt used to specify the bus routes used by the transit simulation.

---

## Getting Started

1. _pull_  new code into your support-code branch on your repo.

2. _merge_ the new lab code into your master branch.

3. _cd_ (change directory) in  to the `project` directory.

4. Copy your Doxyfile from Lab 7 into the  `project/docs` directory : `cp ../labs/lab07_style_doxy/docs/Doxyfile ./docs`

5. Copy your `mainpage.h` from Lab 7 into the  `project/src` directory : `cp ../labs/lab07_style_doxy/src/mainpage.h ./src`

---

## Code Explanation

What is given here is a working version of a transit simulation.  This a starting point for your work this semester, improving and extending the functionality of the Transit Simulation. We have also provided test drivers for the passenger, stop, bus and route classes which you should create and run to familiarize yourself with the major entities being simulated by the transit simulation. The test drivers are *not* Google Tests, but rather simple driver applications which run the classes through a couple of simple tasks, basically a working check to ensure that these classes still perform as expected when you make changes to the simulation (assuming you have unit tested them by building Google Unit Tests to do so).

---

## The Lab Assignment

### Build the visulization transit simulation executable and run it

---

1. Open the **README.md** file in the `project` directory.

2. Follow the instructions labeled: **Step by step instructions for CSE Labs machines or vole users**

3. Click on the button named **Start** below the *Run* label

4. When the simulation completes, close your browser, and scroll through the output on the terminal window where you executed (ran) the web server.   After you have seen enough, press `<ctrl> + c` to terminate the web server

5. Next, in the **README.md** file in the `project`, follow the instructions labeled: **To Compile and Run Unit Tests created with Google Test**.

6. Review the file `passenger_UT.cc`, it is a (mostly-empty) template for the Unit tests you will be writing later on!

---

Push your code up to your repository for feedback (don't forget to add the new files and commit before pushing...).

---


### Note on feedback regeneration

To trigger a feedback regeneration for this lab, you must modify a (any) file in `labs/lab09_project_intro`.

The feedback server looks for changes in that folder and only regenerates if something within it has changed. Since the work for this lab will be done in `/project`, it will not regenerate automatically when you change files in that directory.

I would recommend that you just make a trivial change to the this file (e.g. add a word) to trigger the feedback regeneration!


---


### OPTIONAL documentation

Read and add to the documentation (by making your header files Doxygen compliant, and writing self-documenting code in the `*.cc` files) for the c++ code (`*.h` and `*.cc` files) we have provided to you in the `project/src` directory. You should read and add to the documentation and figure out how use Doxygen to generate documentation from the header files in the `project/webcode/web` directory.  For the project, all the code you submit should be well-documented, and every header file should be commented using Doxygen, so get into the habit of making your code Doxygen compliant and self-documenting.

### Congratulations, you have started the Csci3081 project for Spring 2020!!
