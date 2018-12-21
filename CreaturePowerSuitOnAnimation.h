#ifndef __CREATURE_POWER_SUIT_ON_ANIMATION_H__
#define __CREATURE_POWER_SUIT_ON_ANIMATION_H__

#include <stdint.h>
#include "PixelColorChanger.h"
#include "ExternalStrip.h"
#include "CreaturePowerSuitAnimation.h"

class CreaturePowerSuitOnAnimation: public CreaturePowerSuitAnimation {


    public:
        CreaturePowerSuitOnAnimation();
        ~CreaturePowerSuitOnAnimation();

        void update(unsigned long time);
        void render();
        bool isAnimationComplete();
        unsigned int getLoopCount();


    private:
        uint32_t colors[1] = {0x0000ff};
        unsigned int colorsCount = 1;
        
        PixelColorChanger* onboardColorChanger;
        uint8_t mainPixels[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        unsigned int mainPixelCount = 10;
        
        PixelColorChanger* externalColorChanger;        
        uint8_t externalPixels[3] = {0, 1, 2};
        unsigned int externalPixelCount = 3;
};

#endif
