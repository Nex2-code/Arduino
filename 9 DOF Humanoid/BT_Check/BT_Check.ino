#include <SoftwareSerial.h>

SoftwareSerial bt(12,13);

void setup() {
  Serial.begin(115200);
  bt.begin(9600);
}

void loop() {
  if(bt.available()){
    String data = bt.readStringUntil('\n');
    Serial.print("Received : "); Serial.println(data);
  }

  if(Serial.available()){
    String data = Serial.readStringUntil('\n');
    bt.print(data);
  }

  delay(10);
}

