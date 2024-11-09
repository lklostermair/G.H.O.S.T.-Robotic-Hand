#include <Servo.h>

// Define the servo pins
const int servoPins[] = {3, 5, 6, 9, 10};
Servo servos[5];  // Create an array of Servo objects

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bps

  // Attach servos to their respective pins
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
  }

  Serial.println("Servo Test Program");
  Serial.println("Enter servo number (1-5) and angle (0-180) separated by a space.");
  Serial.println("For example, '1 90' will set servo 1 to 90 degrees.");
}

void loop() {
  if (Serial.available() > 0) {
    // Read the input from the serial monitor
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any leading or trailing whitespace

    // Split the input into two parts: servo number and angle
    int spaceIndex = input.indexOf(' ');
    if (spaceIndex > 0) {
      String servoNumStr = input.substring(0, spaceIndex);
      String angleStr = input.substring(spaceIndex + 1);

      int servoNum = servoNumStr.toInt();
      int angle = angleStr.toInt();

      // Validate the servo number and angle
      if (servoNum >= 1 && servoNum <= 5 && angle >= 0 && angle <= 180) {
        // Set the corresponding servo to the specified angle
        servos[servoNum - 1].write(angle);
        Serial.print("Servo ");
        Serial.print(servoNum);
        Serial.print(" set to ");
        Serial.print(angle);
        Serial.println(" degrees.");
      } else {
        Serial.println("Invalid input. Please enter a servo number (1-5) and angle (0-180).");
      }
    } else {
      Serial.println("Invalid input. Please enter a servo number (1-5) and angle (0-180).");
    }
  }
}
