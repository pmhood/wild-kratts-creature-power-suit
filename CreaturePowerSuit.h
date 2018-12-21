#ifndef __CREATURE_POWER_SUIT_H__
#define __CREATURE_POWER_SUIT_H__

#include "CreaturePowerSuitAnimation.h"
#include "KrattBrother.h"
// #include "CreaturePowerSuitColors.h"

class CreaturePowerSuit {

  enum State {
    uninitialized,
    off,
    idle,
    activate,    
    on
  };

  public:
    CreaturePowerSuit(KrattBrother brother);
    ~CreaturePowerSuit();

    // void setState(State newState) { this->state = newState; }
    void activateCreaturePower();
    void reset();

    void update(unsigned long time);
    void render();

  private:
    void updateState();
    void resetAnimation();

    State state;
    KrattBrother brother;
    // CreaturePowerSuitColors* suitColors;
    CreaturePowerSuitAnimation* animation;
};

#endif
