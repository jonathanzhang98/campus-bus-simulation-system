# Lab 13 - Assembling a regression test for the domain classes (Passenger, Bus, Stop, and Route) used by vis_sim

  The purpose of this lab is to have you assemble and run a regression test that can be used to test your succesive versions 
of __vis_sim__.  As noted in the iteration 2 requirements specification, the goal of regression tests is to 
verify that features in your simulation that were already working continue to work, even as you add the new functionality
(that is, code). 

  The regression test you will assemble and run in this lab can also be used as a basis for creating another regression 
test.  __To get full credit for regression testing in iteration 2, you should create (and deliver) at least ONE other 
working regression test - that is in some way different than the one provided in this lab (lab 13).__ _We will provide more 
guidance on this below._ 

  In this lab we will give you the components necessary to create a regression test that you can use to test the successive versions of your simulation to ensure the domain classes (Bus, Stop, Passenger, Route - and all the other functionality in the files in the project/src directory that have NOT been replaced by functionality in files used to create the regression test) produce the results you expect them to produce.  Each time you make changes files / functionality used by the visual simulation, you should recompile and re-run the regression tests (and unit tests) to ensure the non-visual portion of the simulation (i.e, the transit simulation) functions as you expect it to function. As noted above, regression tests are very valuable during the development process,
but even if you have finished development, running regressions test on the components of your simulation that 
have changed during development can help detect issues you have not yet uncovered, and
increase your confidence in your software if the regression test does not expose any issues.

  The regression test you will assemble consists of the original scenario provided with __vis_sim__ in 
iteration 1 (it uses the same inbound and outbound routes and stops that were defined in _config.txt_, however, the stops and routes for a single route  are hardcoded in the version of the
local_simulator_file ( __r_local_simulator.cc__ and __r_local_simulator.h__ ) which we provide in this lab.
The aforementioned __r_local_simulator__ files and the file __regression_driver.cc__ replace the __visualization_simulator__ files in
the regression test - and, note, the visualization components are **NOT** part of the regression test - so the control panel and map functionality
is not available. Once assembled, the regression test you create in this lab will produce the same output each time
it is executed (**once you make some changes to the passenger_factory.cc that we will discuss later**). 

   The lab 13 regression test uses many of the same classes and functionality as __vis_sim__ -  but not all of the same classes
and functionality. Thus, the lab 13 regression test will only test the classes and functionality in the files that it _shares_ with  __vis_sim__. 
Note that the following files do not share classes and functionality with __vis_sim__ and are part of only the regression test.
We are providing these new files to you so that you can create the lab 13 regression test:

* regression_driver.cc
* simulator.h
* r_local_simulator.h
* r_local_simulator.cc
* rtest_passenger_generator.h
* rtest_passenger_generator.cc

We have also provided an updated version of:

* passenger_factory.cc 

The methods in this new *passenger_factory.cc* can be configured to work in random or deterministic (repeatable) mode using a MACRO.

#### Creating the Lab 13 regression test executable

To create the regression test executable, perform the following steps with the files in the lab 13 folder:

1) Copy the file **regression_driver.cc** into your _project/drivers_ directory

2) Copy the files: **simulator.h, r_local_simulator.h, r_local_simulator.cc, rtest_passenger_generator.h, rtest_passenger_generator.cc**, and 
**passenger_factory.cc** into your _project/src_ directory

3) The makefile in your _project/src_ directory should have the following target: **%_test**

  Provided it does, you can create the regression test driver using your makefile as shown in step 4 below:

4) In your project/src directory, type the following on a command line: **make regression_test**

  If your make executes successfully, your regression test driver executable will be a file named: *regression_test* in the directory: _project/build/bin_. 

  _If your makefile in the _project/src_ directory does **not** successfully create an executable file named *regression_test* in the _project/build/bin_ directory, 
  contact a TA for help_
  
> If the error you're getting after running make is related to your factory implemetation, feel free to modify the regression test code to match your implementation.

5) Next, change directory to the _project/build/bin_ directory.  Then run the regression test twice, piping each output to a different output file as such:

  a) ./regression_test > rtout1
  
  b) ./regression_test > rtout2
  
6) Compare the output of rtout1 and rtout2 by checking for differences between the two files (normally, there should not be any differences).

  You can do this by typing the following command on the terminal command line: *diff rtout1 rtout2*

**What happened?** If there is output, the output files produced by two successive runs of the regression_test executable are not the same - which means either the test failed or the test is not working correctly.
_In this case, the test is not working correctly because the methods in the file *passenger_factory.cc* are still using random behavior! Therefore, there is output._

To change that, change directory to _project/src_ and edit the file **passenger_factory.cc**. 

Find the macro directive:

**#define CONSTPASS 1** 

near the top of the file - it is commented out.

Uncomment the directive **#define CONSTPASS 1**, and save the file. 

Then recompile the regression test driver by typing: **make regression_test** at the terminal command line.

7) Finally, change directory to _project/build/bin_ and repeat steps 5 and 6 above.  

When you type the command: *diff rtout1 rtout2* on the terminal command line, it should not produce any ouput to the terminal.  

  If that is the case, congratulations, you have a regression test that you can use for iteration 2 in place!
  
  If that is not the case, talk to a TA.
  
8) **NOTE: To restore the random generation of passengers** in the excutable versions *visual simulator (vis_sim)* or the *regression_driver (regression_test)* you will have
to manually edit the file: **passenger_factory.cc**, comment out the macro definition that you uncommented in step 6 (**define CONSTPASS 1**)
and *make vis_sim* or *make regression_test*

#### Discussion and building your own regression test for iteration 2 (if you haven't already done so). 

You should inspect the files that we gave you to see how we have changed them from the files that they were based upon (and that we provided for you)
by running the **diff** command on them.  Specifically, you should review the differences between the following file pairs:

* **regression_driver.cc** and **web_code/web/main.cpp**
* **r_local_simulator.h** and **visualization_simulator.h**
* **r_local_simulator.cc** and **visualization_simulator.cc**
* **rtest_passenger_generator.h** and **random_passenger_generator.h**
* **rtest_passenger_generator.cc** is based upon **random_passenger_generator.cc**

and finally, review the use of the MACRO to enable random or deterministic (repeatable) behavior at compile time in the file:
* **passenger_factory.cc**

You can use the techniques and concepts illustrated by the lab 13 regression test driver to create your own test driver for iteration 2 
(REMEMBER YOU NEED TO CREATE AT LEAST ONE REGRESSION TEST THAT DIFFERS FROM THE LAB 13 VERSION AND INCLUDE IT IN YOUR FINAL DELIVERABLES FOR ITERATION 2). 

Some possible ideas for creating your iteration 2 regression test are as follows:

1) You could create new versions of the lab 13  **r_local_simulator** files (.h and .cc) that use a subsets of hardcoded stops used by the aforementioned files so that your regression test runs faster than the one you created for this lab.  

Then create a new regression test driver (named something like my_regression_driver.cc) that uses the new versions of the r_local_simulator files, compile it, and test it out! To make your new regression test,  'make my_regression_test' from the project/src directory (Note: my_regression_driver.cc is just an example name - you are free to use a name that makes more sense to you - but remember, your graders have to know it is the regression test you created for iteration 2).

2) You could create a new version of all of the lab 13 files (**with the exception of simulator.h and passenger_factory.cc**). The files would use a new version the passenger generator that adds a constant number
of passengers at each stop each time passengers are generated in a different way that the lab 13 regression test does (for example, each stop adds stop_id + 1 passengers each time a generation takes place)

Then create a new regression test driver (named something like: my_regression2_driver.cc) that uses the new versions of the files , compile it, and test it out! To make your new regression test,  'make my_regression2_test' from the project/src directory (Note: my_regression2_driver.cc is just an example name - you are free to use a name that makes more sense to you - but remember, your graders have to know it is the regression test you created for iteration 2).

3) There are many more possible approaches that you may pursue if you are comfortable doing so. 

If you have already created a regression test that 
is different from the lab 13 regression test provided by this lab, **Congratulations**, you have already met the requirements for iteration 2. 

If not, hopefully this
lab will help you create your own version of the regression test for iteration 2, and you have fun and be successful in doing so!




