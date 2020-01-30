### Classes in C++

These exercises are a part of your assigned reading. Look through the related reading resources if you are unfamiliar with how to define a C++ class or how to instantiate a class object. As you work through this exercise, if you get stuck or are unfamiliar with a concept, refer to the reading resources.

Questions are meant to test your understanding of the concepts. You do not need to formally answer them or turn anything in, HOWEVER the retrieval practice (i.e. quiz) will be based on the concepts covered in these exercises. So if you can answer those questions, you should do well on the quiz. Furthermore, we will go over the key concepts covered by the exercises during lecture and do some in-class follow-up exercises.

You are encouraged to form a study group and do these exercises together. You can practice pair programming techniques, in which the person "coding" is not the one at the keyboard. I suggest that the person with the least C++ programming be the one at the keyboard first. You can trade roles in the middle of the exercise.

Watch for these questions:
- Why did it display those values?
- Why might it not be a good idea to require the user to initialize member variables using setters?
- Why did it not compile?
- What happened to hal?
- Why have members of a struct public instead of private?

### Retrieve Class Materials

> These directions are taken from lab02. You will be following this procedure frequently to grab shared code.

Navigate to your repository.

    $ cd <path_to_your_repos_root_folder>

Now, we want to get the new class materials from the shared-upstream repository. Ensure you are in the _support-code_ branch by executing the _git status_ command.

    $ git status

The output should begin with the branch you are currently on. If it says _On branch support-code_, you are all set. If you are still in _master_, checkout the _support-code_ branch.  

    $ git checkout support-code

__What just happened?__ If you run the above command, you "switch" into the support-code branch. This means that git changes the filesystem to represent the state of files under the support-code branch. This could mean deleting files, adding files, or changing files, depending on how different the files in master are from the files in support-code. Since you were working in master on your first lab deliverable, there should be some minor changes when we switch to support-code. The code in your master branch is not changed, and it will be accessible again when you switch (i.e. _checkout_) the master branch.

Pull any updated materials into your _support-code_ branch.

    $ git pull upstream support-code

__What just happened?__ You pulled the files from our csci3081-shared-upstream repository's support-code branch into your local repository's support-code branch. Anything new in the shared-upstream repo is now a part of your local repo in this branch.

__Why didn't we do git pull?__ The default command in the Git workflow would indeed be _git pull_. However, that command uses the default target _origin_. For our work, origin is the target for your remote repository, repo-<your_id> residing on the github.umn.edu server. We set up csci3081-shared-upstream as a secondary remote target repository, with the name of upstream. To complete the pull action for that repo, we need to add the target name to the git pull command.

Now that we have the updates from our shared-upstream, let's add them into our own work in the master branch.

```
$ git checkout master
$ git merge support-code
```

__What just happened?__ You changed back to having the master branch as your working project. You then merged the file contents and commit history from support-code to master. This adds the changes to our shared-upstream repo into your working branch master.

__Why do we have support-code?__ Technically, we could issue a command that takes these changes and merges them directly into master, without having to deal with our own local support-code branch. That's true, and we could do that. But, we wanted to A) make sure that students maintain a clean copy of the provided code on their local machine. If you make a mistake in your master branch, having the clean copy may be beneficial. B) give you practice in handling merges, since that will be a beneficial skill to have when we start making more complex branching structures during the project.

<hr>
<hr>

### Demonstration of Class Definition in C++

Look through the provided code. Notice class member variables and methods (i.e. class functions) are declared in the header file _robot.h_. Class methods are defined in the source file _robot.cc_. It is important to understand how member variables are initialized, whether that be through the initialization list, in the body of the constructor, or perhaps not at all. Know that if you do not define a constructor, the compiler will write one for you.

<hr>

#### Default Constructor and Initialization

This first example makes use of the default constructor, which is the one the compiler writes. It can be problematic due to initialization.

Here is the code as it appears in the files:

**__robot.h__**

```C++
class Robot {
public:
  void MoveForward( int distance );
  void Display();
private:
  float direction_angle_;
  int position_[2];
};
```

**__robot.cc__**

```C++
void Robot::MoveForward(int distance) {
  position_[0] = position_[0] + distance*cos(direction_angle_);
  position_[1] = position_[1] + distance*sin(direction_angle_);
}

void Robot::Display() {
  cout << "Pos [" << position_[0] << " " << position_[1] << "]. angle "
  << direction_angle_ << endl;
}
```

**__main.cc__**

In C++, _main()_ serves as the entry point to the program. It must exist to generate an executable.

```C++
#include <iostream>
#include "robot.h"

int main() {
  Robot rosy_robot;
  rosy_robot.Display();
}
```

You can compile the program using the provided makefile, then call the executable _robot_.

```
make
./robot
```

Try it again.
```
./robot
```
</br>

> QUESTION: **Why did it display those values?**

</br>

<hr>

#### User-Defined Initialization

You can fix the initialization problem by adding "setters," and you should add some "getters" while you are at it. Add the code below to the header and source files.

**__robot.h__**

```C++
class Robot {
public:
  void MoveForward( int distance );
  void Display();
  // setters and getters
  void set_position( int x, int y);
  int* get_position();
  void set_direction_angle_rad(float d);
  float get_direction_angle_rad();

private:
  float direction_angle_;
  int position_[2];
};
```

**__robot.cc__**

Adding the following to the source code.

```C++
// setters and getters
void Robot::set_position( int x, int y) {
  position_[0] = x;
  position_[1] = y;
}
int* Robot::get_position() {
  return position_;
}
void Robot::set_direction_angle_rad(float d) {
  direction_angle_ = d;
}
float Robot::get_direction_angle_rad() {
  return direction_angle_;
}
```

**__main.cc__**

```C++
int main() {
  Robot rosy_robot;
  rosy_robot.set_position(0,0);
  rosy_robot.set_direction_angle_rad(0);
  rosy_robot.Display();
}
```

```
make
./robot
```

That's better!

</br>

> QUESTION: **This works in the sense that member variables are initialized before being used, but to require the user to initialize using setters might not be such a good idea. Why is that?**

</br>

<hr>
#### Constructors and Initialization

Let's fix initialization by forcing the user to provide initialization when s/he instantiates the object.

**__robot.h__**

You could pass along an array, but let's not do that right now.

```C++
  Robot(int x, int y, float theta);
```


**__robot.cc__**

```C++
Robot::Robot(int x, int y, float theta) {
  position_[0] = x;
  position_[1] = y;
  direction_angle_ = theta;
}
```

Try to compile with `make`.

</br>

> QUESTION: **What happened? Do you know why it will not compile? Read the error message -- we are just about to fix this.**

</br>


#### Overloaded Constructor

You want to give the user some options for how variables are initialized. By overloading the constructor (i.e allowing for different input parameter lists), the user can use default values or initialize with some other value.

<hr>
**__OPTION 1__**: In addition to the constructor defined above, define a no-parameter constructor that initializes to reasonable values, like the example below.

**__robot.h__**

```C++
public:
  Robot();
```

**__robot.cc__**

```C++
Robot::Robot() {
  position_[0] = 0;
  position_[1] = 0;
  direction_angle_ = 0;
}
```

**__main.cc__**

```C++
int main() {
  Robot rosy_robot;
  rosy_robot.Display();
  Robot c3po_robot(10,20,2.8);
  c3po_robot.Display();
}
```
Now you can declare a robot by initializing none or all of the member variables.

```
make
./robot
```

<hr>
**__OPTION 2__**: Define multiple constructors with various subsets of the member variables. Add the constructors below.

**__robot.h__**

```C++
public:
  Robot();
  Robot(int x, int y);
  Robot(float theta);
  Robot(int x, int y, float theta);
```

Now add the appropriate definitions to robot.cc. Let's see how we use them.

**__main.cc__**

```C++
int main() {
  Robot rosy_robot;
  Robot c3po_robot(100,100);
  Robot hal_robot(0,0,3.14/2);
  Robot eva_robot(-100,-100,-3.14/4);
  rosy_robot.Display();
  c3po_robot.Display();
  hal_robot.Display();
  eva_robot.Display();
}
```

Looks like this when you run it ...

```
make
./robot
```

```
Pos [0 0]. angle 0
Pos [100 100]. angle 0
Pos [0 0]. angle 1.57
Pos [-100 -100]. angle -0.785
```
<hr>
**__OPTION 3__**: (Probably the best) Create a single constructor that can take none to all member variable initializations.

Now we have to undo some of our work. We need only the one constructor, because we will add _default_ values. Notice that you define default values in the header, but they do not appear in the source file.

**__robot.h__**

```C++
  Robot(int x=0, int y=0, float theta=0);
```

**__robot.cc__**

```C++
Robot::Robot( int x, int y, float theta ) {
  position_[0] = x;
  position_[1] = y;
  direction_angle_ = theta;
}
```

**__main.cc__**

There was no need to change anything in main from before. All of the various forms of constructors was captured in the one constructor with default arguments.

```C++
int main() {
  Robot rosy_robot;
  Robot c3po_robot(100,100);
  Robot hal_robot(3.14);
  Robot eva_robot(-100,-100,-3.14/4);
  rosy_robot.Display();
  c3po_robot.Display();
  hal_robot.Display();
  eva_robot.Display();
}
```

And it comes out like this ...
```
Pos [0 0]. angle 0
Pos [100 100]. angle 0
Pos [3 0]. angle 0
Pos [-100 -100]. angle -0.785
```
</br>

> QUESTION: **__OOPS__, what happened to hal? We specified an angle of 3.14, but that didn't work. Can you explain that?**

</br>

<hr>
#### Initialization Lists

One more thing to improve our class definition ... an initializer list. But the array is special, so look at how it is initialized. This is not available in all versions of the compiler -- you need c++11 or higher. And the array has to be static.

```C++
Robot::Robot(int x, int y, float theta) :
  direction_angle_(theta), position_{x,y} {
}
```

<hr>
#### Struct Versus Array

Position is awkward and prone to error. Let's fix that with a struct definition.

```
struct Position {
  int x_;
  int y_;
  Position(int x=0,int y=0) : x_(x), y_(y) {}
};
```

But now we have to change all of our code. Too bad we didn't think about this change before we started!


> QUESTION: **If we use a struct, we don't need setters and getters, because everything is public. Why make everything public? Isn't the whole point of data structures to hide and protect the data?**
