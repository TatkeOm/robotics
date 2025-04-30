int M1a = 5;
int M1b = 6;
int M2a = 11;
int M2b = 10;
int IR = A0;
int signal;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1a,OUTPUT);
  pinMode(M1b,OUTPUT);
  pinMode(M2a,OUTPUT);
  pinMode(M2b,OUTPUT);
  pinMode(IR,INPUT);

  Serial.begin(9600);
}

void forward()
{
  digitalWrite(M1a,HIGH);
  digitalWrite(M1b,LOW);
  digitalWrite(M2a,HIGH);
  digitalWrite(M2b,LOW);
}

void backward()
{
  digitalWrite(M1a,LOW);
  digitalWrite(M1b,HIGH);
  digitalWrite(M2a,LOW);
  digitalWrite(M2b,HIGH);
}

void stop()
{
  digitalWrite(M1a,LOW);
  digitalWrite(M1b,LOW);
  digitalWrite(M2a,LOW);
  digitalWrite(M2b,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  signal = digitalRead(IR);
  Serial.println(signal);
  //signal = 1, no obstracle, forward
  //signal = 0, obtracle, stop
  if (signal == 1) {
    forward();
    Serial.println("Forward");
  } 
  if(signal == 0) {
    backward();
    Serial.println("Backward");
  } 
}