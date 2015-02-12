#ifndef LOOP_H
#define LOOP_H

#include "LED.h"

class Loop {
  
  private:
    LED led[3];
    
  public:
    //Variables
    
    //is the loop in a static state currently
    bool is_static_on;
    int current_rotation;
    
    //Functions
    
    /*
    * Sets the pins to be used on output, 3 pins these should be PWM capable
    * sets "is_static_on" as false to avoid incorrect reads
    */
    void set_pins(int pins[]);
    
    /*
    * Returns the 3 pins used for outpus
    */
    int* get_pins();
    
    /*
    * abs(((rotation + 170) % 510) - 255)
    * used to set the brightness for the LED's at 120 degrees from each other
    * 0,510 high 255 low 
    */
    
    void set_led_rotation(int rotation);
    
    int get_led_rotation();
    
    /*
    * Set the loop to be staticly on at the given brightness
    */
    
    void set_static_on(int brightness);
};

#endif
