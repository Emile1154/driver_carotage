#include "Drive.h"

#include "Settings.h"
#include "Button.h"

//инициализация кнопок
Button right(DIR_RIGHT);
Button left(DIR_LEFT);

void Drive::run(){
  static bool dir = false;
  while(1){
    if(right.hold()){
      Drive::direction(dir); //прямой
      continue;
    }
    if(left.hold()){
      Drive::direction(!dir); //реверс
      continue;
    }
    digitalWrite(ENABLE, true);
  }
  return;
}

void Drive::direction(bool dir){
  digitalWrite(ENABLE, false);
  digitalWrite(DIR, dir);
  tone(PULSE, Drive::getSpeed());
  return; 
}

short Drive::getSpeed(){ //выдать частоту импульсов
   return map(analogRead(ADC_INPUT), 0, 1023, MIN_SPEED, MAX_SPEED);
}
