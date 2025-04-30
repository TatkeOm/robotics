  #include <Arduino.h>
  //no semi colon for #define!!
  #define anode 5
  #define cathode 6
void setup() {
  // put your setup code here, to run once:
  pinMode(anode, OUTPUT);
  pinMode(cathode, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(anode, HIGH);
  digitalWrite(cathode, LOW);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
 
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(500);
  digitalWrite(10, LOW);
  delay(500);
}
