#include <Servo.h>

Servo myservo;  // create servo object to control a servo
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int numberOfPositions = 5; // litterally counted
int positions[] = {17, 86, 23, 140, 47}; // array


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);


}
void loop() {
  buttonState = digitalRead(buttonPin);  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {  // if the state has changed, increment the counter
    if (buttonState == HIGH) {          // if the current state is HIGH then the button
                                         // went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
      int index = buttonPushCounter % numberOfPositions ; // position for array

      Serial.print("moving to index = ");
      Serial. println(index);           //hopefully prints intindex from above

      myservo.write(positions[index]); // hopefully writes int index from above, moving throug the aray in order
      delay(1000);
    }
  }

  else {
    // if the current state is LOW then the button
    // wend from on to off:
    Serial.println("off");
  }
  // Delay a little bit to avoid bouncing
  delay(50);
  lastButtonState = buttonState;
}


