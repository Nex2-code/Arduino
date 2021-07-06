#include <LiquidCrystal.h>
// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);
int u = 12;
int v = 13;
int m = 8;
int m1 = 9;
int m2 = 10;
int m3 = 11;
int i = A0;
int i1 = A1;
int cnt = 0;
int button1 = LOW;
int button = LOW;
int x = 0;
int data=0;
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome To");
  lcd.setCursor(0, 1);
  lcd.print("Wingfotech");
  delay(1000);
  lcd.clear();
  pinMode(u, INPUT_PULLUP);
  pinMode(v, INPUT_PULLUP);
  pinMode(m, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(i, INPUT);
  pinMode(i1, INPUT);
  Serial.begin(9600);
}
void loop()
{
  button = digitalRead(u);
  button1 = digitalRead(v);
  ma();
}
