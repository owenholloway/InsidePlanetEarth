#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
  private:
    int trig_pin;
    int echo_pin;
  public:
    
    /*
    * Sets the pin's to be used by the SRF05.
    * 2 digital pins required for the control
    */
    void set_pin_nums(int trig_pin, int echo_pin);
    
    /*
    * Gets the distance reading from the sensor
    * takes 12ms as the sensor is activated and read in this period 
    */
    
    int get_distance();
      
};

#endif
