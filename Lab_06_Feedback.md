### Feedback for Lab 06

Run on February 14, 15:18:49 PM.


#### System Files and Directory Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab06_gdb" exists.

+ Pass: Change into directory "labs/lab06_gdb".


#### Test that code compiles and creates the exectuable

+ Pass: Check that make compiles.



+ Pass: Check that file "date" exists.

+ Pass: Program executes flawlessly.



+ Fail: Check for correct output.

    Files are not equal.
6,8d5
< date is: January 1, 1993
< date is: January 1, 1992
< date is: January 1, 1991
9a7,9
> date is: January 1, 1991
> date is: January 1, 1992
> date is: January 1, 1993
16,18d15
< date is: January 1, 1993
< date is: January 1, 1992
< date is: January 1, 1991
19a17,19
> date is: January 1, 1991
> date is: January 1, 1992
> date is: January 1, 1993




