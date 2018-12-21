#ifndef __CREATURE_POWER_SUIT_IDLE_ANIMATION_H__
#define __CREATURE_POWER_SUIT_IDLE_ANIMATION_H__

#include <stdint.h>
#include "PixelColorChanger.h"
#include "ExternalStrip.h"
#include "CreaturePowerSuitAnimation.h"

class CreaturePowerSuitIdleAnimation: public CreaturePowerSuitAnimation {

    public:
        CreaturePowerSuitIdleAnimation();
        ~CreaturePowerSuitIdleAnimation();

        void update(unsigned long time);
        void render();
        bool isAnimationComplete();
        unsigned int getLoopCount();

    private:
        uint32_t colors[7] = { 0x000010, 0x000015, 0x00001a, 0x00001f, 0x000024, 0x000029, 0x00002e };
        unsigned int colorsCount = 7;
        unsigned int interval = 50;
        
        PixelColorChanger* onboardColorChanger;
        uint8_t mainPixels[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        unsigned int mainPixelCount = 10;
        
        PixelColorChanger* externalColorChanger;        
        uint8_t externalPixels[3] = {0, 1, 2};
        unsigned int externalPixelCount = 3;
};

#endif
