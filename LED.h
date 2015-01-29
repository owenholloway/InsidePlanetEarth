#ifndef LED_H
#define LED_H

class LED {
  private:
    int pin_num;
    int brightness;
  public: 
    void set_pin_num(int pin_num_to_set);
    int get_pin_num();
    void set_brightness(int brightness_to_set);
    int get_brightness();
};

#endif
