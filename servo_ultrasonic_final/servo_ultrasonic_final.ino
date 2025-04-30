const int trigPin = 5;
const int echoPin = 6;

#define M1a 10
#define M1b 9
#define M2a 11
#define M2b 12

float duration, distance;


// Include the servo library:
#include "Servo.h"

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 8

void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
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


int calculateDistance(){ 
 
  digitalWrite(trigPin,  LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10  micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the  echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
} 

void loop() {
// Servo Motor Basic Code
  
  distance = calculateDistance();
  int leftDistance = calculateDistance();
  int rightDistance = calculateDistance();

  if(distance < 40) {
    stop();
    myservo.write(0);
    myservo.write(180);
  } else{
    forward();
  }

  if(leftDistance > rightDistance) {
    turnLeft();
    delay(400);
    forward();
  } else{
    turnRight();
    delay(400);
    forward();
  }
    

// Basic Ultrasonic Sensor Code

  /*digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  //delay(100);*/
}