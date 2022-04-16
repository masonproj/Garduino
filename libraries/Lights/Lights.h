/*
  Lights.h - Library for Garduino Lights functions.
  Created by Mason Irvine, March 30, 2022.
*/
#ifndef Lights_h
#define Lights_h

#include "Arduino.h"

/* Class to control the lighting for Garduino */
class Lights
{
  public:
    /* Initialize light pin and set it's mode */
    Lights();
    /* Turn lights on */
    void lightOn();
    /* Turn lights off */
    void lightOff();

    /* Variable for light pin */
    int lightPin;
};

#endif