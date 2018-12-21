#ifndef __CREATURE_POWER_SUIT_ANIMATION_H__
#define __CREATURE_POWER_SUIT_ANIMATION_H__

// #include "CreaturePowerSuitColors.h"
#include "KrattBrother.h"

// enum CreaturePowerSuitAnimationType {
//     idleAnimation, activateAnimation, onAnimation
// };

class CreaturePowerSuitAnimation {
    public:
        // static CreaturePowerSuitAnimation* make(KrattBrother brother, CreaturePowerSuitAnimationType animationType);

        virtual void update(unsigned long time);
        virtual void render();
        virtual bool isAnimationComplete();
        virtual unsigned int getLoopCount();
};

#endif
