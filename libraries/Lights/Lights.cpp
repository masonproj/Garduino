/*
  Lights.cpp - Library for Garduino Lights functions.
  Created by Mason Irvine, March 30, 2022.
*/
#include "Arduino.h"
#include "Lights.h"

Lights::Lights()
{
  pinMode(13, OUTPUT);
}

void Lights::run()
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void Lights::checkLights()
{

}