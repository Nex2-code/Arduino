void do_namaste(int time_ms){
  if(serial_updated)
    centralise_feet(350);
  write_servo_values(namaste_v[1], namaste_v[2], namaste_v[3], namaste_v[4], namaste_v[5], namaste_v[6], namaste_v[7], namaste_v[8], namaste_v[9], time_ms);
}
