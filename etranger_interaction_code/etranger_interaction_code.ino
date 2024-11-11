#include <Servo.h>

Servo myservo1;  // create Servo object to control servo 1
Servo myservo2;  // create Servo object to control servo 2
Servo myservo3;  // create Servo object to control servo 3

int pos = 0;  // variable to store the servo position
int blinkCode = -1;  // variable to store the command from serial input

void setup() {
  Serial.begin(9600);  // initialise serial communication

  myservo1.attach(9);  // attaches the servo on pin 9
  myservo2.attach(10); // attaches the servo on pin 10
  myservo3.attach(11); // attaches the servo on pin 11
}

void loop() {
  // Wait for a message to arrive
  if (Serial.available()) {
    blinkCode = Serial.read();  // Read the command from serial input
  }

  switch (blinkCode) {
    case 1:
      // Case 1: All three servos move back and forth within a small range (about 20 degrees)
      for (int i = 0; i < 20; i++) {
        myservo1.write(0); myservo2.write(0); myservo3.write(0);
        delay(500);
        myservo1.write(20); myservo2.write(20); myservo3.write(20);
        delay(500);
      }
      break;

    case 2:
      // Case 2: Each servo moves sequentially, each by 30 degrees
      for (int i = 0; i < 3; i++) {
        myservo1.write(30); delay(500);  // Move servo 1 to 30 degrees
        myservo1.write(0);               // Reset to 0
        myservo2.write(30); delay(500);  // Move servo 2 to 30 degrees
        myservo2.write(0);               // Reset to 0
        myservo3.write(30); delay(500);  // Move servo 3 to 30 degrees
        myservo3.write(0);               // Reset to 0
      }
      break;

    case 3:
      // Case 3: All three servos move from 0 to 180 degrees
      for (pos = 0; pos <= 180; pos += 1) {
        myservo1.write(pos);
        myservo2.write(pos);
        myservo3.write(pos);
        delay(15);
      }
      break;

    case 4:
      // Case 4: All three servos move from 180 to 0 degrees
      for (pos = 180; pos >= 0; pos -= 1) {
        myservo1.write(pos);
        myservo2.write(pos);
        myservo3.write(pos);
        delay(15);
      }
      break;
  }
}
