// C++ code
//

#include <LiquidCrystal_I2C.h>

#define trigPin 4
#define echoPin 3

float duration, ultraDistance;

int seconds = 0;


#include "Servo.h"

// Create a new servo object:
Servo myservo;

int pos = 0;

// Define the servo pin:
#define servoPin 8

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  myservo.attach(servoPin);
  pinMode(4,OUTPUT);
  pinMode(3, INPUT);
  
  lcd.begin();
}

void loop() {

  digitalWrite(trigPin,  LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int time = pulseIn(echoPin, HIGH);
  float dist = 0.034*time/2;
  lcd.print("Distance Cal");
  lcd.setCursor(0, 1);
  lcd.print("Distance= ");
  lcd.print(dist);

for (pos = 0; pos <= 180; pos += 1) {
  myservo.write(pos);
  delay(15);
}

for(pos = 180; pos >=0; pos -= 1) {
  myservo.write(pos);
  delay(15);
}
  

}