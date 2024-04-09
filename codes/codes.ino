#include "DFRobot_RGBLCD1602.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BMP180I2C.h>

#include "codes.h"

#define DEBUG123

void setup(){
  Init();
}

void loop() {
  run();
  
}