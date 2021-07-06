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

  if(pin == mot_1_pin)
    write_servo_values(val, c_v[2], c_v[3], c_v[4], c_v[5], c_v[6], c_v[7], c_v[8], c_v[9], 10);
  else if(pin == mot_2_pin)
    write_servo_values(c_v[1], val, c_v[3], c_v[4], c_v[5], c_v[6], c_v[7], c_v[8], c_v[9], 10);
  else if(pin == mot_3_pin)
    write_servo_values(c_v[1], c_v[2], val, c_v[4], c_v[5], c_v[6], c_v[7], c_v[8], c_v[9], 10);
  else if(pin == mot_4_pin)
    write_servo_values(c_v[1], c_v[2], c_v[3], val, c_v[5], c_v[6], c_v[7], c_v[8], c_v[9], 10);
  else if(pin == mot_5_pin)
    write_servo_values(c_v[1], c_v[2], c_v[3], c_v[4], val, c_v[6], c_v[7], c_v[8], c_v[9], 10);
  else if(pin == mot_6_pin)
    write_servo_values(c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], val, c_v[7], c_v[8], c_v[9], 10);
  else if(pin == mot_7_pin)
    write_servo_values(c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6], val, c_v[8], c_v[9], 10);
  else if(pin == mot_8_pin)
    write_servo_values(c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6], c_v[7], val, c_v[9], 10);
  else if(pin == mot_9_pin)
    write_servo_values(c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6], c_v[7], c_v[8], val, 10);

  Serial.print(pin - 2); Serial.print("   ");
  Serial.println(val);
}
