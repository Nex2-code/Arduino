#include "Config.h"
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(12, 13);

String data = "";
bool serial_updated = false;

void setup() {
  Serial.begin(115200);
  bluetooth.begin(9600);

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

  bluetooth.println("-> Hello human.. Humanoid this side..!\n");
  
  bluetooth.println("-> Welcome Wingfotech Pvt. Ltd.!\n");
}

void loop() {
  read_serial();

  if(data == "lock\r")
    lock_bot(10);
  else if(data == "forward\r")
    go_forward();
  else if(data == "back\r")
    go_back();
  else if(data == "left\r")
    go_left();
  else if(data == "right\r")
    go_right();
  else if(data == "namaste\r")
    do_namaste(10);
  else if(data == "gym\r")
    do_gym();
  else if(data == "no\r")
    do_no();
}
