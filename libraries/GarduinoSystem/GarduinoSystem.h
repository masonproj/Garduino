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
/* Main system class - controls the lights and watering system, including the moisture sensors*/
class GarduinoSystem
{
  public:
    /* Initializes variables and sets pins */
    GarduinoSystem();
    /* Gets called on Arduino power on, calls clock start function */
    void on();
    /* Continuous functions need to be ran in the Arduino loop. The hourly timer is in here */
    void run();
    /* Gets button state */
    boolean getButtonStatus();
    /* Sets button state */
    void setButtonStatus();
    /* After every hour an if statement is accepted and the code inside is exexuted */
    void hourly();
    /* Initialize RTC module */
    void startClock();
    /* Function to manually trigger the watering system */
    void manualStart();

    /* Tracks next hour for hourly function */
    int futureHour;
    /* Pin for manual watering button */
    int buttonPin;
    /* Tracking variable for button */
    boolean buttonStatus;
};

#endif