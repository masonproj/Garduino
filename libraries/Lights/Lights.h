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
    void on();
    void run();
    void checkLights();

  private:
};

#endif