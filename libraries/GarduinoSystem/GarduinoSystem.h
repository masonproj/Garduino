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
    void hourly();
    void startClock();

    DateTime now;
    DateTime future;
    int futureMin;
    int futureHour;
  private:
};

#endif