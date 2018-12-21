#ifndef __PIXEL_COLOR_CHANGER_H__
#define __PIXEL_COLOR_CHANGER_H__

#include <stdint.h>

#include "Adafruit_CircuitPlayground.h"
// #include "Loop.h"

/* 
    normal - change colors from 0..N, 0..N, 0..N, ...
    snake - change colors from 0..N..0..N..0
    none - only loop 0..N once
*/
enum PixelColorChangerLoopType { normal, snake, none };

/*
    PixelColorChanger sets a group of pixels using the same colors
*/
class PixelColorChanger {
    enum LoopDirection { forward, backward };

    public:
        PixelColorChanger(Adafruit_CPlay_NeoPixel* strip, uint8_t pixels[], unsigned int pixelCount, uint32_t colors[], unsigned int colorCount, unsigned int interval, PixelColorChangerLoopType loopType);

        void update(unsigned long time);
        void render();

        void reset();

        bool isAnimationComplete() { return this->isComplete; }
        uint16_t getLoopCount() { return this->loopCount; }

    private:
        uint8_t* pixels;
        unsigned int pixelCount;

        uint32_t* colors;
        unsigned int colorCount;
        unsigned int currentColorIndex;

        unsigned long lastUpdatedTime;
        unsigned int interval;
        
        PixelColorChangerLoopType loopType;
        LoopDirection loopDirection;

        bool isComplete;
        uint16_t loopCount;

        Adafruit_CPlay_NeoPixel* strip;
};

#endif
