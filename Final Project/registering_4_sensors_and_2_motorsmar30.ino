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

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);


#define trigPinfront 8
#define echoPinfront 9
#define trigPinback 2
#define echoPinback 3
#define trigPinleft 4
#define echoPinleft 5
#define trigPinrigth 6
#define echoPinright 7
// #define motor1 11
// #define motor2 12

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
  //pinMode(motor1, OUTPUT);
  //pinMode(motor2, OUTPUT);

  AFMS.begin();
  leftMotor->setSpeed(200);
  rightMotor->setSpeed(200);
}

void loop() {


  long durationf, distancef;
  digitalWrite(trigPinfront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinfront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinfront, LOW);
  durationf = pulseIn(echoPinfront, HIGH);
  distancef = (durationf / 2) / 29.1;
  Serial.println ("distancef");
  Serial.println (distancef);
  if (distancef < 10) {
    Serial.println("go back");
  }

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
  if (distanceb < 10) {
    Serial.println("go forward");
  }

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
  if (distancel < 10) {  // This is where the LED On/Off happens
    Serial.println("turn right");
  }

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
  if (distancer < 10) {  // This is where the LED On/Off happens
    Serial.println("turn left");

  }

  else {
    Serial.println("keep on keeping on");
    leftMotor->run(FORWARD);
    rightMotor->run(FORWARD);
  }

  delay(500);
}
