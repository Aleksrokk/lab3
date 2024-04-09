void Init() {
  Wire.begin();

  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("\nI2C Scanner");

#ifdef DEBUG123

  Serial.print("DEBUG123");
#endif

  lcd.init();
  lcd.print("Pressure: ");

  lcD.init();
  lcD.print("Temperature: ");

  if (!bmp180.begin()) {
    Serial.println("begin() failed. Check your BMP180 Interface and I2C Address.");
    while (1)
      ;
  }
  scaner();
}