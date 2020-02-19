# Lab08 Testing with Google Test

**_Note: Since we need to recompile multiple times to test, feedback may take 2-5 minutes to generate_**

### Preparing for the Lab

1.  Pull from shared-upstream into your _support-code_ branch.
2.  Merge into _master_.

### Materials

In the labs/lab08_google_tests folder, the class Date has been defined within the files _date.h_ and _date.cc_. A _main.cc_ has also been provided. In this lab, **none of these files need to be modified**. The header and main are provided to you to help determine how to test the class Date. This is one of the major benefits of using a testing framework -- the tests are developed outside of the code.

We have also provided you with sample unit tests in the file _date_unittest.cc_. This is a typical structure in that each class has a designated file that is a collection of unit tests for that class. There might also be a file for _integrated_ tests that involve testing functionality of shared data across classes. There is only one class for this lab, thus we will be using one file.

### Google Test Introduction

A formal testing framework, such as Google Test, provides a powerful and convenient mechanism for testing your code. It does this without requiring you to modify your source code or pollute it with test statements.

Tests primarily consist of a comparison of an expected result to a calculated result. If they match, the test is reported as passed, if not, it reports a fail. For unit tests, you will create a separate test for each class method, which is a collection of statements to compare expected and calculated results based on a variety of input.

**Think carefully about the range of input to a given method to ensure the code is thoroughly tested.** For example, if you were trying to test a function that calculated a fibonacci number, you would want to consider _boundary_ cases such as 1 and 2, some _normal_ cases such as 3 and 8, some _error_ cases such as -1 and 3.6, and then there is 0. Is this an error or do you define it as 0? It could be either, but maybe you need to ask someone how this should be handled. As you are writing tests, you will often reveal ambiguities in the specifications, which is another excellent reason to write code with testing in mind (and even to write requirements with testing in mind)!

For this class, we will be using the Google C++ Testing Framework. For more information please refer to the following link:
https://github.com/google/googletest/blob/master/googletest/docs/primer.md.

To work on your personal machine, please see the google test website for setup: https://github.com/google/googletest.

### Running the tests

We have provided tests for a couple of the methods in the class _Date_. These tests are not sufficient, for the class nor for the methods being tested. As part of the lab, you will be writing more tests. To see how tests work, navigate to the tests folder, compile the tests, then run the executable.

```
cd labs/lab08_google_tests
make
./date_unittest
```

Notice that not all of the tests passed. This is good! It means you found errors in the code before it went out to the customer. You should **_NOT_** fix the errors for this lab -- only write the tests that find the errors.

### Unit Testing <i>class Date</i>

A test might be independent of all other tests in which you instantiate the needed objects in the body of the test. But if you have a lot of tests that use the same objects, it will probably be more efficient to use a _Test Fixture_.

Let's look a little closer at one of these test fixtures:

```
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}
```

Here we see the test named _DaysBetweenTests_ that is part of a set of tests for _DateTest_ (called a _Fixture_ in Google Test). Test fixtures imply using a class built for these tests. In this case, that is the _DateTest_ class at the top of the unit test file.

Notice the syntax of _DateTest_:
- The name _DateTest_ is the first parameter of all the _TEST_F_ tests.
- _DateTest_ inherits from ::testing::Test.
- _SetUp()_ and member variables are _protected_.
- Use the _SetUp()_ method to initialize all of your objects.
- To define a test that uses this setup, define with `TEST_F(DateTest,<InformativeTestName>)`.

For any given test statement, the _EXPECT_EQ_ compares the 2 passed-in parameters and records the test as _pass_ if they are equal, _fail_ if not. There are several conditions that you can test, for example _EXPECT_LT_ will pass if parameter 1 < parameter 2 and _EXPECT_STREQ_ will pass if the given C strings are equal. When you use _EXPECT_XX_, the tests will continue even if they fail. If you use _ASSERT_XX_, the tests will stop executing if the statement fails (i.e. returns False).

>HINT: When you write tests for the project in iteration 2, you will find it convenient to overload operators (e.g. ==, <, >, ...) to compare class objects. For example, rather than having several EXPECT_EQ statements to test individual data member values in a class, we could define `operator==` and compare the objects directly!

Notice that this test consists of multiple statements to test a variety of input to the method. Within the test, we aren't seeing the instantiation of _first_day_ or _last_day_, as this is in the _SetUp()_ of _DateTest_, as mentioned above.

One thing to note is `<< "Some message"` to the right of the _EXPECT_XX_ calls. These messages can be beneficial to add when executing multiple statements within a test. This will tell the tester exactly which of the lines has failed.


#### Things to Think About

- **Test Fixture**: Use a test fixture for testing a class. This simplifies the writing of each test.

- **Assertion Statements**: Unless the program should not proceed if the test fails, use _EXPECT_ not _ASSERT_.

- **Naming**: Use informative names for your tests. These appear in the test report and will help the user to identify which test/method is failing.

- **Messages**: If you have multiple assertions in a single test, then add messages to the assertions/expect fail using `<<` after the comparison.

- **Scope**:  Each test should only test a single method/function. Furthermore, if there is a lot of functionality within that function, it might be appropriate to separate into different tests.

- **Coverage**: Think carefully about what input to use for testing. Make sure you are considering _boundary_ cases, in which input is on the boundary of where output changes (for example, 0 is often on the boundary because positive and negative numbers produce different results). Include _error_ cases too to ensure your method is robust to bad input.

- **Errors**: Make a careful inspection of your tests to ensure you will not be getting false-positives or false-negatives.


## Your Assignment:

Write thorough tests for the Date class. This includes tests which will catch each of the errors injected into the _date.wrong.cc_ file you have been given, but also more comprehensive testing that will catch other errors within the class.

Remember that there are errors in the code and that is okay! Your task today is _not to fix the errors_, only to find them.

You have been given the implementation for _date.cc_, however you do not NEED this file. You should be able to develop your tests from the header alone (and possibly looking at _main.cc_ for some usage examples). What the class can do should be defined in the header, as that is what other teams are relying upon for their own work. We should be (as Google recommends) testing our _public API_, as represented in our header.


### How will you be graded

How good are the tests? To answer this question, we will use [mutation analysis](https://en.wikipedia.org/wiki/Mutation_testing).

First, your tests will be run against the correct implementation of the _date.cc_ file (given to you as _date.correct.cc_). Your tests should all PASS. This is worth 50% of the lab grade. Your tests shouldn't fail if there's nothing wrong!  Any failed test will be removed from the mutant testing described below.

Then, your tests will be run against a set of mutants. Each mutant has one small defect included. For example, one of the documented errors in date.wrong.cc is "Line 71: uses + instead of -". Rather than running your tests on _date.wrong.cc_, we will create a version of _date.cc_ which is correct EXCEPT for this one error. If your tests run and **ANY** test fails, your tests were adequate to find this defect. If your tests pass, they were not sufficient.

We will generate many such mutants. Some of them will be included in the feedback mechanism. Some will not. Your final score will be based on the number of mutants your tests identify, with 50% based on the proportion of mutants your tests identify.

__Below are the mutants that your tests will need to find for the Full Feedback__:

 * __Mutant:__ Dates from GetDate are missing a character
 * __Mutant:__ Some dates don't have leading zeroes
 * __Mutant:__ Today's date month off by one
 * __Mutant:__ Dates from GetUsDate are not in the right format (same as GetDate?)
 * __Mutant:__ operator-: Probably a copy paste error
 * __Mutant:__ Days between calculation seems to be much larger than it should be.
 * __Mutant:__ A test failed on the correct version of the program.Developer thought months should be zero-indexedDates constructed with epoch are about 70 years in the future
 * __Mutant:__ 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59

***Note:*** The assessment will include more mutants, so it is important to test above and beyond those tests above.  You will only need to pass 90% of the mutant tests in the assessment to get full credit.  Partial credit will be awarded for the mutants that are found.

### Help ensuring tests pass on correct version

We've included the correct implementation for you to be able to test against, when you believe your tests are working properly.  To run against the correct implementation, switch _date.cc_ over to the correct version and run the tests:

```
cp date.correct.cc date.cc
make clean
make
./date_unittest
```

If your tests are good, they should pass when run against the correct version.

To revert back to the incorrect version of date.cc:

```
cp date.wrong.cc date.cc
make clean
make
./date_unittest
```

### Feedback and Assessment

For this lab, feedback will be given in two parts due to processing limitations on the grading server.

 * **Lab_08_Basic_Feedback.md** - This feedback file is generated immediately after checking in your code.  It compiles and tests your tests using the correct version of the date.cc.  This represents 50% of your grade.
 * **Lab_08_Full_Feedback.md** - This feedback file is generated multiple times daily through a batch process.  This includes the basic feedback and the mutant testing.  These results will give you a good idea on how you will do on the assessment.  Please review the mutants described above for what things you should be testing for.
 * **Lab_08_Assessment.md** - This file is your assessment for the lab.  It includes the Full Feedback with correct and mutant tests.  It also, however includes additional mutants you need to find, so your tests should be robust to handle other scenerios besides the full feedback mutants.  To get full credit you will need to find 90% of the assessment mutants.  Partial credit will be awarded for the mutants you find.
