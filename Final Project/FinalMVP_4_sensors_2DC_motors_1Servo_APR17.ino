/*

  //Tthis code is attempting to get readings from 4 sensors in the same code. sensors are at 90 degres from one another. also attempted to add motors. i beleive the motor sheild i'm using is broken

  HC-SR04 Ping distance sensor]
  VCC to arduino 5v GND to arduino GND
  Echo to Arduino pin 13 Trig to Arduino pin 12
  Red POS to Arduino pin 11
  Green POS to Arduino pin 10
  560 ohm resistor to both LED NEG and GRD power rail
  More info at: http://goo.gl/kJ8Gl
  Original code improvements to the Ping sketch sourced from Trollmaker.com
  Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#include <Servo.h>
Servo myservo;  // create servo object to control a servo

#define trigPinfront 8
#define echoPinfront 9
#define trigPinback 2
#define echoPinback 3
#define trigPinleft 4
#define echoPinleft 5
#define trigPinrigth 6
#define echoPinright 7

const int motor1Pin = 10;    // H-bridge leg 1 (pin 10, 1A)
const int motor2Pin = 11;    // H-bridge leg 2 (pin 11, 2A)
const int enablePin = 12;    // H-bridge enable pin 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPinfront, OUTPUT);
  pinMode(echoPinfront, INPUT);

  pinMode(trigPinback, OUTPUT);
  pinMode(echoPinback, INPUT);

  pinMode(trigPinleft, OUTPUT);
  pinMode(echoPinleft, INPUT);

  pinMode(trigPinrigth, OUTPUT);
  pinMode(echoPinright, INPUT);

  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);

  myservo.attach(13); // attaches servo to pin 13

}

void loop() {

  long durationf, distancef; //read front
  digitalWrite(trigPinfront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinfront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinfront, LOW);
  durationf = pulseIn(echoPinfront, HIGH);
  distancef = (durationf / 2) / 29.1;
  Serial.println ("distancef");
  Serial.println (distancef);

  long durationb, distanceb; // read back
  digitalWrite(trigPinback, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinback, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinback, LOW);
  durationb = pulseIn(echoPinback, HIGH);
  distanceb = (durationb / 2) / 29.1;
  Serial.println("distanceb");
  Serial.println(distanceb);


  long durationl, distancel; // read left
  digitalWrite(trigPinleft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinleft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinleft, LOW);
  durationl = pulseIn(echoPinleft, HIGH);
  distancel = (durationl / 2) / 29.1;
  Serial.println("distancel");
  Serial.println(distancel);

  long durationr, distancer; // read right
  digitalWrite(trigPinrigth, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinrigth, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinrigth, LOW);
  durationr = pulseIn(echoPinright, HIGH);
  distancer = (durationr / 2) / 29.1;
  Serial.println("distancer");
  Serial.println(distancer);

  if (distancef < 10) { // go back
    Serial.println("go back");
    //go straight and back
    myservo.write(90);
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
    delay(5000);
  }

  if (distanceb < 10) { // go forward
    Serial.println("go forward");
    //go straight forward
    myservo.write(90);
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    delay(5000);
  }


  if (distancel < 10) {  // turn right
    Serial.println("turn right");
    //go forward and turn right
    myservo.write(45);
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    delay(5000);
  }
  if (distancer < 10) {  // This is where the LED On/Off happens
    Serial.println("turn left");
    //go forward and turn left
    myservo.write(135);
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    delay(5000);
  }

  else {
    Serial.println("stop");
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high

  }

 
}
