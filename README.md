# Arduino-Led

This library implements any physical led light plugged to the Arduino board. I modelled it like an object which can be controlled through two main methods :

- **_setState()_**;
- **_setState(*LedState state)_**;

**_LedState_** is simply an enum class type which can be :

- **_LedState::ON_** 
- **_LedState::OFF_**

The class object provides also a basic callback mechanism which can be useful when we want to be notified that the state of the led light is changed. The callback function can be passed to the constructor method of the object when we instatiate it.
