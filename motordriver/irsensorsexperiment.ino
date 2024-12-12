#define in1 3     //motor driver in1 pin
#define in2 4     //motor driver in2 pin
#define in3 5     //motor driver in3 pin
#define in4 6     //motor driver in4 pin
#define ir1out 7  //1st ir pair output
#define ir2out 8  //2nd ir pair output

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ir1out, INPUT);
  pinMode(ir2out, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir1 = digitalRead(ir1out);
  int ir2 = digitalRead(ir2out);

  if (ir1 == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  if (ir2 == 0) {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
