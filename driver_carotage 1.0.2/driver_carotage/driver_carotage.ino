/*
 * ------------------------------------------------------
 * НПФ Электро прошивка Водильник v1.0.2
 * Разработчик Багманов Э.Р. 17.09.2022
 * ------------------------------------------------------
 */
 
#include "Settings.h"
#include "Drive.h"

int main(void){
  init();
  #if defined(USBCON)
    USBDevice.attach();
  #endif
  pinMode(ADC_INPUT,INPUT); // инициализация ацп 
  pinMode(PULSE, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(ENABLE, OUTPUT);

  Drive drive;
  drive.run();
  return 0;  
}
