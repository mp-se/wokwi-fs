#include <Arduino.h>
#include <FS.h>

//#define USE_SPIFFS true

#ifdef USE_SPIFFS
#include <SPIFFS.h>
#define LittleFS SPIFFS
#else
#include <LittleFS.h>
#endif

void setup() {
  Serial.begin(115200L);
  Serial.printf("Starting\n");

  LittleFS.begin(true);

  File f = LittleFS.open("/myfile.txt", "r");
  if(f) {
    String s = f.readStringUntil('\r');
    Serial.println(s.c_str());
    f.close();
    Serial.printf("Read successful\n");
  }else {
    Serial.printf("Failed to open file for reading\n");
  }

  f = LittleFS.open("/test", "w");
  if(f) {
    f.write('C');
    f.close();
    Serial.printf("Write successful\n");
  }else {
    Serial.printf("Failed to open file for writing\n");
  }
}

void loop() {
}
