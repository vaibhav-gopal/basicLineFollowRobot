/*
  Line Following Robot CPT
  Name: Vaibhav Gopalakrishnan
  Date: Tuesday, Oct 27, 2020
  Description: A program which allows a robot to follow a black line around a course.
  The program does this by constantly checking sensor inputs and powering its corresponding motors to achieve turns and forward motion.
*/
const int rMot = 7;
const int rMot2 = 6;
const int lMot = 4;
const int lMot2 = 5;
const int en1 = 3;
const int en2 = 9;
int rEye, lEye;
bool startUp = true;

void setup() {
  // initialize digital pins for motors as an output and start serial monitor
  Serial.begin(19200);
  pinMode(rMot, OUTPUT);
  pinMode(rMot2, OUTPUT);
  pinMode(lMot, OUTPUT);
  pinMode(lMot2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}

void loop() {
  //adds a 3 second start up delay so you can set up first
  if (startUp) {
    delay(3000);
    startUp = false;
  }
  //Reads the sensor inputs and prints them
  rEye = analogRead(A6);
  lEye = analogRead(A5);
  Serial.println(rEye);
  Serial.println(lEye);
  
  //ROBOT MOVEMENT AND SENSOR DESCISIONS 
  if (rEye >= 780 && lEye >= 780) {
    //If the left sensor detects and the right sensor detects, then increase speed for both motors and hold it for 1/10th of a second to get over a ramp
    analogWrite(en1, 255);
    analogWrite(en2, 255);
    digitalWrite(rMot, HIGH);
    digitalWrite(rMot2, LOW);
    digitalWrite(lMot, HIGH);
    digitalWrite(lMot2, LOW);
    delay(100);
  } else if (rEye >= 780 && lEye < 780) {
    //if the right eye detects black, increase speed in left motor and run it while stopping the right motor
    analogWrite(en1, 255);
    analogWrite(en2, 255);
    digitalWrite(lMot, HIGH);
    digitalWrite(lMot2, LOW);
    digitalWrite(rMot, LOW);
    digitalWrite(rMot2, LOW);
  } else if (lEye >= 780 && rEye < 780) {
    //if the left eye detects black, increase speed in right motor and run it while stopping the left motor
    analogWrite(en1, 255);
    analogWrite(en2, 255);
    digitalWrite(lMot, LOW);
    digitalWrite(lMot2, LOW);
    digitalWrite(rMot, HIGH);
    digitalWrite(rMot2, LOW);
  } else{
    //decrease speed and run both motors when both sensors detect nothing
    analogWrite(en1, 145);
    analogWrite(en2, 145);
    digitalWrite(rMot, HIGH);
    digitalWrite(rMot2, LOW);
    digitalWrite(lMot, HIGH);
    digitalWrite(lMot2, LOW);
  }
}
