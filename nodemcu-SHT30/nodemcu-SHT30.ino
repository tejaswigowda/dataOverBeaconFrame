#include <Wire.h>
#include "Adafruit_SHT31.h"
Adafruit_SHT31 sht31 = Adafruit_SHT31();


extern "C" {
  #include "user_interface.h"
}
#include <ESP8266WiFi.h> 




void setup() {
  Serial.begin(115200);
  delay(100);
  
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("Loading...", "");
    WiFi.begin();

  if (! sht31.begin(0x44)) 
  {
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
}

void loop() {
  float t = sht31.readTemperature() * 1.8 + 32;
  float h = sht31.readHumidity();
  String es = "FDN-{\"t\":" + String(t) + ",\"h\":" + String(h) + "}";
  char eschar[32];
  es.toCharArray(eschar,es.length()+1);
  WiFi.softAP(eschar, "");
  WiFi.begin();
  Serial.println(eschar);

  delay(1000);


}
