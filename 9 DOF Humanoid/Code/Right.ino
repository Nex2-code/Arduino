void go_right(){
  if(serial_updated){
    lock_bot(500);
    for(int i=1;i<=7;i++){
      write_servo_values(right_v[i][1], right_v[i][2], right_v[i][3], right_v[i][4], right_v[i][5], right_v[i][6], right_v[i][7], right_v[i][8], right_v[i][9], right_v[i][10]);
    }
  }
}
