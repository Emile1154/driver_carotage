#pragma once
#include "Arduino.h"
class Button{
  public:
    Button(byte pin);
    bool hold();

  private:
   const byte _pin;
};
