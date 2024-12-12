# define irpin 6
# define irpin2 7
# define irpin3 8
# define irpin4 9
//# define buzzer 5

void setup() {
  for (int i=6; i<=9; i++) {
  pinMode(i, INPUT);
  }
  //pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
int a = digitalRead(irpin);
int b = digitalRead(irpin2);
int c = digitalRead(irpin3);
int d = digitalRead(irpin4);


   if(a==0) {
  Serial.println("Intruder Alert, approaching from left");
  delay(100);
} else{Serial.println("safe");}
  
   if(b==0) {
  Serial.println("Intruder Alert, approaching from right");
  delay(100);
} 
   if(c==0) {
  Serial.println("Intruder Alert, approaching from front");
  delay(100);
} 
   if(d==0) {
  Serial.println("Intruder Alert, approaching from back");
  delay(100);
} 

}

