int in1Pin = 10;//Define L293D channel 1 pin
int in2Pin = 9;//Define L293D channel 2 pin
int enable1Pin = 11;//Define L293D enable 1 pin
int buttonPin = 3;
int ledPin = 13;
boolean rotation; //Define a variable to save the motor's rotation, true and false are represented by rotating or not rotating
int rotationSpeed = 255; //Define a variable to set the motor rotation speed to 255

void setup() {
  // put your setup code here, to run once:
  //Initialize the pins into an output mode
pinMode (in1Pin, OUTPUT);
pinMode (in2Pin, OUTPUT);
pinMode (enable1Pin, OUTPUT);
pinMode (ledPin, OUTPUT); //declare LED as output
pinMode (buttonPin, INPUT); //declare button as input
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(buttonPin)== LOW){ //LOW indicates that the button is pressed
  delay(10);
  Serial.println("Motor running");
  digitalWrite(ledPin, HIGH);
  runMotor(rotation, rotationSpeed);
}
else if(digitalRead(buttonPin)==HIGH){
  delay(10);
  Serial.println("Motor not running");
  digitalWrite(ledPin, LOW);
  stopMotor(rotation, rotationSpeed);
}
}

void runMotor(boolean rotation, int spd){
  if(rotation = true){
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
}

void stopMotor(boolean rotation, int spd){
  if(rotation = false){
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  }
}
