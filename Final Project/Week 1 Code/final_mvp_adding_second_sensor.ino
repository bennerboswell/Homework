/*
// this code did not work but is my attempt to add a secondoary sensor to the first code 
*/

#define trigPin 3 // fron sensor 
#define echoPin 2 // front sensor 
#define trigPinback 5 // rear sensor
#define echoPinback 4 // rear sensor 
#define motor1 11 // forward
#define motor2 12 // backward 

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPinback, OUTPUT);
  pinMode(echoPinback, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

void loop() {
  long duration, distance; // code for converting sensor data to CM 
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  

  long durationback, distanceback; // code for converting sensor data to CM 
  digitalWrite(trigPinback, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPinback, HIGH);
  delayMicroseconds(10); // 
  digitalWrite(trigPinback, LOW);
  durationback = pulseIn(echoPinback, HIGH);
  distanceback = (durationback / 2) / 29.1;
  {
    if (distance < 10) {  // turrning around
      digitalWrite(motor1, HIGH); //
      digitalWrite(motor2, LOW);
    }
    if (distanceback < 10) {  // turrning around
      digitalWrite(motor1, LOW); //
      digitalWrite(motor2, HIGH);
    }
    if (distance = distanceback) {  // turrning around
      digitalWrite(motor1, HIGH); //
      digitalWrite(motor2, LOW);
    }


    else {
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, HIGH);
    }
    if (distance >= 200 || distance <= 0) {
      Serial.println("Out of range");
    }
    else {
      Serial.print(distance);
      Serial.println(" cm");
      Serial.print(distanceback);
      Serial.println(" cm back");

    }
    delay(500);


  }
}



