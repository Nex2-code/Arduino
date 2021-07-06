void go_forward(){
  if(serial_updated){
    lock_bot(500);
    for(int i=1;i<=4;i++){
      write_servo_values(forward_v[i][1], forward_v[i][2], forward_v[i][3], forward_v[i][4], forward_v[i][5], forward_v[i][6], forward_v[i][7], forward_v[i][8], forward_v[i][9], forward_v[i][10]);
    }
  }

  for(int i=5;i<=10;i++){
    write_servo_values(forward_v[i][1], forward_v[i][2], forward_v[i][3], forward_v[i][4], forward_v[i][5], forward_v[i][6], forward_v[i][7], forward_v[i][8], forward_v[i][9], forward_v[i][10]);
  }
}
