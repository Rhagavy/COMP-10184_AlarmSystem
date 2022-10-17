// I, Rhagavy Rakulan (000802106), certify that this material is my original work.
// No other person's work has been used without due acknowledgement. I have not made
// my work available to anyone.
#include <Arduino.h>

#define PIN_PIR D5//PIR Sensor
#define PIN_BUTTON D6//push button
bool bPIR;

// *************************************************************
void setup() {
 // configure the USB serial monitor
 Serial.begin(115200);
 // configure the LED output
 pinMode(LED_BUILTIN, OUTPUT);
 // PIR sensor is an INPUT
 pinMode(PIN_PIR, INPUT);
 // Button is an INPUT
 pinMode(PIN_BUTTON, INPUT_PULLUP);
}
// *************************************************************
void loop() {
mainloop:bPIR = digitalRead(PIN_PIR);
  // if motion is detected
  if(bPIR==1)
  {
    //blink 10 sec, 4blink per sec
    for(int i=0;i<=30;i++)
    {
      //check if button isn't pressed
      if(digitalRead(PIN_BUTTON)==0)
        while(1)
        {
         digitalWrite(LED_BUILTIN,0); 
         delay(200);
         if(digitalRead(PIN_BUTTON)==0)
         {
          //if button isn't pressed go back and keep checking for motion
           goto mainloop;
         }
        }
      //turn on LED
      digitalWrite(LED_BUILTIN,1);
      delay(125);
      if(digitalRead(PIN_BUTTON)==0)
        while(1)
        {
         digitalWrite(LED_BUILTIN,0);
         delay(200);
         if(digitalRead(PIN_BUTTON)==0)
         { //if button isn't pressed go back and keep checking for motion
           goto mainloop;
         } 
        }
      //turn off LED
      digitalWrite(LED_BUILTIN,0);
      delay(125);
    }
    //keep LED on until board is reset
    while(1)
    {
    digitalWrite(LED_BUILTIN,1);
    }
  }
} 