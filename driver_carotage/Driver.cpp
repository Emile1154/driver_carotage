#include "Drive.h"

#include "Settings.h"
#include "Button.h"
#include "GyverStepper2.h"

GStepper2<STEPPER2WIRE> stepper(200, PULSE, DIR, ENABLE);

//инициализация кнопок
Button right(DIR_RIGHT);
Button left(DIR_LEFT);

void Drive::run(){
  stepper.invertEn(true); //драйвер с инверсным enable (tb6600)
  bool dir = false;
  while(1){
    if(right.hold()){
      Drive::direction(dir); //прямой
    }
    if(left.hold()){
      Drive::direction(!dir); //реверс
    }
    else{
      stepper.disable(); //выключить двигатель
    }
  }
}

void Drive::direction(bool dir){
  stepper.enable(); //включить двигатель
  stepper.reverse(dir); //прямой либо реверс
  stepper.setSpeed(Drive::getSpeed()); //двигаться с заданной скоростью
}

short Drive::getSpeed(){ // выдать скорость в виде шаг/сек
   return map(analogRead(ADC_INPUT), 0, 1023, MIN_SPEED, MAX_SPEED);
}
