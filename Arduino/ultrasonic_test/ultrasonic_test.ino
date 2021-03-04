// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Original code by Arbi Abdul Jabbaar
// Edited by Veera Ihalainen
// Using Arduino IDE 1.8.13
// Using HC-SR04 Module
// ---------------------------------------------------------------- //

#define echoPin1 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin2 4 // attach pin D4 Arduino to pin Echo of HC-SR04
#define trigPin2 5 //attach pin D5 Arduino to pin Trig of HC-SR04
#define echoPin3 6 // attach pin D6 Arduino to pin Echo of HC-SR04
#define trigPin3 7 //attach pin D7 Arduino to pin Trig of HC-SR04

// defines variables
long duration1; // variable for the duration of sound wave travel
long duration2;
long duration3;
int distance1; // variable for the distance measurement
int distance2;
int distance3;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delay(50);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delay(100);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  //Second HC-SR04 sensor
  digitalWrite(trigPin2, LOW);
  delay(50);
  digitalWrite(trigPin2, HIGH);
  delay(100);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  //Third HC-SR04 sensor
  digitalWrite(trigPin3, LOW);
  delay(50);
  digitalWrite(trigPin3, HIGH);
  delay(100);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");
}
