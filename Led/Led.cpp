#include "Led.h"

#define DEFAULT_INITIAL_LED_STATE LedState::OFF

//Class constructor
Led::Led(int pin){
  _pin = pin;  //I don't check if the pin received is valid
  _state = DEFAULT_INITIAL_LED_STATE;
  _stateChangedEventHandler = NULL;  

  pinMode(_pin, OUTPUT);

  if(_state == LedState::ON){
    digitalWrite(_pin, HIGH);
  }  
}

//Class constructor
Led::Led(int pin, LedState state){
  _pin = pin;  //I don't check if the pin received is valid
  _state = state;
  _stateChangedEventHandler = NULL;  

  pinMode(_pin, OUTPUT);

  if(_state == LedState::ON){
    digitalWrite(_pin, HIGH);
  }  
}

//Class constructor
Led::Led(int pin, void (*stateChangedEventHandler)()){
  _pin = pin;  //I don't check if the pin received is valid
  _state = DEFAULT_INITIAL_LED_STATE;
  _stateChangedEventHandler = stateChangedEventHandler;  

  pinMode(_pin, OUTPUT);

  if(_state == LedState::ON){
    digitalWrite(_pin, HIGH);
  }    
}

//Class constructor
Led::Led(int pin, LedState state, void (*stateChangedEventHandler)()){
  _pin = pin;  //I don't check if the pin received is valid
  _state = state;
  _stateChangedEventHandler = stateChangedEventHandler;  

  pinMode(_pin, OUTPUT);

  if(_state == LedState::ON){
    digitalWrite(_pin, HIGH);    
  }  
}

//Returns the state of the led
LedState Led::getState(){
  return _state;
}

//Changes the state of the led (e.g. if it's ON, this method turns it to OFF and vice versa)
void Led::setState(){
  
  if(_state == LedState::OFF){
      _state = LedState::ON;
      digitalWrite(_pin, HIGH);
  } else {
      _state = LedState::OFF;
      digitalWrite(_pin, LOW);
  }

  if(_stateChangedEventHandler != NULL){
    _stateChangedEventHandler();
  }  
}

//Changes the state of the led using the value passed to the method
void Led::setState(LedState state){
    if(_state == state){ 
      return;
    }

    if(_state == LedState::OFF){
        _state = LedState::ON;
        digitalWrite(_pin, HIGH);
    } else {
        _state = LedState::OFF;
        digitalWrite(_pin, LOW);
    }

    if(_stateChangedEventHandler != NULL){
    _stateChangedEventHandler();
   }             
}

//Returns true if the state of led is ON, false otherwise.
bool Led::isON(){
 return (_state == LedState::ON)?(true):(false); 
}

//Returns true if the state of led is OFF, false otherwise.
bool Led::isOFF(){
  return (_state == LedState::OFF)?(true):(false);
}
