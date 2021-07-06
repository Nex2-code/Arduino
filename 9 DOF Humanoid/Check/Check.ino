#include "Config.h"

int pin = mot_1_pin;

int val = 1500;

void setup() {
  Serial.begin(115200);

  pinMode(mot_1_pin, OUTPUT);
  pinMode(mot_2_pin, OUTPUT);
  pinMode(mot_3_pin, OUTPUT);
  pinMode(mot_4_pin, OUTPUT);
  pinMode(mot_5_pin, OUTPUT);
  pinMode(mot_6_pin, OUTPUT);
  pinMode(mot_7_pin, OUTPUT);
  pinMode(mot_8_pin, OUTPUT);
  pinMode(mot_9_pin, OUTPUT);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  if(Serial.available()){
    int data = Serial.parseInt();

    if(data >= 1 && data <= 9){
      pin = data + 2;
      val = c_v[data];
    }
    else
      val = data;
  }

  digitalWrite(pin, HIGH);
  delayMicroseconds(val);
  digitalWrite(pin, LOW);

  Serial.print(pin - 2); Serial.print("   ");
  Serial.println(val);

  delay(10);
}




