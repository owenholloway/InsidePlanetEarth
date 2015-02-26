#ifndef LED_H
#define LED_H

#include "LED.h"

class LED {
  private:
    int pin_num;
    int brightness;
  public: 
  
    /*
    * Sets the pin to be used in output for this LED group
    * should be a PWM pin
    * 
    * also sets this pin as an output
    */
    void set_pin_num(int pin_num_to_set);
    
    /*
    * gets the pin used as output
    */
    int get_pin_num();
    
    /*
    * sets the brightness of the LED 
    */
    void set_brightness(int brightness_to_set);
    
    /*
    * returns the brightness of the LED
    */
    
    int get_brightness();
};

#endif


