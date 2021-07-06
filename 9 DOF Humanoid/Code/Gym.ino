void do_gym(){
  if(serial_updated){
    lock_bot(500);
    for(int i=1;i<=1;i++){
      write_servo_values(gym_v[i][1], gym_v[i][2], gym_v[i][3], gym_v[i][4], gym_v[i][5], gym_v[i][6], gym_v[i][7], gym_v[i][8], gym_v[i][9], gym_v[i][10]);
    }
  }

  for(int j=0;j<=3;j++){
    for(int i=2;i<=3;i++){
      write_servo_values(gym_v[i][1], gym_v[i][2], gym_v[i][3], gym_v[i][4], gym_v[i][5], gym_v[i][6], gym_v[i][7], gym_v[i][8], gym_v[i][9], gym_v[i][10]);
    }
  }

  for(int j=0;j<=3;j++){
    for(int i=4;i<=5;i++){
      write_servo_values(gym_v[i][1], gym_v[i][2], gym_v[i][3], gym_v[i][4], gym_v[i][5], gym_v[i][6], gym_v[i][7], gym_v[i][8], gym_v[i][9], gym_v[i][10]);
    }
  }

  for(int j=0;j<=3;j++){
    for(int i=6;i<=7;i++){
      write_servo_values(gym_v[i][1], gym_v[i][2], gym_v[i][3], gym_v[i][4], gym_v[i][5], gym_v[i][6], gym_v[i][7], gym_v[i][8], gym_v[i][9], gym_v[i][10]);
    }
  }

  for(int j=0;j<=3;j++){
    for(int i=8;i<=9;i++){
      write_servo_values(gym_v[i][1], gym_v[i][2], gym_v[i][3], gym_v[i][4], gym_v[i][5], gym_v[i][6], gym_v[i][7], gym_v[i][8], gym_v[i][9], gym_v[i][10]);
    }
  }
}

