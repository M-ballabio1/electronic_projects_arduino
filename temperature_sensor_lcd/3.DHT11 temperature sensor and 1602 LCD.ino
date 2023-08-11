#include <DHT.h>

#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
// dht11 è il tipo di sensore che uso
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// connessione display (pin)
 
void setup() {
Serial.begin(9600);
delay(1000);
lcd.begin(16, 2);
// imposto il tipo di display (colonne, righe)
lcd.print("Temperatura");
lcd.setCursor(0,1);
lcd.print("Umidita'");
dht.begin();
}
void loop() {
int t = dht.readTemperature();
int h = dht.readHumidity();
lcd.setCursor(14, 0);
lcd.print(t);
lcd.setCursor(14, 1);
lcd.print(h);
}
