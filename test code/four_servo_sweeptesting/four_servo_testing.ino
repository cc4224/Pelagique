  #include <Servo.h>

Servo servo1;  // create servo objects for each of the four servos
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Attach each servo to a corresponding pin
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
}

void loop() {
  // Sweep the first three servos from 0 to 180 degrees, and the fourth from 90 to 180 degrees
  for (int pos = 0; pos <= 180; pos++) {
    servo1.write(pos);        // Control servo1
    servo2.write(pos);        // Control servo2
    servo3.write(pos);        // Control servo3

    int pos4 = map(pos, 0, 180, 90, 180); // Map the range of pos to 90-180 for servo4
    servo4.write(pos4);       // Control servo4 with mapped position

    delay(15);                // Adjust delay for smoother or faster sweep
  }

  // Sweep back the first three servos from 180 to 0 degrees, and the fourth from 180 to 90 degrees
  for (int pos = 180; pos >= 0; pos--) {
    servo1.write(pos);        // Control servo1
    servo2.write(pos);        // Control servo2
    servo3.write(pos);        // Control servo3

    int pos4 = map(pos, 0, 180, 90, 180); // Map the range of pos to 90-180 for servo4
    servo4.write(pos4);       // Control servo4 with mapped position

    delay(15);                // Adjust delay as needed
  }
}
