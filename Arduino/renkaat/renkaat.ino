#include <NewPing.h>

#define maxDistance 200
#define maxSpeed 190
#define maxSpeedOffset 20

int in1Pin = 10; // Define L293D channel 1 pin
int in2Pin = 9; // Define L293D channel 2 pin
int enable1Pin = 11; // Define L293D enable 1 pin
int in3Pin = 7;
int in4Pin = 6;
int enable2Pin = 8;

int echoPin1 = 2;
int trigPin1 = 3;

boolean goesForward = false;
int distance = 100;
int speedSet = 0;


NewPing sonar (trigPin1, echoPin1, maxDistance); 

void setup() {
 // Initialize the pin into an output mode:
 pinMode(in1Pin, OUTPUT);
 pinMode(in2Pin, OUTPUT);
 pinMode(enable1Pin, OUTPUT);
 pinMode(in3Pin, OUTPUT);
 pinMode(in4Pin, OUTPUT);
 pinMode(enable2Pin, OUTPUT);
}
void loop() {
 //int distanceR = 0;
 //int distanceL = 0;
 //int distanceC = 0;
 //delay(40);
// moveForward();
   digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
}

void moveStop(){
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);
}

void moveForward(){
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
}

/*void driveMotor(boolean dir, int spd) {
 // Control motor rotation direction
 if (dir) {
 digitalWrite(in1Pin, HIGH);
 digitalWrite(in2Pin, LOW);
 }
 else {
 digitalWrite(in1Pin, LOW);
 digitalWrite(in2Pin, HIGH);
 }
 // Control motor rotation speed
 analogWrite(enable1Pin, constrain(spd, 0, 255));
}*/
