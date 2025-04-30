#include "Servo.h";
#define redLed 3
#define yellowLed 4
#define greenLed 5
#define buzzer 6
#define trigPin 8
#define echoPin 9
#define servoPin 11

int distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  long time = pulseIn(echoPin, HIGH);
  int dist = time*0.034/2;
  return dist;
}

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    delay(15);
    int ultraDistance = distance();
    Serial.println(ultraDistance);

    if(ultraDistance > 200){
      digitalWrite(greenLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, LOW);
    } else if(ultraDistance > 100 && ultraDistance < 200) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, LOW);
    } else if(ultraDistance > 50 && ultraDistance < 100) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, HIGH);
      digitalWrite(buzzer, LOW);
    } else if(ultraDistance > 0 && ultraDistance < 50) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, HIGH);
    }
  }

  for (int angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    delay(15);
    int ultraDistance = distance();
    Serial.println(ultraDistance);

    if(ultraDistance > 200){
      digitalWrite(greenLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, LOW);
    } else if(ultraDistance > 100 && ultraDistance < 200) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, LOW);
    } else if(ultraDistance > 50 && ultraDistance < 100) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, HIGH);
      digitalWrite(buzzer, LOW);
    } else if(ultraDistance > 0 && ultraDistance < 50) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, HIGH);
    }
  }
}