#ifndef __CREATURE_POWER_SUIT_COLORS_H__
#define __CREATURE_POWER_SUIT_COLORS_H__

#include <stdint.h>
#include "KrattBrother.h"


class CreaturePowerSuitColors {
    public:
        static CreaturePowerSuitColors* make(KrattBrother brother);
        CreaturePowerSuitColors();

        uint32_t blackToColor[9];
        unsigned int blackToColorCount;
        uint32_t fastBlackToColor[5];
        unsigned int fastBlackToColorCount;
        uint32_t whiteToColor[4];
        unsigned int whiteToColorCount;
        uint32_t blackToWhite[5] = {0x000000, 0x303030, 0x606060, 0xa0a0a0, 0xffffff};
        unsigned int blackToWhiteCount = 5;
        uint32_t blackToWhiteFlash[2] = {0x000000, 0xffffff};
        unsigned int blackToWhiteFlashCount = 2;
};

// class CreaturePowerSuitBlueColors: public CreaturePowerSuitColors {
//     public:
//         CreaturePowerSuitBlueColors();

// };

// class CreaturePowerSuitGreenColors: public CreaturePowerSuitColors {
//     public:
//         CreaturePowerSuitGreenColors();

// };


#endif