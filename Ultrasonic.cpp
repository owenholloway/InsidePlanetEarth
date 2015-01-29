#include "Ultrasonic.h"
#include <Arduino.h>

void Ultrasonic::set_pin_nums(int trig_pin, int echo_pin) {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

int Ultrasonic::get_distance() {
  //code from: http://www.robot-electronics.co.uk/files/arduino_srf04.ino
  
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance= distance/58;                        // Calculate distance from time of pulse
  return distance;
}
