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
    /* Initialize pump and sensor pins, set pump pinMode */
    Water();
    /* Check soil moisture sensors analog resistance and if it is above the 600 threshold which is very dry soil, call the watering function */
    boolean checkMoisture();
    /* Get value of soil moisture sensor */
    int getSensorValue();
    /* Update the soil moisture value */
    void setSensorValue();
    /* Start the pump and water the plant */
    void waterPlant();

    /* Variable for storing sensor pin */
    int sensorPin;
    /* Variable for storing sensor value */
    int sensorValue;
    /* Variable for storing pump pin */
    int pumpPin;
};

#endif