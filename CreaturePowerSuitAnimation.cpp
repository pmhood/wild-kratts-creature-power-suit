#include "CreaturePowerSuitAnimation.h"
#include "CreaturePowerSuitIdleAnimation.h"
#include "CreaturePowerSuitActivateAnimation.h"
#include "CreaturePowerSuitOnAnimation.h"


// CreaturePowerSuitAnimation* CreaturePowerSuitAnimation::make(KrattBrother brother, CreaturePowerSuitAnimationType animationType) {
//     switch(animationType) {
//         case idleAnimation:
//             Serial.println("making idleAnimation");
//             // if(brother == martin) {
//                 return new CreaturePowerSuitIdleAnimation(0x000044);
//             // } else {
//                 // return new CreaturePowerSuitIdleAnimation(suitColors->blackToColor, suitColors->blackToColorCount);
//             // }            
//             break;
        
//         // case activateAnimation:
//         //      Serial.println("making activateAnimation");
//         //      Serial.println(suitColors->fastBlackToColorCount);
//         //      Serial.println(suitColors->blackToWhiteCount);
//         //      return new CreaturePowerSuitActivateAnimation(suitColors->fastBlackToColor, suitColors->fastBlackToColorCount, suitColors->blackToWhite, suitColors->blackToWhiteCount, suitColors->blackToWhiteFlash, suitColors->blackToWhiteFlashCount, suitColors->whiteToColor, suitColors->whiteToColorCount);
//         //      break;
        
//         // case onAnimation:
//         //     Serial.println("making onanimation");
//         //     return new CreaturePowerSuitOnAnimation();
//         //     break;

//         default:
//             Serial.println("making 0");
//             return 0;
//         break;

//     }
// }
