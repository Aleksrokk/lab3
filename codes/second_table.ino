
void show_second() {

  lcD.setCursor(0, 1);
  lcD.print(get_temperature());
  lcD.print(" C");
}

float get_temperature() {
  check_preassure();
  wait_value1();
  return bmp180.getTemperature();
}

void check_preassure() {
  if (!bmp180.measureTemperature()) {
    Serial.println("Could not start temperature measurement, is a measurement already running?");
    return;
  }
}

void wait_value1() {
  do {
    delay(100);
  } while (!bmp180.hasValue());
}