#include "Ultrasonic.h"
#include <Arduino.h>

void Ultrasonic::set_pin_nums(int trig_pin, int echo_pin) {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

int Ultrasonic::get_distance() {
  //code modified from: http://www.robot-electronics.co.uk/files/arduino_srf04.ino
  
  digitalWrite(trig_pin, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);                   // Send pin low again
  int distance = pulseIn(echo_pin, HIGH);        // Reads in the amount of time that the TRIG pulse runs for
  distance = distance/58;                        // Calculate distance from time of pulse
  return distance;
}

