/* Code Written by Roy Pe'er. I've explained all the code in the grey comments.
I recommend you to go over the code, examine it, play with it, improve it and modify it according to your needs. 
For more awesome videos, subsrice to my channel:
http://www.youtube.com/subscription_center?add_user=Roypeer1
*/

#include <AFMotor.h> //import your motor shield library
#define trigPin 13 // define the pins of your sensor
#define echoPin 12 
#define trigPin2 8 //* new code defining pins of sensor
#define echoPin2 7
AF_DCMotor motor1(1, MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(4, MOTOR12_8KHZ);
 
void setup() {
  Serial.begin(9600); // begin serial communitication  
  Serial.println("Motor test!");
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(trigPin2, OUTPUT); //*
  pinMode(echoPin2, INPUT);
  motor1.setSpeed(105); //set the speed of the motors, between 0-255
  motor2.setSpeed(125);  
}
 
void loop() {
  long duration, distance; // start the scan
  long duration2, distance2; //* new things

  bool just_rev = false;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);

  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  duration2 = pulseIn(echoPin2, HIGH);
  Serial.print("Dur: ");
  Serial.print(duration2);
  
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  distance2 = (duration2/2) / 29.1;
  Serial.print("D1 ");
  Serial.print(distance);
  Serial.print("  D2 ");
  Serial.print(distance2); 
  
  if (distance < 25)/*if there's an obstacle 25 centimeters, ahead, do the following: */ 
  {   
    Serial.println ("Close Obstacle detected!" );
    Serial.println ("Obstacle Details:");
    Serial.print ("Distance From Robot is " );
    Serial.print ( distance);
    Serial.print ( " CM!");// print out the distance in centimeters.

    Serial.println ("Check if there's something behind!");
    if ((distance2 < 25) && (distance != 0))
    {
      Serial.println ("Something is Close behind me!");
      Serial.println ("Obstacle details:");
      Serial.print ("Distance From Robot is ");
      Serial.print (distance2);
      Serial.print (" cm!"); 
      Serial.println (" Evasive Maneuvers!");

      motor1.run(FORWARD);
      motor2.run(FORWARD);
    }
    else 
    {
      Serial.println ("Must make room!");
      Serial.println ("Must reverse!");

      motor1.run(FORWARD);
      motor2.run(BACKWARD);

      just_rev = true;
    }
  }
  if (just_rev == true)
  {
    Serial.println ("Just reversed for more room");
    Serial.println ("Must turn to avoid next time");

    motor1.run(FORWARD); 
    motor2.run(FORWARD);

    just_rev = false;
  }
  else 
  {
    Serial.println ("No obstacle detected. going forward");
    delay (15);
    motor1.run(BACKWARD); //if there's no obstacle ahead, Go Forward! 
    motor2.run(FORWARD); 
    Serial.println ("Moved."); 
  }  
}
