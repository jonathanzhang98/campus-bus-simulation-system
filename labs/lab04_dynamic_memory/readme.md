# Lab04 Dynamic Allocation Exercise

## What You Will Learn
1. How C++ allocates memory for static arrays.
2. How C++ dynamically allocates memory for arrays and array elements.
3. How memory is freed after dynamic allocation.


**__There is no grading script for this lab. Simultaneously view this lab and the Canvas quiz on dynamic allocation. The quiz will give some options in completing the code, and you can answer the questions on the quiz as you work through the lab. You will have ONLY 3 ATTEMPTS at the Canvas quiz, and the highest score will be recorded.__**

## Git Reminder - DO NOT FORGET
### Retrieve Class Materials

> In case you forgot how, here is how to pull in the shared code ...

Navigate to your repository.
```
% cd <path_to_directory_repo-userid>
% git status
```

1. If you are on your master branch and you have made changes that are not yet committed and pushed, you should probably do that before proceeding.

2. Move to the support-code branch with `git checkout support-code`.

3. `git pull upstream support-code` to grab the latest changes from the shared class repo.

4. `git checkout master` to move back to the master branch for merging.

5. `git merge support-code`

## Lab Instructions
### Completing the Code

Part of the assignment is to fill in the code that initializes, displays, and destroys the arrays in the ArrayPointerTest class. You will show what you have learned by completing the corresponding Canvas quiz.

Open ArrayPointerTest.cc and complete the following. Recall that to compile and run the executable:
```
make
./ducks
```

1. In the ArrayPointerTest constructor, for each of the ducks#_ arrays, fill in the code that will initialize "count_" ducks. For our purposes, the count_ is set to 3 (which is already in the code).

2. In the NameTheDucks class method, for each of ducks2_, ducks3_, and ducks4_, fill in the code to name the 3 ducks and to set the array number in which the duck is stored.

3. In the DisplayContents class method, uncomment all the code that performs the quack for each duck in each array.

4. Take notice in the class method DisplayContents how the individual ducks are referenced. In ducks1_ and ducks2_, they are referenced using the '.' operator, but in ducks3_ and ducks4_, they are referenced using the '->' operator. You don't have to answer this in the quiz, but you should understand why the different operators are needed in the different circumstances.

5. In the ArrayPointerTest destructor, for each of the ducks#_ arrays, fill in the code that will destroy all objects created at the instantiation of an ArrayPointerTest object. 

6. [Optional] You may want to print the size of various data types. You can achieve this using the `sizeof` operator. For instance, if you want to print the size of a duck object, you can write `cout << "size of a Duck object: " << sizeof(Duck) << endl;`.

While your code in this lab will not be checked for a grade, you can check the output of your program against the example below.


```
Instantiating ArrayPointerTest, which creates my ducks arrays.

Initializing ducks1.
Initializing ducks2
Initializing ducks3
Initializing ducks4
Naming ducks1
Naming ducks2
Naming ducks3
Naming ducks4

ducks1
lemon in ducks1 says Quack.
yang in ducks1 says Quack.
mia in ducks1 says Quack.
ducks2
lemon in ducks2 says Quack.
yang in ducks2 says Quack.
mia in ducks2 says Quack.
ducks3
lemon in ducks3 says Quack.
yang in ducks3 says Quack.
mia in ducks3 says Quack.
ducks4
lemon in ducks4 says Quack.
yang in ducks4 says Quack.
mia in ducks4 says Quack.
All my ducks will be destroyed upon exit of helper().
In ArrayPointerTest destructor.

Deleting ducks1
Deleting ducks2
mia in ducks2 is being destroyed.
yang in ducks2 is being destroyed.
lemon in ducks2 is being destroyed.
Deleting ducks3
lemon in ducks3 is being destroyed.
yang in ducks3 is being destroyed.
mia in ducks3 is being destroyed.
Deleting ducks4
lemon in ducks4 is being destroyed.
yang in ducks4 is being destroyed.
mia in ducks4 is being destroyed.
Duck in ducks0 is being destroyed.
Duck in ducks0 is being destroyed.
Duck in ducks0 is being destroyed.
Duck in ducks0 is being destroyed.
Duck in ducks0 is being destroyed.
Duck in ducks0 is being destroyed.
Duck in ducks0 is being destroyed.
mia in ducks1 is being destroyed.
yang in ducks1 is being destroyed.
lemon in ducks1 is being destroyed.
```
