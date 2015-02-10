#ifndef LED_H
#define LED_H

class Loop {
  private:
    int pins[4];
  public:
    void set_pins(int pins[]);
    int* get_pins();
};

#endif
