#include<ESP8266WiFi.h>

#define ssid "FRITZ!Box 7530 UL"
#define password "xxxx"

void setup() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  Serial.begin(115200);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  // pinMode(LedPin, OUTPUT);
  // digitalWrite(LedPin, LOW);

}

void loop() {  

}
