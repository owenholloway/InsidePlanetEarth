#ifndef LED_H
#define LED_H

class LED {
  private:
    int led_num;
  public: 
    void set_led_num(int led_num_to_set);
    int get_led_num();
};

#endif
