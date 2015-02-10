#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
  private:
    //NA
  public:
    void set_pin_nums(int trig_pin, int echo_pin);
    int get_distance();
      
};

#endif
