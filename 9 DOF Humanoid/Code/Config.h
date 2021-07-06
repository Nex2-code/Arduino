#define mot_1_pin 3   // Head           // On increasing pulse, motor rotates towards right
#define mot_2_pin 4   // Left shoulder  // On increasing pulse, motor rotates towards front
#define mot_3_pin 5   // Left arm       // On increasing pulse, motor rotates towards outside
#define mot_4_pin 6   // Right shoulder // On increasing pulse, motor rotates towards back
#define mot_5_pin 7   // Right arm      // On increasing pulse, motor rotates towards inside

#define mot_6_pin 8   // Left thigh     // On increasing pulse, motor rotates towards outside
#define mot_7_pin 9   // Left foot      // On increasing pulse, motor rotates clockwise
#define mot_8_pin 10  // Right thigh    // On increasing pulse, motor rotates towards inside
#define mot_9_pin 11  // Right foot     // On increasing pulse, motor rotates clockwise

//                       1     2     3     4     5     6     7     8     9
const int c_v[10] = {0, 1520, 1400, 1500, 1500, 1400, 1500, 1500, 1600, 1200};

const int forward_v[11][11] = {
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 10},  //Centre

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 160, c_v[7]      , c_v[8] - 160, c_v[9]      , 400}, //Separate legs
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 160, c_v[7] + 125, c_v[8] - 160, c_v[9] + 300, 700}, //Lean towards left
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 170, c_v[7] + 125, c_v[8] - 160, c_v[9] + 300, 400}, //Move right leg forward by rotating left leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 170, c_v[7]      , c_v[8] - 160, c_v[9]      , 400}, //Come to centre from left lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 160, c_v[7] - 300, c_v[8] - 160, c_v[9] - 125, 700}, //Bring left leg to centre, lean right
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 160, c_v[7] - 300, c_v[8] + 340, c_v[9] - 125, 400}, //Move left leg forward by rotating right leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 160, c_v[7]      , c_v[8] + 340, c_v[9]      , 400}, //Come to centre from right lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 160, c_v[7] + 125, c_v[8] - 160, c_v[9] + 300, 700}, //Bring right leg to centre, lean towards left
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 300, c_v[7] + 125, c_v[8] - 160, c_v[9] + 300, 400}, //Move right leg forward by rotating left leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 300, c_v[7]      , c_v[8] - 160, c_v[9]      , 400}, //Come to centre from left lean
};

const int back_v[11][11] = {
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 10},  //Centre

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 140, c_v[7]      , c_v[8] + 140, c_v[9]      , 400}, //Separate legs
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 140, c_v[7] + 125, c_v[8] + 140, c_v[9] + 300, 700}, //Lean towards left
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 170, c_v[7] + 125, c_v[8] + 140, c_v[9] + 300, 400}, //Move right leg backward by rotating left leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 170, c_v[7]      , c_v[8] + 140, c_v[9]      , 400}, //Come to centre from left lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 140, c_v[7] - 300, c_v[8] + 140, c_v[9] - 125, 700}, //Bring left leg to centre, lean right
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 140, c_v[7] - 300, c_v[8] - 340, c_v[9] - 125, 400}, //Move left leg backward by rotating right leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 140, c_v[7]      , c_v[8] - 340, c_v[9]      , 400}, //Come to centre from right lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 140, c_v[7] + 125, c_v[8] + 140, c_v[9] + 300, 700}, //Bring right leg to centre, lean towards left
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 300, c_v[7] + 125, c_v[8] + 140, c_v[9] + 300, 400}, //Move right leg backward by rotating left leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 300, c_v[7]      , c_v[8] + 140, c_v[9]      , 400}, //Come to centre from left lean
};

const int left_v[8][11] = {
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 10},  //Centre

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7] - 300, c_v[8]      , c_v[9] - 125, 700}, //Lean towards right
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7] - 300, c_v[8] + 180, c_v[9] - 125, 400}, //Move left leg forward by rotating right leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8] + 180, c_v[9]      , 400}, //Come to centre from right lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7] + 125, c_v[8]      , c_v[9] + 300, 700}, //Bring right leg to centre, lean left
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 400, c_v[7] + 125, c_v[8]      , c_v[9] + 300, 400}, //Move right leg backward by rotating left leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] + 400, c_v[7]      , c_v[8]      , c_v[9]      , 400}, //Come to centre from right lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},  //Centre
};

const int right_v[8][11] = {
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 10},  //Centre

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7] + 125, c_v[8]      , c_v[9] + 300, 700}, //Lean towards left
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 180, c_v[7] + 125, c_v[8]      , c_v[9] + 300, 400}, //Move right leg forward by rotating left leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6] - 180, c_v[7]      , c_v[8]      , c_v[9]      , 400}, //Come to centre from left lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7] - 300, c_v[8]      , c_v[9] - 125, 700}, //Bring left leg to centre, lean right
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7] - 300, c_v[8] - 400, c_v[9] - 125, 400}, //Move left leg backward by rotating right leg
  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8] - 400, c_v[9]      , 400}, //Come to centre from right lean

  {0, c_v[1], c_v[2], c_v[3], c_v[4], c_v[5], c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},  //Centre
};

const int namaste_v[10] = {0, c_v[1]      , c_v[2] + 830, c_v[3] - 200, c_v[4] - 840, c_v[5] + 200, c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      };

const int gym_v[10][11] = {
  {0, c_v[1]      , c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 10},  //Centre
  {0, c_v[1]      , c_v[2]      , c_v[3] + 600, c_v[4]      , c_v[5] - 600, c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 700},
  //Shoulder + Arm
  {0, c_v[1]      , c_v[2] + 480, c_v[3] + 600, c_v[4] - 480, c_v[5] - 600, c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 700},
  {0, c_v[1]      , c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 700},  //Centre
  //Shoulder + Arm + Head
  {0, c_v[1] + 200, c_v[2] + 480, c_v[3] + 600, c_v[4] - 480, c_v[5] - 600, c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 700},
  {0, c_v[1] - 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 700},
  //Shoulder + Arm + Head + Thighs
  {0, c_v[1] + 200, c_v[2] + 480, c_v[3] + 600, c_v[4] - 480, c_v[5] - 600, c_v[6] + 180, c_v[7]      , c_v[8] - 120, c_v[9]      , 700},
  {0, c_v[1] - 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6] - 180, c_v[7]      , c_v[8] + 120, c_v[9]      , 700},
  //Shoulder + Arm + Head + Foot
  {0, c_v[1] + 200, c_v[2] + 480, c_v[3] + 600, c_v[4] - 480, c_v[5] - 600, c_v[6]      , c_v[7] + 150, c_v[8]      , c_v[9] - 175, 700},
  {0, c_v[1] - 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7] - 150, c_v[8]      , c_v[9] + 175, 700},
};

const int no_v[6][11] = {
  {0, c_v[1]      , c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 10},  //Centre
  
  {0, c_v[1] + 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},
  {0, c_v[1] - 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},
  {0, c_v[1] + 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},
  {0, c_v[1] - 200, c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},
  {0, c_v[1]      , c_v[2]      , c_v[3]      , c_v[4]      , c_v[5]      , c_v[6]      , c_v[7]      , c_v[8]      , c_v[9]      , 400},  //Centre
};
