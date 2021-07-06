void go_back(){
  if(serial_updated){
    lock_bot(500);
    for(int i=1;i<=4;i++){
      write_servo_values(back_v[i][1], back_v[i][2], back_v[i][3], back_v[i][4], back_v[i][5], back_v[i][6], back_v[i][7], back_v[i][8], back_v[i][9], back_v[i][10]);
    }
  }

  for(int i=5;i<=10;i++){
      write_servo_values(back_v[i][1], back_v[i][2], back_v[i][3], back_v[i][4], back_v[i][5], back_v[i][6], back_v[i][7], back_v[i][8], back_v[i][9], back_v[i][10]);
    }
}
