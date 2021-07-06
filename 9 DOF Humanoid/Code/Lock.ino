void lock_bot(int time_ms){
  if(serial_updated)
    centralise_feet(350);
  write_servo_values(c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6], c_v[7], c_v[8], c_v[9], time_ms);
}

