/*Movement keys for robot are "s":Stand,"t":Sleep "f":Forward, "b":backward, "l":Left
   "r":Right, "w":hand wave, "e":Hand Shake
   Connection For:
   Left Leg (D2-D4)
   Left rear Leg (D5-D7)
   Right Leg (D8-D10)
   Right Rear Leg (D11-D13)
*/
#include <Servo.h>    //to define and control servos
#include <FlexiTimer2.h> //to set a timer to manage all servos
Servo servo[4][3];
//define servos' ports
#define MAX_PULSE  1750
#define MIN_PULSE  1250
#define CENTER_PULSE 1500
const int servo_pin[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };
/* Size of the robot ---------------------------------------------------------*/
const float length_a = 50;
const float length_b = 77.1;
const float length_c = 27.5;
const float length_side = 71;
const float z_absolute = -28;
/* Constants for movement ----------------------------------------------------*/
const float z_default = -50, z_up = -30, z_boot = z_absolute;
const float x_default = 62, x_offset = 0;
const float y_start = 0, y_step = 40;
const float y_default = x_default;
/* variables for movement ----------------------------------------------------*/
volatile float site_now[4][3];    //real-time coordinates of the end of each leg
volatile float site_expect[4][3]; //expected coordinates of the end of each leg
float temp_speed[4][3];   //each axis' speed, needs to be recalculated before each movement
float move_speed;     //movement speed
float speed_multiple = 1; //movement speed multiple
const float spot_turn_speed = 4;
const float leg_move_speed = 8;
const float body_move_speed = 3;
const float stand_seat_speed = 1;
volatile int rest_counter;      //+1/0.02s, for automatic rest
//functions' parameter
const float KEEP = 255;
//define PI for calculation
const float pi = 3.1415926;
/* Constants for turn --------------------------------------------------------*/
//temp length
const float temp_a = sqrt(pow(2 * x_default + length_side, 2) + pow(y_step, 2));
const float temp_b = 2 * (y_start + y_step) + length_side;
const float temp_c = sqrt(pow(2 * x_default + length_side, 2) + pow(2 * y_start + y_step + length_side, 2));
const float temp_alpha = acos((pow(temp_a, 2) + pow(temp_b, 2) - pow(temp_c, 2)) / 2 / temp_a / temp_b);
//site for turn
const float turn_x1 = (temp_a - length_side) / 2;
const float turn_y1 = y_start + y_step / 2;
const float turn_x0 = turn_x1 - temp_b * cos(temp_alpha);
const float turn_y0 = temp_b * sin(temp_alpha) - turn_y1 - length_side;
char SerialData;
char data;
void setup()
{
  //start serial for debug
  Serial.begin(9600);
  Serial.println("Servo Calibration");
  delay(500);
  Serial.println("Booting UP");
  //initialize default parameter
  Serial.println("Wait");
  set_site(0, x_default - x_offset, y_start + y_step, z_boot);
  set_site(1, x_default - x_offset, y_start + y_step, z_boot);
  set_site(2, x_default + x_offset, y_start , z_boot);
  set_site(3, x_default + x_offset, y_start, z_boot);
  Serial.println("Wait");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      site_now[i][j] = site_expect[i][j];
    }
    delay(1000);
  }

  FlexiTimer2::set(20, servo_service);
  FlexiTimer2::start();
  //initialize servos
  Serial.println("Hello im spidey");
}
void loop()
{
  if (Serial.available() > 0)
  {
    delay(10);
    data = Serial.read();
    Serial.println(data);
    if (data == 's')
    {
      Serial.println("Standing");
      servo_attach();
      delay(300);
      stand();
    }
    if (data == 'f')
    {
      Serial.println("Moving Forward");
      step_forward(6);
    }
    if (data == 'b')
    {
      Serial.println("Moving Back");
      step_back(6);
    }
    if (data == 'l')
    {
      Serial.println("Moving left");
      turn_left(6);
    }
    if (data == 'r')
    {
      Serial.println("Moving right");
      turn_right(5);
    }
    if (data == 'w')
    {
      Serial.println("hii");
      hand_wave(3);
    }
    if (data == 't')
    {
      Serial.println("Sleeping");
      sit();
    }
    if (data == 'e')
    {
      Serial.println("nice to meet you");
      hand_shake(3);
    }
    if (data == 'p')
    {
      Serial.println("zzzzzzzzz");
      sleep();
    }
  }
}
