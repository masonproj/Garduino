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
    boolean getButtonStatus();
    void setButtonStatus();
    void hourly();
    void startClock();
    void manualStart();

    DateTime now;
    DateTime future;
    int futureHour;
    boolean buttonStatus;
  private:
};

#endif