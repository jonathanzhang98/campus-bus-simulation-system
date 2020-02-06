## 3081 lab05 C++ Polymorphism, Class Destructors, and Other Gotcha's

## What You Will Learn
1. Polymorphism and dynamic memory allocation.
2. Class static variables.
2. When to use destructors.
3. When to use the copy constructor.

> There is no feedback for this lab. You submit your results through the corresponding **Canvas quiz**. Like the last quiz, you will have ONLY 3 ATTEMPTS at the lab. Again, you will have **3 ATTEMPTS**. It looks like Canvas saves your answers as you go along and that you can leave the quiz then resume later (BUT -- please test this first!).

## Git Reminder - DO NOT FORGET
### Retrieve Class Materials

Navigate to your repository.
```
% cd <path_to_directory_repo-userid>
```
You will again pull and merge the support-code branch from the remote shared-upstream repository. First, orient yourself to the branch that you are on and any uncommitted changes. The command
```
% git status
```

In general, you want to check the following:

1. If you are on your master branch and you have made changes that are not yet committed and pushed, you should probably do that before proceeding.

2. Move to the support-code branch with `git checkout support-code`.

3. `git pull upstream support-code` to grab the latest changes from the shared class repo.

4. `git checkout master` to move back to the master branch for merging.

5. `git merge support-code`

## Lab Instructions
### What's in labs/lab05_destructors

- main.cc:
    There are 3 helper functions in main. You need to pass a command line argument when you run the executable to run 1 of these 3. The 3 helper functions are:
    - RunStaticDemo()
    - RunPointerDemo()
    - RunMemoryDemo()

- delivery.cc:
    - The base class for different types of deliveries.

- overnight.cc, twoday.cc, and ground.cc:
    - Files containing classes derived from Delivery

### Executing the Code

To get started, you can compile and run each of the helper functions by passing an argument to the executable. Follow the directions below to change the code and observe the different behavior.

```
make
./deliver static
./deliver pointer
./deliver memory
```

> It is important to note that the makefile does not list headers as dependencies. This means that if you only change a header file, `make` will assume everything is up-to-date and not recompile and link. To fix this, use `make clean` to remove all object files and then call `make`.

<hr>

### Static Demo

The intent of inheritance is to create a base class that holds code for the common elements of a collection of similar classes. The common elements of the base class are inherited by the derived class, thereby reusing code, yet in each of the derived classes, base class functions can be overridden to implement the special functionality of that subclass. This becomes particularly powerful when we manage objects from all derived classes as if they were base class objects, but the overridden functions of the derived class are called instead. In C++, this happens through _dynamic binding_ and we call this _polymorphism_.

In this example, we are creating an array of base class Delivery objects, but storing derived class objects in the array. In C++, we use the keyword _virtual_ in front of a class method to let the compiler know that it should call the derived class version of that method.

Go to main.cc and look at the helper function `RunStaticDemo()`. Notice how the array is of type Delivery, but we are assigning objects of the derived class to those elements. Notice that each type of delivery differs by its Transport() function (the keyword _virtual_ is used in Delivery.h), which impacts the number of days it takes to deliver the package. Notice that Deliver() is NOT overridden.

#### Static Demo and Object Count

**You want to open the Canvas quiz now** and complete it as you complete this lab. The first quiz question asks where the deliveries[4] and special_delivery variables are being stored.

Run the static demo code with `./deliver static` at the command prompt. First look at the printouts under "CREATING ..." and "ASSIGNING ARRAY" and notice that it prints out every time an object is created or deleted. After everything is created and assigned, it prints out that there are 0 deliveries -- that's because we haven't filled that part in, but that's what we will do next.

A _static_ class variable is a single instance of a variable for all class objects. A common use of a static variable is to track how many objects of that class type have been created. Static variables are declared in the class header, but defined in the GLOBAL scope! Additionally, any class method that is called from outside the class and uses the static variable, must also be static (which you indicate by adding the keyword _static_ in front of its declaration). See IncrementCount as an example. 

    Take a moment to look through delivery.h and main.h to see how the static variable `Delivery::delivery_count_` is declared (in delivery.h), defined (in main.cc at the top), and used (in Delivery::IncrementCount and DecrementCount). What do you expect to be displayed when we uncomment IncrementCount()?

```
Uncomment the call IncrementCount() in the Delivery constructor in delivery.cc
```

What do you see? Very curious -- do you know why? **The next questions on the Canvas quiz** ask you about this static variable and what counts that you see when you run this demo with the Delivery::IncrementCount() uncommented.

Now,

```
uncomment IncrementCount() in the constructor of Ground.
make
./deliver static
```

We just made the problem worse! There isn't a quiz question on this, but make sure you understand why this made the problem worse. Let's undo that! Go back and re-comment the IncrementCount in ground.cc.

Let's try to address this problem of counting deliveries. The issue stems from the fact that we never decrement the count when objects are destroyed.

  Uncomment DecrementCount() in the Delivery destructor in delivery.cc

We fixed the problem for when the arrays are being filled with derived class objects! BUT WHAT??? Now we have another problem. **The next Canvas quiz question** asks about this.

The _copy constructor_ is used whenever you have to make a copy of an object that is being passed as a parameter. If you do not write the copy constructor, the compiler will write one for you, which is what has been done here. Sometimes that is okay, but sometimes you need to implement this. Let's write our own here. Add this declaration to Delivery.h

```
Delivery(const Delivery &package);
```

And add the definition to delivery.cc:
```
Delivery::Delivery(const Delivery &package) {
  std::cout << "Creating a delivery copy." << std::endl;
  IncrementCount();
}
```

You may need to `make clean` in order for these changes to take effect.

> Notice the syntax for the copy constructor. It looks very similar to the constructor in that it has no return type. It must have the _const_ keyword and the reference operator _&_ in the parameter list as shown. This constructor is being passed the object that will be copied and returns the "this" object. 

Now try compiling and running the _static_ demo. That's better. It looks like we have worked out the delivery count! (As an aside, you might want to separate the count for the delivery objects and for the derived class objects. This would require implementing static counts in each of the derived classes. You do not need to do this in this lab, but if you're curious, you could give that a try.)

#### Static Exercise and Polymorphism (Overriding Methods)

Look at the output after "Reporting on Deliveries." **The next Canvas quiz question** asks you to report on the problem.

It's curious that the transportation mode does not align with the number of days to delivery, yes!?! Take a moment to try to understand this. Notice that the days_to_deliver_ of the Delivery class is a private variable. Derived classes access this using setters and getters. (It might be useful at this point to depict the Delivery object inside the Ground object and list the variables and functions of each, along with their access.) Notice that Delivery::Deliver() is NOT virtual and therefore is not intended to be overridden by the derived class but Delivery::Transport() is virtual. Yet, Transport is not working because we have not implemented it with pointers, which will allow _dynamic binding_. **The next Canvas quiz question** asks about this.

<hr>

### Pointer Demo

Dynamic binding means that an object is bound to the appropriate class type and all of its overriding methods at runtime. This can only be achieved if the object is dynamically allocated at runtime. Thus, if you want to create an array of Delivery objects, but fill them with derived class objects, you have to create an array of _pointers_ to Delivery objects then dynamically bind those pointers to a derived class object. And don't forget to use the keyword _virtual_ for any function that you will be overriding.

Take a moment to look at the _RunPointerDemo()_ code. Notice how we are now creating an array of pointers and assigning each dynamically. This fixed the transport messages, and our object count is still good!

Also notice that an object is destroyed when calling Process(), but no object is destroyed when calling ProcessPointer(). There isn't a quiz question on this, but you should understand why this is the case?

There is one thing wrong with the delivery report. **The next Canvas quiz question** asks about this.

The problem lies in the header of ground.h. Do you see the problem? If not, look at your depiction of the Delivery object inside the Ground object and all corresponding variables and methods.

We need to fix the issue. **The next quiz question** asks you to select from a list of possible fixes to this problem.

<hr>

### Memory Demo

Now that we know we have to work with pointers and dynamic allocation, let's make sure that we are destroying our objects appropriately so that there are no dangling pointers and no memory leaks.

> Consider a pointer that points to a dynamically allocated object. If that object is deleted, then the pointer should be reset to NULL so that you don't try to reference deallocated memory. A **__dangling__** pointer is one that points to deallocated memory and if referenced, the behavior is undefined.

> When a class object is dynamically created in a local scope and then control goes out of scope but the object is not destroyed, you have created a **__memory leak__**. Or if you have a pointer pointing to an object on the heap, then you reassign it without deleting the previously pointed to object, then you have a **__memory leak__**. In general, it means there is nothing that points to that memory location and so there is no way to deallocate it and free it to be reallocated to something else.

In most languages, you do not have to manage memory, because it is built into the language. Pointers are powerful tools, but you have to be careful with them and make sure you know how they work! 9 times out of 10, if you get a SEGFAULT, you aren't managing your pointers correctly. Next week's lab will be devoted to using the debugger _gdb_, which is particularly easy and useful to use when you get errors related to pointers.

Look at the code for _RunMemoryDemo()_ in _main()_. Notice the type of the parameters defined for ReadyForTransport! These are `Object **` not `Object *`. Make sure you understand the need for this -- it is a common mistake to use a pointer instead of a pointer to a pointer. This is necessary because we essentially want to pass the pointers using pass by reference so that when we return from the function, these pointers point to new objects.

Let's first look at the destructor of Object. Notice that everything is commented out. Uncomment the appropriate parts of the code to correctly free memory. **The next Canvas quiz** asks you what code should be included in the Object destructor.

To test delete in the helper function, uncomment each of these lines (only one at a time) at the bottom of the function `ReadyForTransport()` in main.cc.
```
// delete *dynamic;
// delete dynamic;
// delete *local;
// delete local;
```

**The next Canvas quiz question** asks you which of these will compile and execute. It isn't in the quiz, but you should understand WHY this is the case.

Now comment out all deletes within the ReadyForTransport and try each of the following deletes at the end of the RunMemoryDemo. **The next Canvas quiz question** asks you which one will compile and run.
```
// delete dyn_object;
// delete &dyn_object;
// delete local_object;
// delete &local_object;
```

**The next 2 quiz questions** aska about the dyn_object pointer that gets reassigned a value at each iteration of the loop in _RunMemoryDemo()_ (which is problematic), and how to solve it.

If we want to try to address the problem, what code might you add to "ReadyForTransport(&dyn_object, &local_object)" that is called from RunMemoryDemo()?

- `if (*dynamic != NULL) { delete *dynamic; }`
- `delete *dynamic;`
- `delete dynamic;`
- It cannot be fixed.

Finally, **answer the last 2 quiz questions** related to _local_object_ is pointing to when it returns from _ReadyForTransport()_.

Once you complete the corresponding Canvas quiz, this lab is complete!

Congratulations!
