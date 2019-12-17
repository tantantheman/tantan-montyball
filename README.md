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
One Micro-USB Cable and USB Power Brick (2.4A+)  
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
  
**Implementation:**  
One of the most exciting aspects of this project was the chance for me to finally go beyond the traditional box-like enclosures that I have been building all semester, and work on improving my woodworking skills as well as my design skills. This time, instead of constructing a box and putting the components inside, I had to design and conceptualize everything in the beginning before I began to work so that every component and section of the Monty Ball Machine would seem integrated into the system as a whole. In addition, I made it a priority to design it to resemble a traditional arcade-style ball game, while being able to fit it on a table. 

There were also other design considerations, such as building components such as the ball ramp and target area to maximize enjoyment while playing. If the angle of the ball ramp was too steep or not steep enough, for example, it would dramatically affect the pace of the game.  

The most important thing I kept in mind while designing and creating the Monty Ball Machine was modularity. Because of its rather large size (the machine is about 30" deep), I wanted to make sure that it would be easily transportable. So, the Monty Ball Machine is actually two separate halves, with the first half being the ramp and ball return system module, and the second being the target area, obstacles, and electronic components. Both halves can be simply slid together to form the final table game.

**Technical Difficulties:**  
The largest technical difficulty with building this project was actually figuring out a way to attach the motors in a way that worked with the thickness of the wooden enclosure. At the end, a combination of electric tape and shipping tape seemed to do the trick. In addition, calibrating the knocking to register successfully, and figuring out a timing to register an attempt was difficult, as it just relied on trial and error. 

**Video**  
A video of the KnöchBox in action can be found here:  
https://youtu.be/6DZXhUA5q48  


