/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: Displaytest // 2-Punkt Temperaturregelung

**************************************************************************************************
Version: 13.06.2024
**************************************************************************************************
Board: ESP32vn IoT UNO
**************************************************************************************************
Libraries:
https://github.com/espressif/arduino-esp32/tree/master/libraries
C:\Users\User\Documents\Arduino
D:\gittemp\Arduino II\A156_Wetterdaten_V3

- WiFi.h V0.16.1
- LiquidCrystal_I2C I2C DisplaySDA(GPIO21), SDL(GPIO22)
- DHT.h
- Adafruit_Sensor.h

**************************************************************************************************
C++ Arduino IDE V1.8.19
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
http://arduino.esp8266.com/stable/package_esp8266com_index.json
**************************************************************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// LCD Addresse 0x27 fÃ¼r 16 Zeichen und 2 Zeilen
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, world!");
}
void loop()
{
  // ...
}
