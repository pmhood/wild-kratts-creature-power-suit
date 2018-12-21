#include "CreaturePowerSuitIdleAnimation.h"

CreaturePowerSuitIdleAnimation::CreaturePowerSuitIdleAnimation() {
    onboardColorChanger = new PixelColorChanger(&CircuitPlayground.strip, mainPixels, mainPixelCount, &colors[0], colorsCount, interval, snake);
    externalColorChanger = new PixelColorChanger(&ExternalStrip, externalPixels, externalPixelCount, &colors[0], colorsCount, interval, snake);
}

CreaturePowerSuitIdleAnimation::~CreaturePowerSuitIdleAnimation() {
  delete onboardColorChanger;
  delete externalColorChanger;
}

void CreaturePowerSuitIdleAnimation::update(unsigned long time) {
    onboardColorChanger->update(time);
    externalColorChanger->update(time);     
}

void CreaturePowerSuitIdleAnimation::render() {
    CircuitPlayground.setBrightness(30);
    onboardColorChanger->render();
    externalColorChanger->render();
}

bool CreaturePowerSuitIdleAnimation::isAnimationComplete() {
    return onboardColorChanger->isAnimationComplete() && externalColorChanger->isAnimationComplete();
}

unsigned int CreaturePowerSuitIdleAnimation::getLoopCount() {
    return onboardColorChanger->getLoopCount();
}
