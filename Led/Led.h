/*
 * Led.h - Library used to model a led light connected to the Arduino board 
 * Created by crash6, February 22, 2019.
 * Released into the public domain
 */

 /*
  * Note : the led ligh should be plugged to the Arduino board using a 220 Ohm resistor
  */

#ifndef Led_h
#define Led_h

#include "Arduino.h"

enum class LedState {
   OFF = 0,
   ON  = 1
};

class Led {

  //public members
  public:
    Led(int pin);
    Led(int pin, LedState state);
    Led(int pin,void (*stateChangedEventHandler)());
    Led(int pin, LedState state, void (*stateChangedEventHandler)());   
    LedState getState();
    void setState();
    void setState(LedState state);
    bool isON();
    bool isOFF();

  //private members
  private:
    int _pin;  
    LedState _state;
    void (*_stateChangedEventHandler)();
};


#endif
