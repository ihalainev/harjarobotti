int EN1 = 13;
int IN1 = 12;
int IN2 = 11;

void setup(){
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
}
void loop(){
  moveForward();
  delay(1000);
  moveStop();
  delay(1000);
  moveBackward();
  delay(1000);
  turnLeft();
  delay(1000);
  turnRight();
  delay(1000);
}

void moveForward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void moveStop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void moveBackward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void turnLeft(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void turnRight(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
