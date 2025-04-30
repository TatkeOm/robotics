import processing.serial.*;

Serial myPort;  // Create object from Serial class
String distanceValue = "0"; 
int servoAngle = 0;

void setup() {
  size(400, 400);  // Set window size
  println(Serial.list());  // List available serial ports
  myPort = new Serial(this, Serial.list()[0], 9600); // Change index if needed

  myPort.bufferUntil('\n');  // Read until new line
}

void draw() {
  background(0);
  fill(255);

  // Display the ultrasonic sensor reading
  textSize(20);
  text("Distance: " + distanceValue + " cm", 50, 50);

  // Simulate the servo movement
  translate(width/2, height/2);
  float angle = radians(servoAngle);
  stroke(255);
  line(0, 0, 100 * cos(angle), 100 * sin(angle));
}

void serialEvent(Serial myPort) {
  String receivedData = myPort.readStringUntil('\n');
  if (receivedData != null) {
    receivedData = receivedData.trim();
    distanceValue = receivedData;

    // Simulate servo sweeping from 0 to 180 degrees
    servoAngle = (servoAngle + 1) % 181; 
  }
}
