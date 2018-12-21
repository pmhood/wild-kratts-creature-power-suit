#include <Adafruit_CircuitPlayground.h>
#include "ExternalStrip.h"
#include "CreaturePowerSuit.h"

CreaturePowerSuit* suit;
bool pressedButton = false;

void setup() {  
//  suit.reset();
//  pressedButton = false;
  Serial.begin(9600);
//  while (! Serial);
  Serial.println("begin()");
  
  // Setup 3 external NeoPixels for paw  
  CircuitPlayground.begin();
  ExternalStrip.begin();
  
   suit = new CreaturePowerSuit(chris);
//   suit = new CreaturePowerSuit(martin);

//  CircuitPlayground.setAccelTap(1, 10);
}



void loop() {
  // put your main code here, to run repeatedly:
//    CircuitPlayground.redLED(HIGH);
//    delay(500);
//    CircuitPlayground.redLED(LOW);
//    delay(500);

//  CircuitPlayground.setPixelColor(0, 0x000010);
//  CircuitPlayground.setPixelColor(1, 0x000015);
//  CircuitPlayground.setPixelColor(2, 0x00001a);
//  CircuitPlayground.setPixelColor(3, 0x00001f);
//  return;

  // 1. Inputs
  if(!pressedButton) {
    pressedButton = CircuitPlayground.leftButton();
    if(pressedButton) {
      Serial.println("in here!");
      suit->activateCreaturePower();
    }
  }

  // 2. Updates
  suit->update(millis());

  // 3. Render
  suit->render();

}
