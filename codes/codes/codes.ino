#include "DFRobot_RGBLCD1602.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BMP180I2C.h>

#define I2C_ADDRESS 0x77

BMP180I2C bmp180(I2C_ADDRESS);

LiquidCrystal_I2C lcD(0x3F, 20, 4); 

DFRobot_RGBLCD1602 lcd(0x60 ,16,2);

void setup() {
  Wire.begin();

   Serial.begin(9600);
  while (!Serial); 
  Serial.println("\nI2C Scanner");

  lcd.init();
    lcd.print("Pressure: ");

    lcD.init(); 
    lcD.print("Temperature: ");

     if (!bmp180.begin()) {
    Serial.println("begin() failed. Check your BMP180 Interface and I2C Address.");
    while (1);
  }
}
void loop() {
//сканер
int nDevices = 0;
  Serial.println("Scanning...");

  for (byte address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");
      ++nDevices;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
  //перший інтерфейс

    if (!bmp180.measurePressure()) {
    Serial.println("Could not start pressure measurement, is a measurement already running?");
    return;
  }

  do {
    delay(100);
  } while (!bmp180.hasValue());

  float pressure = bmp180.getPressure();

  lcd.setCursor(0, 1);
  lcd.print(pressure);
  lcd.print(" Pa");

//другий інтерфейс

  if (!bmp180.measureTemperature()) {
    Serial.println("Could not start temperature measurement, is a measurement already running?");
    return;
  }

  do {
    delay(100);
  } while (!bmp180.hasValue());
  float temperature = bmp180.getTemperature();
   lcD.setCursor(0, 1);
  lcD.print(temperature);
  lcD.print(" C");
  delay(500);
}
