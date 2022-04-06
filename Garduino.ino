#include <GarduinoSystem.h>

GarduinoSystem garduinoSystem;

void setup() {
  garduinoSystem.on();
}

void loop() {
  garduinoSystem.run();
}
