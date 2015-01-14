#include "LED.h"

void LED::set_led_num(int led_num_to_set) {
  this->led_num = led_num_to_set;
}

int LED::get_led_num() {
  return this->led_num;
}
