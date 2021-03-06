/*
  Water.cpp - Library for Garduino water functions.
  Created by Mason Irvine, March 30, 2022.
*/
#include "Arduino.h"
#include "Water.h"

int sensorPin;
int sensorValue;

int pumpPin;

Water::Water()
{
  sensorPin = A0; 
  pumpPin = 9;

  pinMode(pumpPin, OUTPUT);
}

void Water::setSensorValue()
{
  sensorValue = analogRead(sensorPin);
}

int Water::getSensorValue()
{
  return sensorValue;
}

boolean Water::checkMoisture()
{
  int limit = 600;
  setSensorValue();
  if(getSensorValue() > limit)
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
  digitalWrite(pumpPin, HIGH);
  delay(3500);
  digitalWrite(pumpPin, LOW);
}