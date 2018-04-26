#ifndef LED_H
#define LED_H
#include <stm32f411xe.h>  
#include "utils.hpp"

class Led
{
  public:
    Led(GPIO_TypeDef &portName, unsigned int pinNum): port(portName),
      pin(pinNum) {};
    inline void toggle() const { utils::toggleBit(port.ODR, pin); }
    inline void switchOn() const { utils::setBit(port.ODR, pin); }
    inline void switchOff() const { utils::clearBit(port.ODR, pin); }
  private:
    GPIO_TypeDef &port;
    unsigned int pin;
};
#endif