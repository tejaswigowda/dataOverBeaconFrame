#include <SimpleDHT.h>
int pinDHT11 = D1;
SimpleDHT11 dht11(pinDHT11);

extern "C" {
  #include "user_interface.h"
}
#include <ESP8266WiFi.h> 




void setup() {
  Serial.begin(115200);
  delay(100);
    WiFi.mode(WIFI_AP_STA);t
    WiFi.softAP("Loading...", "");
    WiFi.begin();
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  t = float(temperature)*1.8+32;
  h = float(humidity);
  
  // DHT11 sampling rate is 1HZ.
  String es = "FDN-{\"t\":" + String(t) + ",\"h\":" + String(h) + "}";
  char eschar[32];
  es.toCharArray(eschar,es.length()+1);
  WiFi.softAP(eschar, "");
  WiFi.begin();
  Serial.println(eschar);

  delay(1000);


}
