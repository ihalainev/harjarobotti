void setup(){
  pinMode (5, OUTPUT);
}

void loop(){
  analogWrite(5, 125);
  delay(1000);
  analogWrite(5, 75);
  delay(1000);
}
