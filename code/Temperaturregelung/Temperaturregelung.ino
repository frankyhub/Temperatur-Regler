/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: 2-Punkt Temperaturregelung

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


#define SetPoint 23 // Temperatur-Vorwahl
#define RELAY 5 // RELAIS
#define START 19 // START
//
// I2C LCD libraries
//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//
// DHT11 libraries
//
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHT11_PIN 18
#define DHTTYPE DHT11
//
// Temperatur Variablen
//
int MinTemperature = 15;
int MaxTemperature = 30;
// Min set
// Max set
int RequiredTemperature;
int First = 1;
DHT dht(DHT11_PIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
pinMode(RELAY, OUTPUT); // Relais
pinMode(SetPoint, INPUT_PULLUP); // Temperatur-Vorwahl
pinMode(START, INPUT_PULLUP); // Start
digitalWrite(RELAY, LOW); // RELAIS in Ruhe OFF
dht.begin(); // Init DHT11
lcd.begin(); // Init LCD
lcd.backlight(); // Backlight ein
}
//
// Temperatur beim Start vorwÃ¤hlen
// Die Temperatur kann zwischen 15 und 30Â°C eingestellt werden
// Mit dem Start-Taster die Regelung starten
//
int SetTemperature()
{
int ExitFlag = 0;
lcd.setCursor(0, 0); // Go to col 0, row 0
lcd.print("Temp. Vorwahl"); // Display Temp. Vorwahl
lcd.setCursor(0, 1); // LCD Position Spalte 0, Zeichen 1
RequiredTemperature = MinTemperature;
lcd.print(RequiredTemperature);
while(ExitFlag == 0)
{
if(digitalRead(SetPoint) == 0)
{
RequiredTemperature++;
if(RequiredTemperature > MaxTemperature)
{
RequiredTemperature = MinTemperature;
}
lcd.setCursor(0, 1);
lcd.print(RequiredTemperature);
delay(150);
}
else if(digitalRead(START) == 0)
{
ExitFlag = 1;
}
}
lcd.clear();
return RequiredTemperature;
}

void loop()
{
if(First == 1)
{
RequiredTemperature = SetTemperature();
First = 0;
}
int Measured = dht.readTemperature(); // Temperatur einlesen
lcd.setCursor(0,0); // Spalte 0,Zeile 0
lcd.print(" IST-T: "); // Display IST-T:
lcd.print(Measured);
lcd.print(char(223)); // Grad-Zeichen
lcd.print(" Rel");

lcd.setCursor(0,1); // Spalte 0,Zeile 1
lcd.print("SOLL-T: "); // Display SOLL-T:
lcd.print(RequiredTemperature);
lcd.print(char(223));

if(RequiredTemperature > Measured)
{
digitalWrite(RELAY, HIGH); // Relais ON
lcd.print(" ON "); // Display "ON"
}
else
{
digitalWrite(RELAY, LOW); // Relais OFF
lcd.print(" OFF"); // Display "OFF"
}
delay(1000);

}
