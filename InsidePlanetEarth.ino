#include "LED.h"

#define LED_ARRAYS 4
#define LED_LOOPS_PER_ARRAY 3

#define SWITCH_PIN 52

/* Written by Owen Holloway [owen.holloway101@gmail.com]
 * on behalf of Suzanne Crowley
 *
 * Controls the InsidePlanetEarth LED arrays
 * http://github.com/Owen-Holloway101/InsidePlanetEarth
 * 
 * Three states exist
 * Waiting:
     Ultrasonic sensors are active and will cause
     tranisition to Displaying state when triggered
   
 * Displaying:
     The LED's are being controlled (faded in and out) 
     This is controlled in a semi random fashion.
     
 * StaticDisplay:
     This state is triggered when the switch is set
     to high (on) all the lights stay on constantly
     
*/

LED led[LED_ARRAYS][LED_LOOPS_PER_ARRAY];

int brightness = 0;
int brightChange = 2;

//setup runs once at the begining of the program
void setup() {
  
  
  //switch for state
  pinMode(SWITCH_PIN,INPUT);
  
  //for loop
    //makes a variable (iterate_a) and gives it a value (0)
    //checks that it is below a certain value (LED_ARRAYS)
    //then loops and changes the variable (iterate++)
  for (int iterate_a = 0; iterate_a < LED_ARRAYS; iterate_a++) {
    
    for (int iterate_b = 0; iterate_b < LED_LOOPS_PER_ARRAY; iterate_b++) {
      //defines the variables in the array led, each to a new LED instance. 
      led[iterate_a][iterate_b] = *new LED();
      
    }
    
  }
  
  led[0][0].set_pin_num(12);
  
  
}

//loop runs continually until the power runs out (or is swtiched off)
void loop() {  
  
  if (digitalRead(SWITCH_PIN) == LOW) {
    brightness = brightness + brightChange;
    led[0][0].set_brightness(brightness);
    delay(10);
  } else {
    delay(10);
  }
  
}
