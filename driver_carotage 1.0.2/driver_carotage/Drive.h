#pragma once
#include "Arduino.h"

class Drive{
  public:
    void run();
  private:
    short getSpeed();
    void direction(bool dir);
};
