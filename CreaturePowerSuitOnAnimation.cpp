#include "CreaturePowerSuitOnAnimation.h"
#include <Adafruit_CircuitPlayground.h>

CreaturePowerSuitOnAnimation::CreaturePowerSuitOnAnimation() {
    onboardColorChanger = new PixelColorChanger(&CircuitPlayground.strip, mainPixels, mainPixelCount, &colors[0], colorsCount, 1000, normal);
    externalColorChanger = new PixelColorChanger(&ExternalStrip, externalPixels, externalPixelCount, &colors[0], colorsCount, 1000, normal);
}

CreaturePowerSuitOnAnimation::~CreaturePowerSuitOnAnimation() {
  delete onboardColorChanger;
  delete externalColorChanger;
}

void CreaturePowerSuitOnAnimation::update(unsigned long time) {
    CircuitPlayground.setBrightness(100);
    onboardColorChanger->update(time);
    externalColorChanger->update(time);     
}

void CreaturePowerSuitOnAnimation::render() {
    onboardColorChanger->render();
    externalColorChanger->render();
}

bool CreaturePowerSuitOnAnimation::isAnimationComplete() {
  return false;
}

unsigned int CreaturePowerSuitOnAnimation::getLoopCount() {
  return 0;
}
