void go_left(){
  if(serial_updated){
    lock_bot(500);
    for(int i=1;i<=7;i++){
      write_servo_values(left_v[i][1], left_v[i][2], left_v[i][3], left_v[i][4], left_v[i][5], left_v[i][6], left_v[i][7], left_v[i][8], left_v[i][9], left_v[i][10]);
    }
  }
}
