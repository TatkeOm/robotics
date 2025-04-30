const int trigPin = 5;
const int echoPin = 6;
#define M1a 10
#define M1b 9
#define M2a 11
#define M2b 12

#include Servo.h


float duration, ultraDistance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void forward() {
  digitalWrite(M1a, HIGH);
  digitalWrite(M1b, LOW);
  digitalWrite(M2a, HIGH);
  digitalWrite(M2b, LOW);
}

void backward() {
  digitalWrite(M1a, LOW);
  digitalWrite(M1b, HIGH);
  digitalWrite(M2a, LOW);
  digitalWrite(M2b, HIGH);
}

void turnLeft() {
  digitalWrite(M1a, LOW);
  digitalWrite(M2a, HIGH);
  digitalWrite(M1b, HIGH);
  digitalWrite(M2b, LOW);
}

void turnRight() {
  digitalWrite(M1a, HIGH);
  digitalWrite(M2a, LOW);
  digitalWrite(M1b, LOW);
  digitalWrite(M2b, HIGH);
}

void stop() {
  digitalWrite(M1a, LOW);
  digitalWrite(M1b, LOW);
  digitalWrite(M2a, LOW);
  digitalWrite(M2b, LOW);
}

int distance(){ 

  digitalWrite(trigPin,  LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10  micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the  echoPin, returns the sound wave travel time in microseconds
  ultraDistance= duration*0.034/2;
  Serial.println(ultraDistance);
  delay(20);
  return ultraDistance;
} 

void loop() {
  // put your main code here, to run repeatedly:
  ultraDistance = distance();

  if(ultraDistance > 20) {
    forward();
  } else{
    stop();
    delay(400);
    backward();
    delay(400);
    turnLeft();
    delay(400);
    forward();
  }

}
