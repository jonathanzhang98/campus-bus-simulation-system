### Assessment for Lab 03

#### Total score: _100.0_ / _100.0_

Run on February 04, 09:15:40 AM.


#### Necessary Files and Structure

+ Pass: Check that directory "googletest" exists.

+  _2.5_ / _2.5_ : Pass: Check that directory "labs" exists.

+  _2.5_ / _2.5_ : Pass: Check that directory "labs/lab03_class_basics" exists.

+ Pass: Change into directory "labs/lab03_class_basics".


#### Essential Files Exist

+  _5_ / _5_ : Pass: Check that file "Makefile" exists.

+ Pass: Check that file "Makefile.test" exists.

+  _5_ / _5_ : Pass: Check that file ".gitignore" exists.

+  _5_ / _5_ : Pass: Check that file "point2.cc" exists.

+  _5_ / _5_ : Pass: Check that file "point2.h" exists.

+ Pass: Check that file "point2_unittest.cc" exists.


#### .gitignore set up properly

+  _2.5_ / _2.5_ : Pass: Check that file/directory "cluster" does not exist.

+  _2.5_ / _2.5_ : Pass: Check that file/directory "point2_unittest" does not exist.

+  _2.5_ / _2.5_ : Pass: Check that no files with extension ".o" exist in directory "."

+  _2.5_ / _2.5_ : Pass: Check that no files with extension ".out" exist in directory "."


#### Test that code compiles and creates the exectuable

+  _10_ / _10_ : Pass: Check that make compiles.



+  _5_ / _5_ : Pass: Check that file "cluster" exists.

+  _5_ / _5_ : Pass: Check that file "main.o" exists.

+  _5_ / _5_ : Pass: Check that file "point2.o" exists.


#### Test the correctness of the code using unit tests

+ Pass: Check that make compiles for Makefile:Makefile.test.

    make successful.
    Check point2_unittest exists...OK: result point2_unittest found

+ Pass: Check that file "point2_unittest" exists.

+  _10_ / _10_ : Pass: Check that a GoogleTest test passes.
    passes the test: Point2Test.DistBtwnBothPositive.



+  _10_ / _10_ : Pass: Check that a GoogleTest test passes.
    passes the test: Point2Test.DistBtwnInverses.



+  _10_ / _10_ : Pass: Check that a GoogleTest test passes.
    passes the test: Point2Test.Quadrant.



+  _10_ / _10_ : Pass: Check that a GoogleTest test passes.
    passes the test: Point2Test.QuadrantBorder.



#### Total score: _100.0_ / _100.0_

