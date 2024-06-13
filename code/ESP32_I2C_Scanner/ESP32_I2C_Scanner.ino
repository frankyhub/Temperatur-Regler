/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: ESP32 I2C Scanner // 2-Punkt Temperaturregelung

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

void setup()
{
  Serial.begin (115200);  
  Wire.begin (21, 22);   // sda= GPIO_21 /scl= GPIO_22
}

void Scanner ()
{
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;

  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);          // Begin I2C transmission Address (i)
    if (Wire.endTransmission () == 0)  // Receive 0 = success (ACK response) 
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);     // PCF8574 7 bit address
      Serial.println (")");
      count++;
    }
  }
  Serial.print ("Found ");      
  Serial.print (count, DEC);        // numbers of devices
  Serial.println (" device(s).");
}

void loop()
{
  Scanner ();
  delay (100);
}
