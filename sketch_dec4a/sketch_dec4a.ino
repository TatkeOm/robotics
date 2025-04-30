

void setup() {
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);

  

}

void loop() {

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  analogWrite(10, 50);

  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  analogWrite(5, 50);
}


