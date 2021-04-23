#include <stdio.h>
#include <stdlib.h>

const int motor1Pin = 5; //motorpin, duh
//const int divider = 3;
int motorSpeed = 20; //motor speed
const int Button = 3; //Arduino pin connected to button's pin

int motorState = LOW; //current state of motor
int lastButtonState; //previous state of motor
int currentButtonState; //current state of button

unsigned long lastDebounceTime = 0; //the last time the output pin was toggled
unsigned long debounceDelay = 50; //the debounce time; increase if the output flickers

void setup()
{
  Serial.begin(57600); //initialize serial
  pinMode(motor1Pin, OUTPUT); //output
  pinMode(Button, INPUT_PULLUP); //intput w internal pullup resistor
  digitalWrite(motor1Pin, motorState);
  //analogWrite (motor1Pin, motorSpeed);
}

void loop() {

  analogWrite(motor1Pin, motorSpeed);
  //read the state of the switch into a local variable
  int reading = digitalRead(Button);

  //check to see if you just pressed the button
  //(i.e. the input went from LOW to HIGH), and you've waited long enough
  //since the last press to ignore any noise

  //if the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    //reset the debouncing timer
    lastDebounceTime = millis();
    Serial.println("Keskeytys");
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    //whatever the reading is at, it's been there for longer than the debounce
    //delay, so take it as the actual current state:

    //if the button state has changed:
    if (reading != currentButtonState) {
      currentButtonState = reading;
      // only toggle the motor if the new button state is high
      if (currentButtonState == HIGH) {
        Serial.println("Button state low!");
        motorState = !motorState;
      }
    }
  }
  //set the motor:
  digitalWrite(motor1Pin, motorState);
  //save the reading; next time through the loop, it'll be the lastButtonState
  lastButtonState = reading;
}
