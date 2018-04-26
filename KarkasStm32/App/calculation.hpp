#ifndef CALCULATION_H
#define CALCULATION_H
#include <vector>                       //for begin
#include <algorithm>                    //for sort
#include "iactiveobject.h"

class Calculation : public iActiveObject
{
  public:     
    virtual void run() override { for(;;) {update();} };
    inline void update() {for(auto i = 0; i < 100'000'000; i++) {};};
};

#endif