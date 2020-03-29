## Iteration 1 Information and Tutorials
### UPDATE 1 - March 17th - Adjusted due date following COVID-19 impacts

This lab is intended to help you with some of the deliverables for the final stage of Iteration 1, specifically implementing a bus factory and implementing a pause button for the simulation. As a reminder, here is more detailed information from the Iteration 1 Requirements:

**Design a bus factory and implement it in the simulation**

You should create a bus factory class that is capable of creating large, regular, or small capacity busses and implement it in the simulation. You can do this by creating a concrete factory class or an abstract factory.

Note the values of small, regular, and large should be 30, 60, 90.

**Add Functionality to Pause / Resume**

Add a pause/resume button to the simulation. If a user presses the pause/resume button, the simulation should pause. When the user presses the button again, the simulation should resume from where it left off.

This will entail adding a button to the graphical user interface, and depending on the design, could require the addition of command to the command pattern implemented in the `my_web_server_command` files in the directory `project/web_code/web`.

There are **two deliverables for this lab**:
1. UML of the Bus Factory you choose to Implement for interation 1 integrated into your updated UML diagram of the Transit Simulation.   
2. Pause/Resume Button code

These should be submitted on Canvas, and they are due at **11:55pm on Tuesday, March 24** at the same time as the rest of the Iteration 1 requirements.
​
### (IMPORTANT!) Before you start 

Pull our code from shared upstream to your support-code branch. Then, use your devel branch to merge from support-code upstream. After you merge, branch off of devel to a branch that implements the pause/resume functionality. For this lab, all your work should be done in that branch because your code will not work correctly after the edits you make. Once you have a working version of the pause/resume functionality in JS AND C++ code, you should merge to devel. After you're done with all iteration 1 requirements, merge devel to master. You should ALWAYS branch off of devel to edit, merge to devel after you're done editing, then after a certain number of requirements merge to master to publish your code.

### Part One: Bus Factory UML
​
To assist in implementing the bus factory, you should start by drawing an UML diagram for the factory and all the classes it interacts with. Note that it will assist in creating three different types of Bus objects: large, regular, or small. The advantage of using a factory is that the creation of these objects is decoupled from the VisualizationSimulator class that uses them. Once we have implemented the factory, even if we decide to add a fourth type of Bus, we will not need to change the code in the VisualizationSimulator class.
​
Our code already contains an example of a factory: the PassengerFactory class. You should have diagrammed this class when you drew the UML diagram for the provided code base. Now, using your original diagram as a guide, create a diagram for a new BusFactory class. You can use either a concrete factory or an abstract factory; the choice is yours. Once you are satisfied with your diagram, you can start implementing the factory in code.
​
Right now, there isn't any specific reason to create one type of bus(e.g, large capacity) instead of a different one (e.g., small capacity). However, this might change at a later time. During peak hours, for instance, we might want to use large busses more frequently. For now, the following code snippet, which generates a random integer between 1 and 3 (for example to represent small, medium, and large) might be helpful:
​
```
#include <vector>
#include <random>
​
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
int rand_int = dist1(rng);
```
​
Make sure to submit your updated UML diagram on Canvas when it is complete.
​
### Part Two: Pause/Resume Button Pseudocode  
​
To implement the pause button, you need to think about what aspects of the code must be modified. One, since the pause/resume button must be visible to the user, we need to add some code to the `project/web_graphics/sketch.js` file. After we have added the pause button to the visualization, we will go through the mechanisim of the "**start**" functionality to give you a sense of how the JS code interacts with the backend.
​
#### Adding the Pause button
> Once you finish this lab, **UNCOMMENT** all the code we have asked you to comment out.

In order to test if the JS code is being correctly modified after every step, we must first comment out part of the `project/web_graphics/sketch.js` code.
1. Comment out the lines 145 and 146 `socket = new WebSocket("ws://" + location.hostname+(location.port ? ':'+location.port: ''), "web_server");` and `setupSocket();`.
2. Comment out line 304 in the code `socket.send(JSON.stringify({command: "start", numTimeSteps: numTimeSteps, timeBetweenBusses: busTimeOffsets}));`.

What you just did:
1. Since we don't want to setup a socket **for communication between the backend (C++) and the frontend (JS)**, we are skipping setting up the socket.
2. Since we don't have a connection to send commands to, we are skipping doing anything once the start button is clicked.

You should now be able to view the html file `project/web_graphics/project.html` on your web browser without having to start the server. 


**Let's add the button**  
> Normally you would style your buttons in CSS, however, it's out of the scope of this course. So, we will use the simple button object provided in html and javascript.

First, we need to instantiate a button variable, much like the start variable you'll find in line 30. So, in line 32, add `var pauseButton;`. After that, you need to style that button and give it a position in your visualization. For clarity, we will do that where we instantiated the start button (`setup()` function that starts at line 144). Right below the instantiation of the start button in line 164, add this:  
``` 
pauseButton = createButton('Pause');
pauseButton.position(10, startYPos+20);
pauseButton.value("Pause");
pauseButton.style('width', '200px');
pauseButton.style('height', '20px');
```
The first line creates a new button object. The second line creates the position of that object. The third sets a value that we will use to create a toggle function. The fourth and fifth set the dimensions of the button. There are many scales to use for the dimensions, we just happened to choose pixels. After adding this code, you should be able to see the button on your web browser (make sure you refresh).
> in JS, (0,0) is at the top left of the screen. 

To finish configuring the button, you need to signal what function you would like to execute once the button is clicked. To do that, add `pauseButton.mousePressed(pause);` to the bottom of the commands you added just now. Again, check your web browser to see if there are any changes.
> You won't find any changes as you haven't added a function called pause to your JS code.

All that's left to do now is add the code for the function pause:

right below the implementation for the start function in line 298, add this code:
```
function pause() {
    if (started)
    {
        if (pauseButton.value!=="Resume"){
            pauseButton.value="Resume";
            pauseButton.elt.childNodes[0].nodeValue ="Resume";
        }
        else {
            pauseButton.value="Pause";
            pauseButton.elt.childNodes[0].nodeValue ="Pause";
        }
        socket.send(JSON.stringify({command: "pause"}));
    }
}
```
After doing that, refresh your browser, then click on the start button (to make the boolean `started` be true), then make sure that your pause button toggles between Pause and Resume. `socket.send(JSON.stringify({command: "pause"}));` simply sends information to the backend that the user just executed the pause command.

Since the start button is no longer useful after clicking it, you might want to add `startButton.elt.disabled = true` after you set the boolean `started` to True in line 305.

With that, you should have everything you need from the frontend to be able to implement the pause functionality. Now that you finished this part, **Uncomment the code we asked you to comment out above to reconnect the frontend and the backend.**
#### JS and C++ interaction for the start button

If you take a look at the JavaScript code in `sketch.js`, you'll notice that all of the `socket.send()` calls tend to include the 'command' field in the JSON that is passed to the argument. This is how the web code tells the server what to do. But where are these commands processed in the C++ code?

Most of this is handled in the web_code/web directory. In the file `main.cpp`, you may notice that there are several lines that are of the form `state.commands['NAME'] = new NAMECommand()`. This is where the different server commands are registered, so when the `socket.send({command: "NAME"})` is called, the information will be relayed to the corresponding function NAMECommand.execute(). There are currently 5 commands:

* getRoutes: sends JSON to the client, including information about the location and id of each stop
* getBusses: similar to getRoutes, sends JSON including information about busses
* start: kicks off the simulation, nothing will happen before this is called
* update: effectively moves the simulation forward a timestep, calls the Update() function on various entities in the simulation
* initRoutes: don't worry too much about this one,  returns information about the number of routes

When you define the pause button, you will have to make sure that you add your functionality to all relevant points on this pipeline. This naturally raises the question, where are the various commands added? 

As you might anticipate, the command code is in `web_code/web/my_web_server_command.h/cc`. For each command, there's a constructor, which doesn't do much, and and execute() command, which is called whenever the socket.send() is called for that command. While the constructors take different arguments, all of the execute functions take the same arguments:

* `session: MyWebServerSession*` => contains information about the web session, you shouldn't need to interact with this too much
* `command: picojson::value&` => this is how you will receive the information you passed in the JSON from the javascript
* `state: MyWebServerSessionState*` => don't worry about this one

The final thing to note is that many of the commands take in and store the `VisualizationSimulator`. This is similar to a driver for the simulation. Its important methods are `Start()` and `Update()`, which perform very similar roles to the start() and update() commands.

To implement the Pause() command, you will need to do the following:
1. Create a pause button, and call a function pause() whenever it is clicked
2. Send information through the socket to call the pause() command
3. Create a new class `PauseCommand()`, whose constructor takes the `VisualizationSimulator` as its only argument.
4. Add a new instance of this PauseCommand to the commands list in `main.cc`
5. Create a function, PauseCommand::execute(), that calls Pause() on the associated `VisualizationSimulator`
6. Create a function VisualizationSimulator::Pause() that will pause the simulator if it is running and not paused, and will unpause it if it is running and paused.
7. Edit the function VisualizationSimulator::Update(), adding logic (code) to it so it does not execute if the simulator is paused, and resumes execution when the pause button is selected again.

### End of the lab

You have reached the end of this lab. As a reminder, this lab **has two deliverables**:
1. UML of the Bus Factory you choose to Implement for interation 1 integrated into your updated UML diagram of the Transit Simulation.
2. Pause/Resume Button functionality implemented in the simulation

Your updated UML diagram which includes the UML class design of the factory pattern you implemented should be submitted via Canvas, and the documented code that implements the Pause/Resume button should be submitted with the rest of the functionality you are required to implement for iteration 1 as per the development process documented in Lab 10.  The deliverables are due at **11:55pm on Tuesday, March 24** at the same time as the rest of the Iteration 1 requirements.

