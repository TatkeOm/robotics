int potPin = A0;
int ledPin = 9;
int PWM;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //Set LED pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(A0);
  PWM = potValue/4;
  analogWrite(ledPin, PWM);
}
