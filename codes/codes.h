
#define I2C_ADDRESS 0x77

BMP180I2C bmp180(I2C_ADDRESS);

LiquidCrystal_I2C lcD(0x3F, 20, 4);

DFRobot_RGBLCD1602 lcd(0x60, 16, 2);

void scaner(void);
void show_first(void);
void check_pressure(void);
void wait_value(void);
void show_second(void);
float get_temperature(void);
float get_pressure(void);
void wait_value1(void);
void Init(void);
void run(void);