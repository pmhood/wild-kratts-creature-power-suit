#include "CreaturePowerSuit.h"
#include <stddef.h>
#include <Adafruit_CircuitPlayground.h>

#include "CreaturePowerSuitActivateAnimation.h"
#include "CreaturePowerSuitIdleAnimation.h"
#include "CreaturePowerSuitOnAnimation.h"

CreaturePowerSuit::CreaturePowerSuit(KrattBrother brother): state(uninitialized), animation(NULL) {    
}

CreaturePowerSuit::~CreaturePowerSuit() {
  delete animation;
}

void CreaturePowerSuit::reset() {
  resetAnimation();
  state = uninitialized;
}

void CreaturePowerSuit::resetAnimation() {
    if(animation) {
      delete animation;
      animation = NULL;
    }
}

void CreaturePowerSuit::activateCreaturePower() {
    resetAnimation();
    Serial.println("state=>activate");
    state = activate;    
    animation = new CreaturePowerSuitActivateAnimation();
    Serial.println(animation != 0);
}

void CreaturePowerSuit::update(unsigned long time) {
    updateState();

    if(animation) {
      animation->update(time);
    }
}

void CreaturePowerSuit::render() {
    if(animation) {
      animation->render();
    }
}

void CreaturePowerSuit::updateState() {
    switch(state) {
        case uninitialized:
            resetAnimation();
            state = idle;
            animation = new CreaturePowerSuitIdleAnimation();
            break;

        case activate:
           if(animation->isAnimationComplete()) {
               resetAnimation();
               state = on;
               animation = new CreaturePowerSuitOnAnimation();
           }
        break;
    }
}
