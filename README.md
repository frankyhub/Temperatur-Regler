<a name="oben"></a>

<div align="center">

|[:skull:ISSUE](https://github.com/frankyhub/Temperatur-Regler/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/Temperatur-Regler/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/Temperatur-Regler/wiki)||
|--|--|--|--|
| | | | |
|![Static Badge](https://img.shields.io/badge/RepoNr.:-%2039-blue)|<a href="https://github.com/frankyhub/Temperatur-Regler/issues">![GitHub issues](https://img.shields.io/github/issues/frankyhub/Temperatur-Regler)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/Temperatur-Regler)|<a href="https://github.com/frankyhub/Temperatur-Regler/discussions">![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/Temperatur-Regler)|<a href="https://github.com/frankyhub/Temperatur-Regler/releases">![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/Temperatur-Regler)|
|![GitHub Created At](https://img.shields.io/github/created-at/frankyhub/Temperatur-Regler)| <a href="https://github.com/frankyhub/Temperatur-Regler/pulse" alt="Activity"><img src="https://img.shields.io/github/commit-activity/m/badges/shields" />| <a href="https://github.com/frankyhub/Temperatur-Regler/graphs/traffic"><img alt="ViewCount" src="https://views.whatilearened.today/views/github/frankyhub/github-clone-count-badge.svg">  |<a href="https://github.com/frankyhub?tab=stars"> ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)|
</div>



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



---

<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---


