/*
  Water.h - Library for Garduino water functions.
  Created by Mason Irvine, March 30, 2022.
*/
#ifndef Water_h
#define Water_h

#include "Arduino.h"

class Water
{
  public:
    Water();
    void run();
    boolean checkMoisture();
    int getSensorValue();
    void setSensorValue();
    void waterPlant();
  private:
};

#endif