# Introducing: Monty Ball

![alt text][intro]

[intro]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyballcover-1.jpg "Monty Ball Overview"

A tabletop game machine for class. Final project for CPSC 334.  
Programming in Arduino IDE.  

**Concept:**  
For my final project, I wanted to create something that felt like a culmination of all the skills that I had learned from this course. I wanted to work on improving my physical building skills, as well as designing something with intention from the ground up. I knew that I wanted it to be fun, and push the boundaries of what I had been able to accomplish with previous projects. With these things in mind, Monty Ball was born.

**Dependencies:**  
ESP32Servo.h  
Wire.h  
LiquidCrystal_I2C.h

**Materials:**  
One ESP32 Dev Module  
One 4-Line Backlit LCD Module with Built-in IIC Interface
One SW-420 vibration sensor  
Two SG90 Microservo Motors  
One Bread Board  
One Micro-USB Cable and USB Power Brick (5A+)  
6 foam practice golf balls (as game balls)
8 sheets of 1/8" x 12" x 24" plywood  
Assorted planks and blocks of balsa wood/scrap wood  
Four ultra-thin sheets of wood (bendable for ramp and front)  
Lots of jumper wires  
Lots of metal brackets  
Assorted wooden cut-out letters  
Hot glue (like, a ton of it)  
Salt and pepper, to taste 

**How to play:**  
To start the game, roll the first ball off the ramp into the target area. When the game starts, two paddles will attempt to block the target area, frantically rotating back and forth. Your goal is to roll as many balls off the ramp into the target area by the time the 30-second timer expires. High scores of the session will be recorded. 

**How to run:**  
Plug in the ESP32 through the back cutout of the machine with a micro-USB cable and USB power brick, and enjoy! The LCD on the front will serve as an indication that the machine is in fact on and ready to play. 
  
**Design:**  
![alt text][design]

[design]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-15.jpg "Monty Ball Design"

One of the most exciting aspects of this project was the chance for me to finally go beyond the traditional box-like enclosures that I have been building all semester, and work on improving my woodworking skills as well as my design skills. This time, instead of constructing a box and putting the components inside, I had to design and conceptualize everything in the beginning before I began to work so that every component and section of the Monty Ball Machine would seem integrated into the system as a whole. In addition, I made it a priority to design it to resemble a traditional arcade-style ball game, while being able to fit it on a table. 

There were also other design considerations, such as building components such as the ball ramp and target area to maximize enjoyment while playing. If the angle of the ball ramp was too steep or not steep enough, for example, it would dramatically affect the pace of the game. Furthermore, it was important to choose the right balls for the game. At the end, I chose foam practice golf balls, which were the perfect size and the right softness and weight. Lighter balls moved too fast, and didn't have enough weight to maintain inertia as it rolled down the ball return ramp. 

The most important thing I kept in mind while designing and creating the Monty Ball Machine was modularity. Because of its rather large size (the machine is about 30" deep), I wanted to make sure that it would be easily transportable. So, the Monty Ball Machine is actually two separate halves, with the first half being the ramp and ball return system module, and the second being the target area, obstacles, and electronic components. Both halves can be simply slid together to form the final table game.

**The Build:**  
The frames for both halves of the machine are essentially open-top rectangular prisms, bound together by hot glue and metal brackets. When put together, they resemble an arcade-style game. 

![alt text][arcade]

[arcade]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-13.jpg "Monty Ball Cabinet"

![alt text][ramp]

[ramp]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-4.jpg "Monty Ball Ramp"

To construct the ramp, I started with a base of a sheet of plywood, and added a small block at the end of the ramp where it is designed to slope up. Then, I overlayed the wood sheet with strips of ultra-thin wood that was able to curve upwards, resting on the block of wood that defines its slope.

![alt text][rampandball]

[rampandball]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-5.jpg "Monty Ball Ramp and Ball Return"

![alt text][overhead]

[overhead]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-2.jpg "Monty Ball Ball Return"

![alt text][return]

[return]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-3.jpg "Monty Ball Return Drop Point"

![alt text][balls]

[balls]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-1.jpg "Monty Balls"

The ball return system was relatively straightforward. A sheet of plywood was elevated with a larger block of wood, but this time the sheet was shifted so that it extended out the back of the module, allowing for balls that leave the ramp to drop down below, rolling underneath the ramp to a channel that stopped at the front of the machine. The player could then reach underneath the ramp to get a continuous stream of balls for the game.  

For the second module, containing the electronics, sensor, and obstacles, another rectangular prism was built, with a face opening towards the player and space in the back to access electronics and to power the system. To create the target area, two small rectangles of balsa wood acted as border pillars, shrinking the target area towards the center. The back of the target area is a rectangle of wood tiled approximately 60 degrees north, essentially catching the balls as they fly off the ramp and letting them roll and drop down onto the ball return system of the first module below. Attached onto this sheet of wood is a vibration sensor, which essentially counts the number of times a ball makes contact with the board, knowing that the ball has made it past the obstacles.  

![alt text][backhalf]

[backhalf]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-9.jpg "Monty Ball Back Module"

The obstacle system is essentially a horizontal beam of wood spanning the width of the table, with two servo motors attached under it in the middle. A small plank of balsa wood is attached to each motor, with these "paddles" swinging down once the game starts. Balsa wood is light enough to be driven by the microservos, allowing for the speed required. 

![alt text][detect]

[detect]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-12.jpg "Vibration Sensor"

Finally, the backlit LCD panel is glued onto the pillar with a metal bracket, operating as the typical score screens found on these arcade games. It displays a welcome message and instructions on how to start the game, as well as the high score. When the game starts, the score is updated and the high score is updated accordingly when the game is over. 

![alt text][lcd]

[lcd]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-10.jpg "Monty Ball LCD"

These components are all connected to a breadboard attached to the side of the machine, which is connected to an ESP32.  

![alt text][esp]

[esp]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-11.jpg "Wiring"

Last but not least, another ultra-thin sheet of wood was used to create the curved signage for the machine. Pre-cut wood letters were hot-glued onto the sign, and I cut up a third of a foam golf ball to glue onto the front as well. 

![alt text][sign1]

[sign1]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-6.jpg "Monty Ball Signage 1"

![alt text][sign2]

[sign2]: https://github.com/tantantheman/tantan-montyball/blob/master/montyball-photos/montyball-7.jpg "Monty Ball Signage 2"

**The Code:**  
For the programming, all of it was done in the Arduino IDE. The program uses a preexisting library to write statuses to the LCD panel, and when the first ball roll is detected, it lowers the obstacle panels and starts rotating them in random directions until the game is over. One of the more complicated things done was learning how people build game timers in the program, because the delay() function could not be used without pausing all the other elements in the game. 

**Technical Difficulties:**  
There were several technical difficulties that came up during the project. Almost all of them could be solved by spending more money to upgrade parts.  

The first technical difficulty that arose was the LCD Screen. Occasionally, the LCD screen would just clear for unknown reasons. Even with wires swapped, the error still would occur. A power cycle would seem to fix the issue until the next time it occured. In addition, it would be advised to use an OLED screen in the future. The LCD just did not refresh fast enough for the score, and the whole screen had to essentially refresh to update small things without error. 

The second issue that arose was with the vibration sensor. Unfortunately, the vibration sensor's calibration was terrible, in the sense that the built-in potentiometer would lose it's set levels after a few minutes of playing. This meant that eventually, the vibrations from the servo motors would actually be picked up on the vibration sensor. 

**Video:**  
A video of Monty Ball in action can be found here:
https://youtu.be/RgerheXSU-0


