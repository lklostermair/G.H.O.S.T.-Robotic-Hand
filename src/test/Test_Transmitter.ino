///INITIALIZATION

#include <Servo.h>

// Create Servo objects for each finger
Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo pinkie;

// Helper function to clamp the servo position between 0 and 120
int clamp(int value, int minVal, int maxVal) {
  if (value < minVal) return minVal;
  if (value > maxVal) return maxVal;
  return value;
}

///MODES

// Function for human like hand opening/closing
void mode_wave() {
  // Move fingers simultaneously but with different starting positions
  for (int pos = 0; pos <= 120; pos++) {
    thumb.write(clamp(pos, 0, 120));      // Thumb starts from 0
    index.write(clamp(pos - 10, 0, 120)); // Index finger starts from an offset
    middle.write(clamp(pos - 20, 0, 120)); // Middle finger starts from a bigger offset
    ring.write(clamp(pos - 30, 0, 120));  // Ring finger starts from a bigger offset
    pinkie.write(clamp(pos - 40, 0, 120)); // Pinkie finger starts from an even bigger offset

    delay(15);
  }

  delay(2000); // Wait 1 second

  // Reverse the motion back to fully open
  for (int pos = 120; pos >= 0; pos--) {
    thumb.write(clamp(pos, 0, 120));      // Thumb
    index.write(clamp(pos - 10, 0, 120)); // Index finger with offset
    middle.write(clamp(pos - 20, 0, 120)); // Middle finger with offset
    ring.write(clamp(pos - 30, 0, 120));  // Ring finger with offset
    pinkie.write(clamp(pos - 40, 0, 120)); // Pinkie finger with offset

    delay(15); // Short delay to make the movement smooth
  }

  delay(2000); // Wait 1 second
}

// Function for a bringing hand into travel position
void mode_travel() {
  // Fully close the hand
  for (int pos = 0; pos <= 60; pos++) {
    thumb.write(clamp(pos, 0, 60));    // Thumb
    index.write(clamp(pos, 0, 60));    // Index finger
    middle.write(clamp(pos, 0, 60));   // Middle finger
    ring.write(clamp(pos, 0, 60));     // Ring finger
    pinkie.write(clamp(pos, 0, 60));   // Pinkie finger

    delay(15); // Short delay to make the movement smooth
  }

}

// Function for a simple open/close movement (example for "mode2")
void mode_grasp() {
  // Fully close the hand
  for (int pos = 0; pos <= 120; pos++) {
    thumb.write(clamp(pos, 0, 120));    // Thumb
    index.write(clamp(pos, 0, 120));    // Index finger
    middle.write(clamp(pos, 0, 120));   // Middle finger
    ring.write(clamp(pos, 0, 120));     // Ring finger
    pinkie.write(clamp(pos, 0, 120));   // Pinkie finger

    delay(15); // Short delay to make the movement smooth
  }

  delay(1000); // Wait 1 second

  // Fully open the hand
  for (int pos = 120; pos >= 0; pos--) {
    thumb.write(clamp(pos, 0, 120));    // Thumb
    index.write(clamp(pos, 0, 120));    // Index finger
    middle.write(clamp(pos, 0, 120));   // Middle finger
    ring.write(clamp(pos, 0, 120));     // Ring finger
    pinkie.write(clamp(pos, 0, 120));   // Pinkie finger

    delay(15); // Short delay to make the movement smooth
  }

  delay(1000); // Wait 1 second
}

// Function for peace signs
void mode_peace() {
  // Fully close the hand
  for (int pos = 0; pos <= 120; pos++) {
    thumb.write(clamp(pos, 0, 120));    // Thumb
    ring.write(clamp(pos, 0, 120));     // Ring finger
    pinkie.write(clamp(pos, 0, 120));   // Pinkie finger

    delay(15); // Short delay to make the movement smooth
  }

  delay(2000); // Wait 1 second

  // Fully open the hand
  for (int pos = 120; pos >= 0; pos--) {
    thumb.write(clamp(pos, 0, 120));    // Thumb
    ring.write(clamp(pos, 0, 120));     // Ring finger
    pinkie.write(clamp(pos, 0, 120));   // Pinkie finger

    delay(15); // Short delay to make the movement smooth
  }

  delay(2000); // Wait 1 second
}

///MAIN SCRIPT


void setup() {
  // Attach each servo to the appropriate pin
  thumb.attach(9);    // Thumb on pin 9
  index.attach(10);   // Index finger on pin 10
  middle.attach(6);   // Middle finger on pin 6
  ring.attach(3);     // Ring finger on pin 3
  pinkie.attach(5);   // Pinkie finger on pin 5

  // Set all servos to fully open (0 degrees)
  thumb.write(0);    // Thumb to 0 degrees (open)
  index.write(0);    // Index finger to 0 degrees (open)
  middle.write(0);   // Middle finger to 0 degrees (open)
  ring.write(0);     // Ring finger to 0 degrees (open)
  pinkie.write(0);   // Pinkie finger to 0 degrees (open)

  delay(2000); // Wait 1 second
}

void loop() {
  String mode = "mode_wave";  // Change this string to "mode1", "mode2", etc. to select the mode

  // Execute different hand movements based on the mode string
  if (mode == "mode_wave") {
    mode_wave(); 

  } else if (mode == "mode_travel") {
    mode_peace();

  } else if (mode == "mode_grasp") {
    mode_grasp();

  } else if (mode == "mode_peace") {
    mode_peace(); // Execute mode2
  }
}
