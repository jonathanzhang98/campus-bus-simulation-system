### Feedback for Lab 10

Run on February 24, 15:12:13 PM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Fail: Run git ls-remote to check for existence of specific branch- Branch devel not found

+ Skip: Checkout devel branch.

  This test was not run because of an earlier failing test.

+ Skip: Run git ls-remote gather all branches in repo

  This test was not run because of an earlier failing test.

+ Skip: Checking for the correct number of branches

  This test was not run because of an earlier failing test.


#### Counting commits on devel

+ Skip: Checkout devel branch.

  This test was not run because of an earlier failing test.

+ Skip: Gather commit history

  This test was not run because of an earlier failing test.

+ Skip: Check git commit history

  This test was not run because of an earlier failing test.


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+ Fail: Run ghi for total number of issues in Github repo (Found: 0, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Fail: Checkout devel branch.

<pre>error: pathspec 'devel' did not match any file(s) known to git.
</pre>



+ Skip: Check that directory "project" exists.

  This test was not run because of an earlier failing test.

+ Skip: Change into directory "project".

  This test was not run because of an earlier failing test.

+ Skip: Check that file "makefile" exists.

  This test was not run because of an earlier failing test.

+ Skip: Check that make compiles.

  This test was not run because of an earlier failing test.

