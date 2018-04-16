# Create F.I.G.G. - The Object Avoiding Robot

![alt text][pic1]

[pic1]: https://github.com/loopingtangent/CS207majorProject/blob/master/img/20180414_083435.jpg "Picture of F.I.G.G."

> F.I.G.G. stands for "Front is Good, Go!"

The desire to have a robot sidekick has become paramount since films like Wall-E. What better way to have a little sidekick than 
to build one. Enter in F.I.G.G. 

At current, F.I.G.G. is able to avoid running into obstacles, and manouver himself around them. 

## Repositiory Contents

Contained in this repository are the following files:

* **/src** - This is the file where you can get the main source of code from. 
* **/img** - This contains an image of F.I.G.G.m as well as a few circuit diagrams
* **/libraries** - This contains a library from Ada Fruit for motors. While this is still available, there is no way of guaranteeing how long it will be available for, so it makes sense to have a copy on stand-by
* **/LICENSE** - This contains the license for this project. 
* **/README.md** - This is a copy of this document you are reading now! 

## Build Instructions

### Requirements
You will need: 
- X1 Arduino Uno
- x2 Mini Breadboards (~170 tie-points)
- X1 Arduino Motor Shield (Used Kuman KY58 L293D Motor Drive Shield)
- X1 Chassis Kit with Wheels 
- X2 Ultrasonic Distance Sensors (HC-SR04)
- Wires

You may also need to use a hot glue gun, depending on your chassis size. 

### Time to Build

1. Build your chassis as per instructions (usually) provided.
2. Attach your Arduino Uno. Some chassis come with holes for the arduino, however mine didn't, and I had to hotglue the Arduino to the chassis board.
3. Attach the breadboards. One goes on each end of the robot. If they do not have an adhesive on one side, you may need to hotglue them. 
4. Attach the sensors to each of the boards, with the parts facing outward. 
5. Connect thw wires as seen in the following image: 

![alt text][pic2]

[pic2]: https://github.com/loopingtangent/CS207majorProject/blob/master/img/figg-circuit.jpg "Picture of F.I.G.G.'s Circuit Diagram"


6. Connect the Motor Shield to the Arduino, and the motors to the shield. Connect the power source as well. 
7. Upload the program in /src/MainProgram.ino to the Arduino. (be sure to have the Ada Fruit AFMotor library installed)
8. Insert batteries and enjoy!

## Usage

Once the batteries are in, F.I.G.G. will begin rolling around.

F.I.G.G. works by using the ultrasonic distance sensors to determine how close something is to itself. If there is something less than 25cm in front of it, it checks to see if something has come up behind itself. If there has been something, it will immediately turn until the path is clear. If there is nothing behind it, it will back up slightly, and then turn. 

## Team

Samantha Rodgers - builder/coder/writer/etc. 

## Credits

This project is origianlly based on an Object Avoiding Robot by Roy Pe'er ([link here](http://www.instructables.com/id/Arduino-Ultimate-Obstacle-Avoiding-Robot/)). 

