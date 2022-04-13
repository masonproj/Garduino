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
int futureMin;
int futureHour;

GarduinoSystem::GarduinoSystem()
{
  DateTime future = (now + TimeSpan(0,0,1,0));
  futureMin = future.minute();

  future = (now + TimeSpan(0,1,0,0));
  futureHour = future.hour();
}

void GarduinoSystem::on()
{
  GarduinoSystem::startClock();
}

void GarduinoSystem::run()
{
  //minutely();
  hourly();
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

void GarduinoSystem::minutely()
{
  DateTime now = rtc.now();
  DateTime future = (now + TimeSpan(0,0,1,0));

  if(futureMin <= now.minute())
  {
    //Execute this code every minute and update for next minute
    
    futureMin = future.minute();
  }
}

void GarduinoSystem::hourly()
{
  DateTime now = rtc.now();
  DateTime future = (now + TimeSpan(0,1,0,0));

  if(futureHour <= now.hour() && futureHour != 0 || futureHour == now.hour() && futureHour == 0)
  {
    //Execute this code every hour and update for next hour
    if(water.checkMoisture())
    {
      water.waterPlant();
    }
    futureHour = future.hour();
  }
}