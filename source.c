// Servo code modified from http://www.arduino.cc/en/Tutorial/Sweep

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position



// this constant won't change:
const int  buttonPin = 12;    // the pin that the pushbutton is attached to
//const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


void setup() {
     pinMode(buttonPin, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);           //  setup serial
    analogWrite(6, 0);
}

bool color = true;
bool servoMove = false;
bool mode = false;

int servoPosition = 0;
int lastCol = 0;
int servoTarget = 0;

void loop() {

////  analogWrite(3, 0);
//  analogWrite(5, 0);
     // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
   if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      mode = !mode;
    } else {
    }
    // if the state has changed, increment the counter

    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  int val = analogRead(A5);  // read the input pin
//  Serial.println(val);          // debug value
  if (mode == color) {
    Serial.println("color");
    analogWrite(6, map(val, 0, 550, 255, 0));
  } else {
    Serial.println("servo");
    servoTarget = map(val, 0, 550, 180, 0);
    Serial.println(servoTarget);
    int servoVal =  servoPosition + (servoTarget - servoPosition) / abs(servoTarget - servoPosition);
    Serial.println(servoVal);
    myservo.write(servoVal);
    servoPosition = servoVal;
    
  }

  delay(15);
}
