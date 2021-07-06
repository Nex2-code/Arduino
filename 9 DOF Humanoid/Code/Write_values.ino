void write_motor_value(int pin, int len){
  digitalWrite(pin, HIGH);
  delayMicroseconds(len);
  digitalWrite(pin, LOW);
}

void centralise_feet(int time_ms){
  unsigned long loop_timer = millis();

  while(millis() - loop_timer <= time_ms){
    write_motor_value(mot_7_pin, c_v[7]);
    write_motor_value(mot_9_pin, c_v[9]);

    delay(20);
  }
}

void write_servo_values(int mot_1_len, int mot_2_len, int mot_3_len, int mot_4_len, int mot_5_len, int mot_6_len, int mot_7_len, int mot_8_len, int mot_9_len, int time_ms){
  unsigned long loop_timer = millis();

  while(millis() - loop_timer <= time_ms){
    write_motor_value(mot_1_pin, mot_1_len);
    write_motor_value(mot_2_pin, mot_2_len);
    write_motor_value(mot_3_pin, mot_3_len);
    write_motor_value(mot_4_pin, mot_4_len);
    write_motor_value(mot_5_pin, mot_5_len);
    write_motor_value(mot_6_pin, mot_6_len);
    write_motor_value(mot_7_pin, mot_7_len);
    write_motor_value(mot_8_pin, mot_8_len);
    write_motor_value(mot_9_pin, mot_9_len);

    delay(20);
  }
}

