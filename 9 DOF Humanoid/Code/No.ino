void do_no(){
  if(serial_updated){
    lock_bot(500);
    for(int i=1;i<=5;i++){
      write_servo_values(no_v[i][1], no_v[i][2], no_v[i][3], no_v[i][4], no_v[i][5], no_v[i][6], no_v[i][7], no_v[i][8], no_v[i][9], no_v[i][10]);
    }
  }
}

