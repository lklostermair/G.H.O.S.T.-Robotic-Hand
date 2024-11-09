#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

// Define the pins for the NRF24L01
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

// Define the servo pins
const int servoPins[] = {3, 5, 6, 9, 10};
Servo servos[5];  // Create an array of Servo objects

// Define the angle mappings for each servo
int servoAngles[5][2] = {
  {30, 170},  // Servo 1 angles for '0' and '1'
  {30, 160},  // Servo 2 angles for '0' and '1'
  {30, 160},  // Servo 3 angles for '0' and '1'
  {10, 140},  // Servo 4 angles for '0' and '1'
  {30, 180}   // Servo 5 angles for '0' and '1'
};

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bps
  radio.begin();       // Initialize the NRF24L01 module
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  // Attach servos to their respective pins
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  if (radio.available()) {
    char receivedData[6] = ""; // Buffer to store received data

    // Read the data
    radio.read(&receivedData, sizeof(receivedData));

    // Print the received data for debugging
    Serial.println(receivedData);

    // Decode the received data and move the servos
    for (int i = 0; i < 5; i++) {
      if (receivedData[i] == '1') {
        servos[i].write(servoAngles[i][1]);  // Set servo to the '1' angle
      } else if (receivedData[i] == '0') {
        servos[i].write(servoAngles[i][0]);  // Set servo to the '0' angle
      }
    }
  }

  delay(200); // Wait for a bit before checking for new data
}
