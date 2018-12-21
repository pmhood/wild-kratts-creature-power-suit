#include "CreaturePowerSuitColors.h"


// // Chris Kratt colors (green)
// uint32_t blackToGreen[] = {0x000000, 0x002000, 0x004000, 0x006000, 0x008000, 0x00A000, 0x00C000, 0x00E000, 0x00FF00};                 
// unsigned int blackToGreenCount = 9;

// uint32_t fastBlackToGreen[] = {0x000000, 0x003000, 0x006000, 0x00a000, 0x00ff00}; 
// unsigned int fastBlackToGreenCount = 5;

// uint32_t whiteToGreen[] = {0xffffff, 0xa0ffa0, 0x80ff80, 0x00ff00};
// unsigned int whiteToGreenCount = 4;

// // Martin Kratt colors (blue)
// uint32_t blackToBlue[] = {0x000000, 0x000020, 0x000040, 0x000060, 0x000080, 0x0000a0, 0x0000c0, 0x0000e0, 0x0000ff};
// unsigned int blackToBlueCount = 9;

// uint32_t fastBlackToBlue[] = {0x000000, 0x000030, 0x000060, 0x0000a0, 0x0000ff}; 
// unsigned int fastBlackToBlueCount = 5;

// uint32_t whiteToBlue[] = {0xffffff, 0xa0a0ff, 0x8080ff, 0x0000ff};
// unsigned int whiteToBlueCount = 4;

// // Common colors
// uint32_t g_blackToWhite[] = {0x000000, 0x303030, 0x606060, 0xa0a0a0, 0xffffff}; 
// unsigned int g_blackToWhiteCount = 5;

// uint32_t g_blackToWhiteFlash[] = {0x000000, 0xffffff};
// unsigned int g_blackToWhiteFlashCount = 2;


CreaturePowerSuitColors::CreaturePowerSuitColors(): 
            blackToColor{0x000000, 0x000020, 0x000040, 0x000060, 0x000080, 0x0000a0, 0x0000c0, 0x0000e0, 0x0000ff},
            blackToColorCount(9),
            fastBlackToColor{0x000000, 0x000030, 0x000060, 0x0000a0, 0x0000ff},
            fastBlackToColorCount(5),
            whiteToColor{0xffffff, 0xa0a0ff, 0x8080ff, 0x0000ff},
            whiteToColorCount(4) {
}

CreaturePowerSuitColors* CreaturePowerSuitColors::make(KrattBrother brother) {            
    switch(brother) {
        case chris:
            return new CreaturePowerSuitColors();
            break;
        case martin:
            return new CreaturePowerSuitColors();
            break;
    }
}


// CreaturePowerSuitBlueColors::CreaturePowerSuitBlueColors() {
//     this->blackToColor = {0x000000, 0x000020, 0x000040, 0x000060, 0x000080, 0x0000a0, 0x0000c0, 0x0000e0, 0x0000ff};
// }