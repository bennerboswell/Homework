/*

  // This code gets readings from 4 ultrasonic sensors, converts sensor data into CM and then decides weather to go forward, left, right or back using 2 DC motors and 1 servo motor. 
  // The defuault is to not move.
  // Sensors are at 90 degres from one another.

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
  //set up trigger and echo pins from sensors
  Serial.begin (9600);
  pinMode(trigPinfront, OUTPUT); // front pin
  pinMode(echoPinfront, INPUT);

  pinMode(trigPinback, OUTPUT); // back pins
  pinMode(echoPinback, INPUT);

  pinMode(trigPinleft, OUTPUT); // left pins
  pinMode(echoPinleft, INPUT);

  pinMode(trigPinrigth, OUTPUT); // right pins
  pinMode(echoPinright, INPUT);

  // set motor pins as out upts
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);

  myservo.attach(13); // attaches servo to pin 13

  }

  void loop() {

  // collecting data

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

  // using data

  if (distancef < 15) { // go back
    Serial.println("go back");
    //go straight and back
    myservo.write(90);
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
    delay(500);
  }

  if (distanceb < 15) { // go forward
    Serial.println("go forward");
    //go straight forward
    myservo.write(90);
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
    delay(500);
  }


  if (distancel < 15) {  // turn right
    Serial.println("turn right");
    //go forward and turn right
    myservo.write(45);
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
    delay(500);
  }
  if (distancer < 15) {  // turn left
    Serial.println("turn left");
    //go forward and turn left
    myservo.write(135);
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
    delay(500);
  }

  else {
    Serial.println("stop"); // defaults to sitting still if no sensors are reading
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, LOW);

  }


  }
