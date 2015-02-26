#include "Loop.h"
#include <Arduino.h>

void Loop::set_pins(int pins[]) {
  is_static_on = false;
  current_rotation = 0;
  
  led[0] = *new LED();
  led[1] = *new LED();
  led[2] = *new LED();
  
  led[0].set_pin_num(pins[0]);
  led[1].set_pin_num(pins[1]);
  led[2].set_pin_num(pins[2]);
  
}

void Loop::set_led_rotation(int rotation) {
  
  current_rotation = rotation%510;
  
  //Serial.println("Rotation:" + current_rotation);
  
  led[0].set_brightness( abs(((rotation + 000)%510) - 255));
  led[1].set_brightness( abs(((rotation + 170)%510) - 255));
  led[2].set_brightness( abs(((rotation + 340)%510) - 255));
  
}

void Loop::set_static_on(int brightness) {
  led[0].set_brightness(brightness);
  led[1].set_brightness(brightness);
  led[2].set_brightness(brightness);
  
  is_static_on = true;
}


