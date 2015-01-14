#include "LED.h"
#define LED_ARRAYS 4
#define LED_LOOPS_PER_ARRAY 3

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

//setup runs once at the begining of the program
void setup() {
  //for loop
    //makes a variable (iterate_a) and gives it a value (0)
    //checks that it is below a certain value (LED_ARRAYS)
    //then loops and changes the variable (iterate++)
  for (int iterate_a = 0; iterate_a < LED_ARRAYS; iterate_a++) {
    
    for (int iterate_b = 0; iterate_b < LED_LOOPS_PER_ARRAY; iterate_b++) {
      
      led[iterate_a][iterate_b] = *new LED();
      
    }
    
  }
  
  led[0][0].set_pin_num(12);
  
  
}

//loop runs continually until the power runs out (or is swtiched off)
void loop() {  
  
  
  for (int i = 0; i < 255; i++) {
     led[0][0].set_brightness(i);
     delay(10);
  }
  
  for (int i = 255; i > 0; i--) {
     led[0][0].set_brightness(i);
     delay(10);
  }
  
}
