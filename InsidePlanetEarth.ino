#include "Ultrasonic.h"
#include "Loop.h"

#define SWITCH_PIN 53
#define SWITCH_POWER 51
#define STATUS_LED 48
#define ECHOPIN 35
#define TRIGPIN 33

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
int pins3[] = {11,44,45};  

//How many time to loop the lights before returning to 0
int lights_loop = 0;

//setup runs once at the begining of the program
void setup() {
  
  // open the serial port at 9600 bps:
  Serial.begin(9600);
  
  //switch for state
  pinMode(SWITCH_PIN,INPUT);
  pinMode(SWITCH_POWER,OUTPUT);
  pinMode(STATUS_LED,OUTPUT);
  
  digitalWrite(STATUS_LED,LOW); 
  digitalWrite(SWITCH_POWER,HIGH);
  
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  
  //Set pin 25 as a ground for use with ultrasonic
  pinMode(37,OUTPUT);
  digitalWrite(37,LOW);
  
  pinMode(31,OUTPUT);
  digitalWrite(31,HIGH);
  
  LED_loop[0] = *new Loop();
  LED_loop[0].set_pins(pins0);
  LED_loop[0].current_rotation = 0;
  
  LED_loop[1] = *new Loop();
  LED_loop[1].set_pins(pins1);
  LED_loop[1].current_rotation = 0;
  
  LED_loop[2] = *new Loop();
  LED_loop[2].set_pins(pins2);  
  LED_loop[2].current_rotation = 0;
  
  LED_loop[3] = *new Loop();
  LED_loop[3].set_pins(pins3);
  LED_loop[3].current_rotation = 0;
}

//loop runs continually until the power runs out (or is swtiched off)
void loop() {

  if (digitalRead(SWITCH_PIN) == HIGH) {
    digitalWrite(STATUS_LED,HIGH);
    
    lights_loop = 0;
    
    LED_loop[0].set_static_on(200);
    LED_loop[1].set_static_on(200);
    LED_loop[2].set_static_on(200);
    LED_loop[3].set_static_on(200);
    
  } else {
    
    digitalWrite(STATUS_LED,LOW);
    
    if (LED_loop[0].is_static_on) {
      LED_loop[0].set_static_on(0);
      LED_loop[0].is_static_on = false;
    }
    
    if (LED_loop[1].is_static_on) {
      LED_loop[1].set_static_on(0);
      LED_loop[1].is_static_on = false;
    }
    
    if (LED_loop[2].is_static_on) {
      LED_loop[2].set_static_on(0);
      LED_loop[2].is_static_on = false;
    }
    
    if (LED_loop[3].is_static_on) {
      LED_loop[3].set_static_on(0);
      LED_loop[3].is_static_on = false;
    }
    
    if (lights_loop > 0) {
      
      LED_loop[0].set_led_rotation(LED_loop[0].current_rotation + 1);
      LED_loop[1].set_led_rotation(LED_loop[1].current_rotation + 1);
      LED_loop[2].set_led_rotation(LED_loop[2].current_rotation + 1);
      LED_loop[3].set_led_rotation(LED_loop[3].current_rotation + 1);
      
      --lights_loop;
      
      delay(10);
      
    } else {
      
      LED_loop[0].set_static_on(0);
      LED_loop[1].set_static_on(0);
      LED_loop[2].set_static_on(0);
      LED_loop[3].set_static_on(0);
      
      digitalWrite(TRIGPIN, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIGPIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGPIN, LOW);
      int distance = pulseIn(ECHOPIN, HIGH);
      distance= distance/58;
      
      if(distance < 400) {
        
        randomSeed(analogRead(0));
        randomSeed(random(1000));
        
        lights_loop = 510*random(4, 10);
        
        LED_loop[0].current_rotation = random(0, 100) - 50;
        LED_loop[1].current_rotation = random(78, 178);
        LED_loop[2].current_rotation = random(205, 305);
        LED_loop[3].current_rotation = random(333, 433);
        
        Serial.print("Rand Values:");
        Serial.print(lights_loop/510);
        Serial.print(":");
        Serial.print(LED_loop[0].current_rotation);
        Serial.print(":");
        Serial.print(LED_loop[1].current_rotation);
        Serial.print(":");
        Serial.print(LED_loop[2].current_rotation);
        Serial.print(":");
        Serial.print(LED_loop[3].current_rotation);
        Serial.println("");
        
        Serial.print("Distance: ");
        Serial.println(distance);
        
        for (int i = 0; i < 254; i++) {
          LED_loop[0].set_static_on(i);
          LED_loop[1].set_static_on(i);
          LED_loop[2].set_static_on(i);
          LED_loop[3].set_static_on(i);
          delay(10);
        }
        
      }
      
    }
    
  }
  
}



