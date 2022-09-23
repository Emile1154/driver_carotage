#include "Button.h"
Button::Button(byte pin):_pin(pin){
      pinMode(_pin, INPUT_PULLUP);
}
bool Button::hold(){
   if(!digitalRead(_pin)){
      return true;
   }
   return false;
}
  
