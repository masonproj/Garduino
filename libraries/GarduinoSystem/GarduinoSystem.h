/*
  GarduinoSystem.h - Library for Garduino system functions.
  Created by Mason Irvine, March 30, 2022.
*/
#ifndef GarduinoSystem_h
#define GarduinoSystem_h

#include "Arduino.h"
#include "RTClib.h"
#include "Water.h"
#include "Lights.h"

class GarduinoSystem
{
  public:
    GarduinoSystem();
    void on();
    void run();
    void startClock();
    void outputClock();
    void updateTime();
    void startSensor();
    void updateSensor();

    char daysOfTheWeek[7][12];
  private:
};

#endif