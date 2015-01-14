#include "LED.h"
#include <Arduino.h>

void LED::set_pin_num(int pin_num_to_set) {
  //Set the pin num in *this* instance of LED
  this->pin_num = pin_num_to_set;
  
  pinMode(pin_num,OUTPUT);
}

int LED::get_pin_num() {
  
  return this->pin_num;
}

void LED::set_brightness(int brightness_to_set) {
  
  this->brightness = brightness_to_set;
  
  analogWrite(pin_num, brightness);
  
}
