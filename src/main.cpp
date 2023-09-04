#include <Arduino.h>
#include <FS.h>

/*#include <SPIFFS.h>

void setup() {
  Serial.begin(115200L);
  Serial.printf("Starting\n");

  SPIFFS.begin(true);

  File f = SPIFFS.open("/test", "w");

  if(f) {
    f.write('C');
    f.close();
    Serial.printf("Write successful\n");
  }else {
    Serial.printf("Failed to open file\n");
  }
}*/


#include <LittleFS.h>
void setup() {
  Serial.begin(115200L);
  Serial.printf("Starting\n");

  LittleFS.begin(true);
 
  File f = LittleFS.open("/test", "w");

  if(f) {
    f.write('C');
    f.close();
    Serial.printf("Write successful\n");
  }else {
    Serial.printf("Failed to open file\n");
  }
}

void loop() {
}
