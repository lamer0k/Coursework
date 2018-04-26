#ifndef BUTTON_H
#define BUTTON_H
#include "utils.hpp"
using namespace utils;

class Button
{
  public:
    Button(GPIO_TypeDef &portName, unsigned int pinNum): port(portName),
      pin(pinNum) {};
      inline bool IsPressed() { 
        return !checkBit(port.IDR, pin);
      }
  private:
    GPIO_TypeDef &port;
    unsigned int pin;
};
#endif