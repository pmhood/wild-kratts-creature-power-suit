#include "PixelColorChanger.h"

#include <stdio.h>

PixelColorChanger::PixelColorChanger(Adafruit_CPlay_NeoPixel* strip, uint8_t pixels[], unsigned int pixelCount, uint32_t colors[], unsigned int colorCount, unsigned int interval, PixelColorChangerLoopType loopType) {
    this->strip = strip;
    
    this->pixels = pixels;
    this->pixelCount = pixelCount;
    this->colors = colors;
    this->colorCount = colorCount;
    this->loopType = loopType;
    this->interval = interval;
    
    this->lastUpdatedTime = 0;
    this->currentColorIndex = 0;
    this->loopDirection = forward;
    this->isComplete = false;
    this->loopCount = 0;
}

void PixelColorChanger::reset() {
    this->currentColorIndex = 0;
    this->loopDirection = forward;
    this->isComplete = false;
    this->loopCount = 0;
}


void PixelColorChanger::update(unsigned long time) {
    if(this->isComplete || (time - this->lastUpdatedTime) < this->interval) {
      return;
    }
    this->lastUpdatedTime = time;

    switch(this->loopType) {
        case none:
            if(this->currentColorIndex == this->colorCount -1) {
                ++this->loopCount;
                this->isComplete = true;
            } else {
                ++this->currentColorIndex;
            }
            break;
        case normal:
            if(this->currentColorIndex == this->colorCount -1) {
                ++this->loopCount;
            }
            this->currentColorIndex = (this->currentColorIndex + 1) % this->colorCount;
            break;
        case snake:
            switch(this->loopDirection) {
                case forward:
                    if(this->currentColorIndex == this->colorCount - 1) {
                        this->loopDirection = backward;
                        --this->currentColorIndex;
                    } else {
                        ++this->currentColorIndex;
                    }
                    break;
                case backward:
                    if(this->currentColorIndex == 0) {
                        ++this->loopCount;
                        this->loopDirection = forward;
                        ++this->currentColorIndex;
                    } else {
                        --this->currentColorIndex;
                    }
                    break;
            }
            break;
    }    
}

void PixelColorChanger::render() {
    if(this->isComplete) {
      return;
    }

    for(int i = 0; i < this->pixelCount; ++i) {
        strip->setPixelColor(this->pixels[i], this->colors[this->currentColorIndex]);
        strip->show();
    }
}
