### Feedback for Lab 10

Run on February 25, 10:41:18 AM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		7ac083142f7c1c21f86914e7ca6651ff35a56a98	refs/heads/devel

		18697241aa98a738c86a4682714f874990db4cbe	refs/heads/master



+ Pass: Checking for the correct number of branches

Insufficient branches found (found=0, required=2):




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history





+ Fail: Check git commit history
Insufficient commits (found=0,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+ Fail: Run ghi for total number of issues in Github repo (Found: 0, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Fail: Check that file "makefile" exists.

     "makefile" not found.

+ Skip: Check that make compiles.

  This test was not run because of an earlier failing test.

