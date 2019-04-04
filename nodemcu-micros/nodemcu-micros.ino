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
}

void loop() {

  String es = "FDN-" + String(micros());
  char eschar[32];
  es.toCharArray(eschar,es.length()+1);
  WiFi.softAP(eschar, "");
  WiFi.begin();
  Serial.println(eschar);

  delay(10000);


}
