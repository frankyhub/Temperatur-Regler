<a name="oben"></a>

# Temperatur-Regler
2-Punkt Temperaturregelung mit Display

## Story
Das ist ein Programm für eine 2-Punkt Temperaturregelung. Beim Start kann der Sollwert vorgegeben werden. Nach Betätigung der Start-Taste startet die Regelung und zeigt den IST-Wert und den SOLL-Wert am Display an. Zusätzlich erhält man am Display die Info, ob der Relaisausgang on oder off ist.

## Hardware

Die Hardware für dieses Projekt:

| Anzahl | Bezeichnung | 
| -------- | -------- | 
| 1  | ESP32   |
| 1  | DHT11   |
| 1  |  2C 1602 Display  |
| 2  | Taster   |
| 1  |  Relais  |
| ---  | ---   |


## ESP32-Programme

- Programm 1: I2C Scanner.
- Programm 2: LCD 1602 Test.
- Programm 3: Temperaturregler.

## Installation

- Die Programme in die Arduino IDE kopieren und in den ESP32 laden.
- DHT11 an 3,3V und GND anschließen, S an GPIO 18.
- Das I2C-Dispaly an 5V und GND anschließen. SDA an GPIO 21, SDL an GPIO 22.
- Den Start-Taster an GPIO 19 anschließen.
- Den Temperatur-Vorwahl-Taster an GPIO 23 anschließen.
- Das Relais an GPIO 5 anschließen.


### Temperatur Vorwahl

![Bild](/pic/tvorwahl.png)


### Temperaturregelung ON

![Bild](/pic/treglungon.png)

### Temperaturregelung OFF

![Bild](/pic/treglungoff.png)



<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div> 


