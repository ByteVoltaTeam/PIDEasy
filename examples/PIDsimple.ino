#include "PIDEasy.h"

PID lineFollower(1.0, 0.0, 0.0); // Kp, Ki, Kd

int error = 0;
const int setPoint = 10;

void setup() {
  Serial.begin(9600);
  lineFollower.setConstrain(-100, 100); // set Constrain for output of PID 
  lineFollower.setWindUP(-100, 100); // set Constrain for Integral
}

void loop() {
  int measurement = analogRead(A0); // Sensor Measurement
  error = measurement - setPoint;
  float output = lineFollower.compute(error, 1); // (error, dt), if do you not want to use dt only put 1 in parameter.

  Serial.println("Output:   " + String(output));
}
