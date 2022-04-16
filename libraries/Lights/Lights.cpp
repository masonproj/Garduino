/*
  Lights.cpp - Library for Garduino Lights functions.
  Created by Mason Irvine, March 30, 2022.
*/
#include "Arduino.h"
#include "Lights.h"

int lightPin;

Lights::Lights()
{
  lightPin = 13;

  pinMode(lightPin, OUTPUT);
}

void Lights::lightOn()
{
  digitalWrite(lightPin, HIGH);
}

void Lights::lightOff()
{
  digitalWrite(lightPin, LOW);
}