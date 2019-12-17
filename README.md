# Introducing: The Monty Ball Machine

![alt text][intro]

[intro]: https://github.com/tantantheman/tantan-knochbox/blob/master/photos/knochoverview.jpeg "Knochbox Overview"

A tabletop game machine for class. Final project for CPSC 334.  
Programming in Arduino IDE.  

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

**How to play:**  

To start the game, roll the first ball off the ramp into the target area. When the game starts, two paddles will attempt to block the target area, frantically rotating back and forth. Your goal is to roll as many balls off the ramp into the target area by the time the 30-second timer expires. High scores of the session will be recorded. 

**How to run:**  
Plug in the ESP32 through the back cutout of the machine with a micro-USB cable and USB power brick, and enjoy! The LCD on the front will serve as an indication that the machine is in fact on and ready to play. 
  
**Design:**  
One of the most exciting aspects of this project was the chance for me to finally go beyond the traditional box-like enclosures that I have been building all semester, and work on improving my woodworking skills as well as my design skills. This time, instead of constructing a box and putting the components inside, I had to design and conceptualize everything in the beginning before I began to work so that every component and section of the Monty Ball Machine would seem integrated into the system as a whole. In addition, I made it a priority to design it to resemble a traditional arcade-style ball game, while being able to fit it on a table. 

There were also other design considerations, such as building components such as the ball ramp and target area to maximize enjoyment while playing. If the angle of the ball ramp was too steep or not steep enough, for example, it would dramatically affect the pace of the game. Furthermore, it was important to choose the right balls for the game. At the end, I chose foam practice golf balls, which were the perfect size and the right softness and weight. Lighter balls moved too fast, and didn't have enough weight to maintain inertia as it rolled down the ball return ramp. 

The most important thing I kept in mind while designing and creating the Monty Ball Machine was modularity. Because of its rather large size (the machine is about 30" deep), I wanted to make sure that it would be easily transportable. So, the Monty Ball Machine is actually two separate halves, with the first half being the ramp and ball return system module, and the second being the target area, obstacles, and electronic components. Both halves can be simply slid together to form the final table game.

**The Build:**  
The frames for both halves of the machine are essentially open-top rectangular prisms, bound together by hot glue and metal brackets. When put together, they resemble an arcade-style game. 

To construct the ramp, I started with a base of a sheet of plywood, and added a small block at the end of the ramp where it is designed to slope up. Then, I overlayed the wood sheet with strips of ultra-thin wood that was able to curve upwards, resting on the block of wood that defines its slope.

The ball return system was relatively straightforward. A sheet of plywood was elevated with a larger block of wood, but this time the sheet was shifted so that it extended out the back of the module, allowing for balls that leave the ramp to drop down below, rolling underneath the ramp to a channel that stopped at the front of the machine. The player could then reach underneath the ramp to get a continuous stream of balls for the game.  

For the second module, containing the electronics, sensor, and obstacles, another rectangular prism was built, with a face opening towards the player and space in the back to access electronics and to power the system. To create the target area, two small rectangles of balsa wood acted as border pillars, shrinking the target area towards the center. The back of the target area is a rectangle of wood tiled approximately 60 degrees north, essentially catching the balls as they fly off the ramp and letting them roll and drop down onto the ball return system of the first module below. Attached onto this sheet of wood is a vibration sensor, which essentially counts the number of times a ball makes contact with the board, knowing that the ball has made it past the obstacles.  



**Technical Difficulties:**  
The largest technical difficulty with building this project was actually figuring out a way to attach the motors in a way that worked with the thickness of the wooden enclosure. At the end, a combination of electric tape and shipping tape seemed to do the trick. In addition, calibrating the knocking to register successfully, and figuring out a timing to register an attempt was difficult, as it just relied on trial and error. 

**Video**  
A video of the KnöchBox in action can be found here:  
https://youtu.be/6DZXhUA5q48  


