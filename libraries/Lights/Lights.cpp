/*
  Lights.cpp - Library for Garduino Lights functions.
  Created by Mason Irvine, March 30, 2022.
*/
#include "Arduino.h"
#include "Lights.h"

int dialPin;
int lightPin;
boolean lightStatus;

int lightLevel;

Lights::Lights()
{
  dialPin = A1;
  lightPin = 13;
  lightStatus = false;

  pinMode(lightPin, OUTPUT);
}

void Lights::run()
{
  lightControl();
}

void Lights::setLightLevel()
{
  lightLevel = analogRead(dialPin);
}

int Lights::getLightLevel()
{
  return lightLevel;
}

boolean Lights::getLightStatus()
{
  return lightStatus;
}

void setLightStatus(boolean status)
{
  if(status)
  {
    lightStatus = true;
  }
  else
  {
    lightStatus = false;
  }
}

void Lights::lightControl()
{
  if(getLightStatus() == true)
  {
    lightOn();
  }
  else
  {
    lightOff();
  }
}

void Lights::lightOn()
{
  setLightLevel();
  digitalWrite(lightPin, HIGH);
}

void Lights::lightOff()
{
  digitalWrite(lightPin, LOW);
}