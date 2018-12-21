#include "CreaturePowerSuitActivateAnimation.h"


CreaturePowerSuitActivateAnimation::CreaturePowerSuitActivateAnimation() : state(uninitialized), onboardColorChanger(NULL), externalColorChanger(NULL) {
}

CreaturePowerSuitActivateAnimation::~CreaturePowerSuitActivateAnimation() {
    if(onboardColorChanger) {
        delete onboardColorChanger;
    }
    if(externalColorChanger) {
        delete externalColorChanger;
    }
}

void CreaturePowerSuitActivateAnimation::resetAnimation() {
    Serial.println("resetAnimation()");
    if(onboardColorChanger) {
        delete onboardColorChanger;
        onboardColorChanger = NULL;
    }
    if(externalColorChanger) {
        delete externalColorChanger;    
        externalColorChanger = NULL;
    }
    Serial.println("resetAnimation() complete");
}

void CreaturePowerSuitActivateAnimation::update(unsigned long time) {
    updateState();

   if(onboardColorChanger) {
       onboardColorChanger->update(time);
   }
   if(externalColorChanger) {
       externalColorChanger->update(time);
   }
}


void CreaturePowerSuitActivateAnimation::render() {
    CircuitPlayground.setBrightness(30);

    if(onboardColorChanger) {
        onboardColorChanger->render();
    }
    if(externalColorChanger) {
        externalColorChanger->render();
    }
}


void CreaturePowerSuitActivateAnimation::updateState() {
   switch(state) {
       case uninitialized:
           switchToColorBlink();
           break;

       case colorBlink:
          Serial.println("updateState::colorBlink");
           if(onboardColorChanger && externalColorChanger && onboardColorChanger->getLoopCount() >= 3 && externalColorChanger->getLoopCount() >= 3) {
               switchToFadeToWhite();
           }
           break;

      case fadeToWhite:
          if(onboardColorChanger->isAnimationComplete() && externalColorChanger->isAnimationComplete()) {
              switchToWhiteFlash();
          }
          break;

      case whiteFlash:
           if(onboardColorChanger->getLoopCount() != toneIndex && toneIndex < 3) {
            CircuitPlayground.playTone(tones[toneIndex], 50);
            toneIndex++; 
           }
           if(onboardColorChanger->getLoopCount() >= 3 && externalColorChanger->getLoopCount() >= 3) {
              switchToWhiteToColor();
          }
          break;

      case whiteToColor:
           if(onboardColorChanger->isAnimationComplete() && externalColorChanger->isAnimationComplete()) {
               switchToComplete();
          }

          break;

       case complete:
           break;
   }
}

void CreaturePowerSuitActivateAnimation::switchToColorBlink() {    
    Serial.println("switchToColorBlink");
    resetAnimation();
    state = colorBlink;

    Serial.println("creating color changers");
    onboardColorChanger = new PixelColorChanger(&CircuitPlayground.strip, onboardPixels, onboardPixelCount, this->colorBlinkColors, this->colorBlinkColorsCount, 50, snake);
    externalColorChanger = new PixelColorChanger(&ExternalStrip, externalPixels, externalPixelCount, this->colorBlinkColors, this->colorBlinkColorsCount, 50, snake);
}

void CreaturePowerSuitActivateAnimation::switchToFadeToWhite() {
    Serial.println("switchToFadeToWhite");
    resetAnimation();
    state = fadeToWhite;

    Serial.println(this->fadeToWhiteColorsCount);
    onboardColorChanger = new PixelColorChanger(&CircuitPlayground.strip, onboardPixels, onboardPixelCount, this->fadeToWhiteColors, this->fadeToWhiteColorsCount, 50, none);
    externalColorChanger = new PixelColorChanger(&ExternalStrip, externalPixels, externalPixelCount, this->fadeToWhiteColors, this->fadeToWhiteColorsCount, 50, none);  
}

void CreaturePowerSuitActivateAnimation::switchToWhiteFlash() {
    resetAnimation();
    state = whiteFlash;

    onboardColorChanger = new PixelColorChanger(&CircuitPlayground.strip, onboardPixels, onboardPixelCount, this->whiteFlashColors, this->whiteFlashColorsCount, 50, normal);
    externalColorChanger = new PixelColorChanger(&ExternalStrip, externalPixels, externalPixelCount, this->whiteFlashColors, this->whiteFlashColorsCount, 50, normal);  
}

void CreaturePowerSuitActivateAnimation::switchToWhiteToColor() {
    resetAnimation();
    state = whiteToColor;

    onboardColorChanger = new PixelColorChanger(&CircuitPlayground.strip, onboardPixels, onboardPixelCount, this->whiteToColorColors, this->whiteToColorColorsCount, 50, none);
    externalColorChanger = new PixelColorChanger(&ExternalStrip, externalPixels, externalPixelCount, this->whiteToColorColors, this->whiteToColorColorsCount, 50, none);  
}

void CreaturePowerSuitActivateAnimation::switchToComplete() {
    resetAnimation();
    state = complete;
}


bool CreaturePowerSuitActivateAnimation::isAnimationComplete() {
    return state == complete;
}

unsigned int CreaturePowerSuitActivateAnimation::getLoopCount() {
    return 0;
}
