void show_first() {

  lcd.setCursor(0, 1);
  lcd.print(get_pressure());
  lcd.print(" Pa");
}

float get_pressure() {
  check_pressure();
  wait_value();
  return bmp180.getPressure();
}

void check_pressure() {
  if (!bmp180.measurePressure()) {
    Serial.println("Could not start pressure measurement, is a measurement already running?");
    return;
  }
}

void wait_value() {
  do {
    delay(100);
  } while (!bmp180.hasValue());
}