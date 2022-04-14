/*
  Lights.h - Library for Garduino Lights functions.
  Created by Mason Irvine, March 30, 2022.
*/
#ifndef Lights_h
#define Lights_h

#include "Arduino.h"

class Lights
{
  public:
    Lights();
    void run();
    void setLightLevel();
    int getLightLevel();
    void setLightStatus();
    boolean getLightStatus();
    void lightControl();
    void lightOn();
    void lightOff();
  private:
};

#endif