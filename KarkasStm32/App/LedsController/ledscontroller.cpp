/**********************************************************
* ledscontroller.cpp
* Author: Sergey Kolody
* Coopyright: SUSU, 2018 
***********************************************************/
#include "ledscontroller.hpp"

Led LedsController::leds[] = 
{{Led{*GPIOC, 5U}},{Led{*GPIOC, 8U}},{Led{*GPIOC, 9U}},{Led{*GPIOA, 5U}}};; 

/****************************************************************
* Name: run()
* Descrtiption: task for updating the leds state depends of mode
* with 1 second period
*****************************************************************/  
void LedsController::run(){
  tU32 lastWakeTime = Rtos.TaskGetTickCount();
  for(;;) {
    Rtos.taskDelayUntil(&lastWakeTime,1sec);
    update();
  }
 };

/****************************************************************
* Name: switchOnAll()
* Descrtiption: 
*****************************************************************/  
void LedsController::switchOnAll() const{ 
  for (auto &led: leds) {
    led.switchOn();
  }      
};   

/****************************************************************
* Name: toggleAll()
* Descrtiption: 
*****************************************************************/  
inline void LedsController::toggleAll() const { 
  for (auto &led: leds) {
    led.toggle();
  }      
};

/****************************************************************
* Name: update()
* Descrtiption: updating the leds state depends of mode
*****************************************************************/  
inline void LedsController::update() {
  switch(mode) {
    case LedMode::Tree:
      leds[currentLed].toggle();        
      break;      
    case LedMode::All: 
    case LedMode::Chess:
      toggleAll();
      break;
    default:
      break;      
   }
   currentLed = (currentLed < (LedsCount - 1)) ? (currentLed + 1) : 0;
};

/****************************************************************
* Name: nextMode()
* Descrtiption: 
*****************************************************************/  
inline void LedsController::nextMode() { 
  mode = (mode < LedMode::All) ? 
    static_cast<LedMode>(static_cast<unsigned char>(mode) + 1U) : LedMode::Tree;
  currentLed = 0;
  if (mode == LedMode::Chess){
    for(int i = 0; i < LedsCount; i++) {
    if ((i % 2) == 0) {
      leds[i].switchOn();
    } 
    else {
     leds[i].switchOff();
    }
  }
  } 
  else {
    switchOnAll();
  }      
};
    

