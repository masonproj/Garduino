/*
  GarduinoSystem.cpp - Library for Garduino system functions.
  Created by Mason Irvine, March 30, 2022.
*/
#include "Arduino.h"
#include "RTClib.h"
#include "Water.h"
#include "Lights.h"
#include "GarduinoSystem.h"


Water water;
Lights lights;
RTC_DS1307 rtc;
int futureHour;

int buttonPin;
boolean buttonStatus;

GarduinoSystem::GarduinoSystem()
{
  buttonPin = 12;
  buttonStatus = false;

  pinMode(buttonPin, INPUT_PULLUP);

  DateTime now = rtc.now();
  DateTime future = (now + TimeSpan(0,1,0,0));
  futureHour = future.hour();
}

void GarduinoSystem::on()
{
  GarduinoSystem::startClock();
}

void GarduinoSystem::run()
{
  manualStart();
  hourly();
}

boolean GarduinoSystem::getButtonStatus()
{
  return buttonStatus;
}

void GarduinoSystem::setButtonStatus()
{
  boolean status = digitalRead(buttonPin);
  if(!status)
  {
    buttonStatus = true;
  }
  else
  {
    buttonStatus = false;
  }
}

void GarduinoSystem::startClock()
{
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial);
#endif

  if (! rtc.begin()) 
  {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) 
  {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void GarduinoSystem::hourly()
{
  DateTime now = rtc.now();
  DateTime future = (now + TimeSpan(0,1,0,0));

  if(futureHour <= now.hour() && futureHour != 0 || futureHour == now.hour() && futureHour == 0)
  {
    if(water.checkMoisture())
    {
      water.waterPlant();
    }

    if(now.hour() > 8 && now.hour() < 18)
    {
      lights.lightOn();
    }
    else
    {
      lights.lightOff();
    }
    futureHour = future.hour();
  }
}

void GarduinoSystem::manualStart()
{
  setButtonStatus();
  if (getButtonStatus() == HIGH)
  {
    water.waterPlant();
  }
}