#include <stdio.h>
#include <stdlib.h>

int in1pin = 6;
int in2pin = 7; // h bridge pins
const int Button = 8; //Arduino pin connected to button's pin

int motorState = LOW; //current state of motor
int lastButtonState; //previous state of button
int currentButtonState; //current state of button

unsigned long lastDebounceTime = 0; //the last time the output pin was toggled
unsigned long debounceDelay = 50; //the debounce time; increase if the output flickers


void setup() {
  Serial.begin(9600); // initialize serial
  pinMode(in1pin, OUTPUT);
  pinMode(in2pin, OUTPUT); // outputs

  pinMode(Button, INPUT_PULLUP); // input w internal pullup resistor
  //pinMode(led, OUTPUT); //set arduino pin to output mode
  digitalWrite(in1pin, motorState);
}

void loop() {

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
  digitalWrite(in1pin, motorState);
  //save the reading; next time through the loop, it'll be the lastButtonState
  lastButtonState = reading;
}
