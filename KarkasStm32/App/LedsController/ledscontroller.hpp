#ifndef LEDSCONTROLLER_H
#define LEDSCONTROLLER_H
#include <array>
#include "led.hpp"
#include "frtosWrapper.h"
#include "susutypes.h"
#include "utils.hpp"

enum class LedMode : unsigned char {
  Tree = 0,
  Chess = 1,
  All = 2,
  End = 2
};

constexpr int LedsCount  =  4;

class LedsController: public iActiveObject {
  public:
    LedsController() { switchOnAll();}; 
    void update();     
    void run() override;
  private:
    void switchOnAll() const;
    inline void toggleAll() const; 
       
    inline void nextMode();
    LedMode mode = LedMode::Tree;
    tS32 currentLed = 0;
    static const Led leds[LedsCount]; 
};
#endif