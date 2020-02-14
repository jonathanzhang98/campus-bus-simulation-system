## Lab 7 - Google Style Guide Compliance and Doxygen

**_Note: cpplint.py is a bit slow on some of the CSE Lab machines.  Please refer to [Option #1 below](#alternative-options-for-running-cpplintpy) for a solution._** You can use the other provided options, but you are encouraged to use Option #1.

### Part 1 - Google Style Compliance: Linting

https://google.github.io/styleguide/cppguide.html

A style guide sets guidelines for how files, classes, functions, and variables
should be named. It also sets guidelines for white space, line lengths, and
commenting within the code. By standardizing naming conventions and layout, it
is easier to integrate code from various programmers in a cohesive way that
is readable and understandable by everyone. Going forward, all code submitted
for this course must be compliant with the Google Style Guide. As stated before,
not everyone is going to agree on every style rule aesthetically, but it is
important to have a standard that everyone programs to.

The code we have provided you in src directory is _somewhat_ style-compliant.
There are still a few compliance errors in the various files for you to find
and fix. Be sure to check out the files which do NOT have errors for guidance
on how to fix the files which do have the errors.

To fix the errors, you will first need to identify them with _cpplint_. The
_cpplint.py_ file is available on CSE labs machines. To run the linter on your
code, navigate to src directory and do the following:

```
cpplint.py main.cc
```

OR

```
cpplint.py --root=.. *.h
cpplint.py *.cc
```

Invoking the linter on the headers and source files separately is not required,
but when you first start, if there are a lot of errors then you won't have to
scroll back up through screenfulls of text to see where they are. For all-in-one
do:

```
cpplint.py --root=.. *.h *.cc
```

**_What does "--root=.." mean?_** Header guards must always be in place for header
files. During compilation, particularly when you have circular references in your
code, a header file might be included multiple times from multiple header files.
If you have already included the header during compilation, you don't want the
compiler to include it again, thus you are _guarding_ against including it multiple
times (possibly infinite if circular references exist). Google Style states that
header guards should use the full path to that file. The _--root_ flag
allows us to specify where in the path to start.

When you run the linter, you should get a report of each error that includes the
file, line number, and a short description of the problem. If you need guidance
in what is expected, you can consult the Style Guide:
https://google.github.io/styleguide/cppguide.html. Notice that the errors range
from the placement of braces to the use of the keyword `explicit` to commenting.

If you want to run the linter on your local copy on your personal machine, you
will need to download cpplint from the repository:
https://github.com/google/styleguide. Note that this will not be supported by
the instructional staff, nor is it sufficient. Your code must pass the linter on
a CSELabs machine. If you are working on your own machine, it
is recommended that you install with the python installation tool _pip3_, which
might need to be installed (but probably not if you have python3 -- type `pip3
--version` to verify), then install cpplint with `pip3 install cpplint`.

As part of assessment, all files in the **src** directory will be run through cpplint. Make
sure your code has 0 errors when you submit.

### Alternative Options for Running cpplint.py

It has come to our attention that cpplint.py is running quite slow on the lab machines,
so we have compiled a few practical options to help speed things up.

1. **Use cpplint-cse.sh in CSE Labs** - We included a CSE Labs script that will take advantage
of the local system storage to speed up cpplint.py.  This is available by pulling the support-code into your repository (https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream/tree/support-code/cpplint):

      ```git pull upstream support-code```

      To use, you simply replace cpplint.py with the path to cpplint-cse.sh (be sure to always include the **--root=** option).
      Here are a couple of examples:

     ```bash
     # Example usage
     cd src
     ../../../cpplint/cpplint-cse.sh --root=.. main.cc

     #Another example
     ../../../cpplint/cpplint-cse.sh --root=.. *.cc
     ```

2. **Run on your local machine** - You could install from instructions above, but just in case
you have trouble installing cpplint.py, we included it in the support-code here:
https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream/tree/support-code/cpplint.

You may need to install cpplint as follows:

   ```bash
   pip install cpplint
   cpplint --root=.. main.cc
   ```

Otherwise you could try the following

    ```bash
    # Example usage
    cd src
    ../../../cpplint/cpplint.py --root=.. main.cc
    ```
3. **SSH into Apollo or Atlas** - These machines do not appear to have the network storage
issue that is slowing down cpplint.py in other labs (i.e. KH 1-250)





### Part 2 - Doxygen

Now that your code is Google style compliant, the next part of this lab is to
generate documentation and UML for the code. This is done via Doxygen.

According to their official website,
> Doxygen is the de facto standard tool for generating documentation from
> annotated C++ sources, but it also supports other popular programming languages
> such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and
> UNO/OpenOffice flavors), Fortran, VHDL, Tcl, and to some extent D.

Notice how the class PassengerFactory in passenger_factory.h has a description above the
class definition. Doxygen makes use of this to generate documentation for this
class. Doxygen also generates documentation for all functions of a class.

NOTE: Students working on their personal machines will have to download the
doxygen executable before continuing. CSE labs machines already have doxygen
installed.

1. Create the configuration file.
  To start generating documentation, you must first generate a Doxygen
  configuration file in the docs directory. Run the following command from the
  lab07 directory.

  ```
  mkdir docs
  doxygen -g docs/Doxyfile
  ```

  You will now see a new file **Doxyfile** in the docs directory.

2. Modify the Doxyfile to look in the _src_ folder when compiling. You can do
   this by setting the **INPUT** tag of your **Doxyfile** to point to src.

   ```
   ../src
   ```
   Also, to generate the UML, set the **UML_LOOK** and **HAVE_DOT** tag to **YES**.

   The path is relative to the directory from which you run/compile the doxygen. It is important that you set it up to run from docs, because that is where the grading scripts will run from. Doxygen will not inform you if it does not find the src directory -- it just won't generate any files from your classes.

3. Generate the html pages for this lab. Run the following commands:
  ```
  cd docs
  doxygen Doxyfile
  ```

  You can now view the generated documentation from the index.html file in the
  **html** directory that was generated inside the docs folder. Open the index.html page which is refered to as the landing page. Explore the various menus to see how the comments in the code are organized in the html. Click on the classes and you will see UML-like diagrams showing the relationship between classes. One missing piece is a general overview of the code, which you want in the landing page. Currently it is blank because there is no mainpage.h
  file in your src directory.

4. Create a home page for the project. In your _src_ directory, create a file
   **mainpage.h** and paste the following in it.

  ```
  /*! \mainpage My Personal Index Page
   *
   * \section intro_sec Introduction
   *
   * This is the introduction.
   *
   */
 ```

  Generate documentation again by running doxygen as you did before from the
  docs directory and notice how you now have a landing page for your project.

 5. Edit the mainpage.h file by giving it a title and write a
    sentence for the introduction.

 6. Now modify the Passenger.h files to add Doxygen comments and see how that gets added to the documentation. Follow the commenting style that you see in passenger_factory.h. **Use @brief** to describe the class and at least one of the class methods.

   When you have created this documentation (you only need the _.h_
   file), run it again and see how it appears in the class list. Click on the
   class and you will see more detailed information.

7. **Set .gitignore so that you are not pushing the html and latex folders** to your repo. These take a lot of space and can be generated from the Doxygen file, thus there is no need to have them in your repo. You can do this by appending the following entries to your `.gitignore` file:
      - `/docs/html/*`
      - `/docs/latex/*`

 **IMPORTANT**: Make sure you run another Google style check before you make your
 final submission.
 
 **IMPORTANT**: In future project iterations, proper code style and documentation is worth 50% of the grade. Therefore, it is imperative that you understand how to use both cpplint and doxygen!
