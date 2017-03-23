void setup() {
  pinMode (7, INPUT);// LEFT 
  pinMode (6, INPUT);// RIGHT 
  pinMode (5, INPUT); // FORWARD 
  pinMode (11, OUTPUT); // left motor 
  pinMode (3, OUTPUT); // Right Motor 

}

void loop() {

  if (HIGH == digitalRead(7) ) { // TURNING LEFT 
    analogWrite(11, 255); 
    analogWrite (3, 100);    
  } else if (HIGH == digitalRead(6) ) { // TURNING RIGHT
    analogWrite(3, 255); 
    analogWrite(11, 100); 
    
  }else if (HIGH == digitalRead(5) ) { // GOING Forward
    analogWrite(11, 255);    
    analogWrite (3, 255);
  } 
  else {
    analogWrite (11, 0);
    analogWrite (3, 0); 
  }
  
}
