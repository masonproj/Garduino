/*
  Water.cpp - Library for Garduino water functions.
  Created by Mason Irvine, March 30, 2022.
*/
#include "Arduino.h"
#include "Water.h"

Water::Water()
{

}

void Water::sensorOn()
{

}

void Water::sensorOff()
{

}

boolean Water::checkMoisture()
{
  int sensorPin = A0; 
  int sensorValue;  
  int limit = 600; 

  sensorValue = analogRead(sensorPin);
  
  if (sensorValue > limit)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Water::waterPlant()
{
  
}