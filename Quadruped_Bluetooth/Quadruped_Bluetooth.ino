#include <Servo.h>    // include servo library

//===== Globals ============================================================================

char state;

// calibration
int da =  -12,  // Left Front Pivot
    db =   10,  // Left Back Pivot
    dc =  -18,  // Right Back Pivot
    dd =   12;  // Right Front Pivot

// servo initial positions + calibration
int a90  = (90  + da),
    a120 = (120 + da),
    a150 = (150 + da),
    a180 = (180 + da);

int b0   = (0   + db),
    b30  = (30  + db),
    b60  = (60  + db),
    b90  = (90  + db);

int c90  = (90  + dc),
    c120 = (120 + dc),
    c150 = (150 + dc),
    c180 = (180 + dc);

int d0   = (0   + dd),
    d30  = (30  + dd),
    d60  = (60  + dd),
    d90  = (90  + dd);

// start points for servo
int s11 = 90; // Front Left Pivot Servo
int s12 = 90; // Front Left Lift Servo
int s21 = 90; // Back Left Pivot Servo
int s22 = 90; // Back Left Lift Servo
int s31 = 90; // Back Right Pivot Servo
int s32 = 90; // Back Right Lift Servo
int s41 = 90; // Front Right Pivot Servo
int s42 = 90; // Front Right Lift Servo

int f    = 0;
int b    = 0;
int l    = 0;
int r    = 0;
int spd  = 3;  // Speed of walking motion, larger the number, the slower the speed
int high = 0;   // How high the robot is standing

// Define 8 Servos
Servo myServo1; // Front Left Pivot Servo
Servo myServo2; // Front Left Lift Servo
Servo myServo3; // Back Left Pivot Servo
Servo myServo4; // Back Left Lift Servo
Servo myServo5; // Back Right Pivot Servo
Servo myServo6; // Back Right Lift Servo
Servo myServo7; // Front Right Pivot Servo
Servo myServo8; // Front Right Lift Servo

//==========================================================================================

//===== Setup ==============================================================================

void setup()
{
  // Attach servos to Arduino Pins
  myServo1.attach(5); //s8  // Front Left Pivot 
  myServo2.attach(6); //s7  // Front Left Lift Servo
  myServo3.attach(7); //s6  // Back Left Pivot Servo
  myServo4.attach(8); //s5  // Back Left Lift Servo
  myServo5.attach(9); //s4  // Back Right Pivot Servo
  myServo6.attach(10);//s3  // Back Right Lift Servo
  myServo7.attach(11);//s2  // Front Right Pivot Servo
  myServo8.attach(12);//s1  // Front Right Lift Servo
//
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);

   Serial.begin (9600);

}

void loop()
{
  if(Serial.available() > 0)
      {     
      state = Serial.read();
      Serial.println(state);
      }
  unsigned long value;
  unsigned long lastValue;
  
  center_servos();  // Center all servos
  high = 15;        // Set hight to 15
  spd = 6;          // Set speed to 3

  
     value = state;

      switch (value)
      {
        case 'F':
            
          forward();
          break;

        case 'B':
          back();
          break;

        case 'R':
     
          turn_right();
          break;

        case 'L':
     
          turn_left();
          break;

        case 'W':
          dance();
          break;

        case 'w':
          wave();
          break;

        case 'S':
         
          center_servos();
          break;

        default:
          break;
      }   
  }
