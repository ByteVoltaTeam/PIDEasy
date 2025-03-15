#include "PIDEasy.h"
#include <Arduino.h> // Necessário para constrain() no Arduino

PID::PID(float kp, float ki, float kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
  previous_error = 0;
  previous_derivative = 0;
  integral = 0;
  setWindUP(-1000, 1000);
  derivative_smoothing = 1.0;
}

float PID::compute(float error, unsigned long dt) {
  if (dt == 0) dt = 1;  

  integral += error * dt;
  integral = constrain(integral, min_windup, max_windup);

  if ((error > 0 && previous_error < 0) || (error < 0 && previous_error > 0)) {
      integral *= dampingFactor;
  }

  float derivative = (error - previous_error) / dt;
  derivative = (derivative_smoothing * derivative) + ((1 - derivative_smoothing) * previous_derivative);

  float output = (kp * error) + (ki * integral) + (kd * derivative);

  previous_error = error;
  previous_derivative = derivative;

  return constrain(output, min_constrain, max_constrain);
}

void PID::setConstrain(int min, int max) {
  this->min_constrain = min;
  this->max_constrain = max;
}

void PID::setSmoothingDerivate(float sD) {
  this->derivative_smoothing = sD;
}

void PID::setWindUP(float min, float max) {
  this->min_windup = min;
  this->max_windup = max;
}

void PID::setDampingFactor(float dF) {
  this->dampingFactor = dF;
}
