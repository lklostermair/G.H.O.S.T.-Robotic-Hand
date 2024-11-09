#include <Servo.h>

Servo myServo;
int const flexsensor = A0;

void setup() {

  myServo.attach(6);
  pinMode(flexsensor, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  int Value;  
  int angle;
  Value = analogRead(flexsensor);
  Serial.print("Sensor: ");
  Serial.println(Value);

  angle = map (Value, 185, 300, 0 , 180);
  angle = constrain(angle, 0, 180);

  myServo.write(angle);

  delay(15);
  
  // put your main code here, to run repeatedly:

}
