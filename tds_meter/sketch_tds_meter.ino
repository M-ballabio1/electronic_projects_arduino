#include <EEPROM.h>
#include "GravityTDS.h"
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
#define TdsSensorPin A1
GravityTDS gravityTds;
 
float temperature = 25,tdsValue = 0;

// set the monitor to 115200 baud (velocità refresh del lcd)

void setup()
{
    Serial.begin(115200);
    lcd.begin(16,2);
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
}
 
void loop()
{
    //temperature = readTemperature();  //add your temperature sensor and read it
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value
    
    lcd.setCursor(0, 0);
    lcd.print("TDS Value:");
    lcd.setCursor(0, 1);
    lcd.print(tdsValue, 0);
    lcd.print(" PPM");

    Serial.print("TDS: ");
    Serial.println(tdsValue, 1); // Mostra il valore con 2 decimali

    delay(1000); // Pausa di 1 secondo tra le letture
}
