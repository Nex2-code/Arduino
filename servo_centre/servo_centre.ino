#include <Servo.h>
#define MAX_PULSE  1750
#define MIN_PULSE  1250
#define CENTER_PULSE 1500
Servo servoToCenter;
Servo servoToCenter1;
Servo servoToCenter2;
Servo servoToCenter3;
int servoPins = 12;
int servoPins1 = 3;
int servoPins2 = 4;
int servoPins3 = 6;
void setup()
{
  servoToCenter.attach(servoPins);
  servoToCenter1.attach(servoPins1);
  servoToCenter2.attach(servoPins2);
  servoToCenter3.attach(servoPins3);
  servoToCenter.writeMicroseconds(MIN_PULSE);
  servoToCenter1.writeMicroseconds(MIN_PULSE);
  servoToCenter2.writeMicroseconds(MIN_PULSE);
  servoToCenter3.writeMicroseconds(MIN_PULSE);
  delay(1000);
    servoToCenter.attach(servoPins);
    servoToCenter1.attach(servoPins1);
    servoToCenter2.attach(servoPins2);
    servoToCenter3.attach(servoPins3);
    servoToCenter.writeMicroseconds(MAX_PULSE);
    servoToCenter1.writeMicroseconds(MAX_PULSE);
    servoToCenter2.writeMicroseconds(MAX_PULSE);
    servoToCenter3.writeMicroseconds(MAX_PULSE);
  delay(1000);
    servoToCenter.attach(servoPins);
    servoToCenter1.attach(servoPins1);
    servoToCenter2.attach(servoPins2);
    servoToCenter3.attach(servoPins3);
    servoToCenter.writeMicroseconds(CENTER_PULSE);
    servoToCenter1.writeMicroseconds(CENTER_PULSE);
    servoToCenter2.writeMicroseconds(CENTER_PULSE);
    servoToCenter3.writeMicroseconds(CENTER_PULSE);
}
void loop()
{
}
