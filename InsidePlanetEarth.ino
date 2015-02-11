#include "Ultrasonic.h"
#include "Loop.h"

#define SWITCH_PIN 53
#define SWITCH_POWER 51
#define STATUS_LED 48

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
     This is controlled in a semi random fashion.1
     
 * StaticDisplay:
     This state is triggered when the switch is set
     to high (on) all the lights stay on constantly
     
*/

Loop LED_loop[4];

int pins0[] = {2,3,4};
int pins1[] = {5,6,7};
int pins2[] = {8,9,10};
int pins3[] = {11,12,13};

//setup runs once at the begining of the program
void setup() {
  
  //switch for state
  pinMode(SWITCH_PIN,INPUT);
  pinMode(SWITCH_POWER,OUTPUT);
  pinMode(STATUS_LED,OUTPUT);
  
  digitalWrite(STATUS_LED,LOW); 
  digitalWrite(SWITCH_POWER,HIGH);
  
  LED_loop[0] = *new Loop();
  LED_loop[0].set_pins(pins0);
  
  LED_loop[1] = *new Loop();
  LED_loop[1].set_pins(pins1);
  
  LED_loop[2] = *new Loop();
  LED_loop[2].set_pins(pins2);  
  
  LED_loop[3] = *new Loop();
  LED_loop[3].set_pins(pins3);
}

//loop runs continually until the power runs out (or is swtiched off)
void loop() {
  
  if (digitalRead(SWITCH_PIN) == HIGH) {
    digitalWrite(STATUS_LED,HIGH);
    
    LED_loop[0].set_static_on(200);
    LED_loop[1].set_static_on(200);
    LED_loop[2].set_static_on(200);
    LED_loop[3].set_static_on(200);
    
  } else {
    digitalWrite(STATUS_LED,LOW);
    if (LED_loop[0].is_static_on) LED_loop[0].set_static_on(0);
    if (LED_loop[1].is_static_on) LED_loop[1].set_static_on(0);
    if (LED_loop[2].is_static_on) LED_loop[2].set_static_on(0);
    if (LED_loop[3].is_static_on) LED_loop[3].set_static_on(0);
  }
  
}
