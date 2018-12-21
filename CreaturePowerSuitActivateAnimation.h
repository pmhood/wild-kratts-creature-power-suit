#ifndef __CREATURE_POWER_SUIT_ACTIVATE_ANIMATION_H__
#define __CREATURE_POWER_SUIT_ACTIVATE_ANIMATION_H__

#include "PixelColorChanger.h"
#include "ExternalStrip.h"
#include "KrattBrother.h"
#include "CreaturePowerSuitAnimation.h"

class CreaturePowerSuitActivateAnimation: public CreaturePowerSuitAnimation {
    enum State {
        uninitialized,
        colorBlink,
        fadeToWhite,
        whiteFlash,
        whiteToColor,
        complete
    };

    public:
        CreaturePowerSuitActivateAnimation();

        ~CreaturePowerSuitActivateAnimation();

        void update(unsigned long time);
        void render();

        bool isAnimationComplete();
        unsigned int getLoopCount();

    private:
        void resetAnimation();
        void updateState();
        void switchToColorBlink();
        void switchToFadeToWhite();
        void switchToWhiteFlash();
        void switchToWhiteToColor();
        void switchToComplete();
        
        State state;
        PixelColorChanger* externalColorChanger;
        PixelColorChanger* onboardColorChanger;

        uint32_t colorBlinkColors[5] = {0x000000, 0x000030, 0x000060, 0x0000a0, 0x0000ff}; 
        unsigned int colorBlinkColorsCount = 5;
        uint32_t fadeToWhiteColors[5] = {0x000000, 0x303030, 0x606060, 0xa0a0a0, 0xffffff};
        unsigned int fadeToWhiteColorsCount = 5;
        uint32_t whiteFlashColors[2] = {0x000000, 0xffffff};
        unsigned int whiteFlashColorsCount = 2;
        uint32_t whiteToColorColors[4] = {0xffffff, 0xa0a0ff, 0x8080ff, 0x0000ff};
        unsigned int whiteToColorColorsCount = 4;

        const unsigned int tones[3] = {500, 800, 1000};
        int toneIndex = 0;

        uint8_t onboardPixels[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        unsigned int onboardPixelCount = 10;
        uint8_t externalPixels[3] = {0, 1, 2};
        unsigned int externalPixelCount = 3;
};

#endif
