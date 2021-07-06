void ma()
{
  if ((button == LOW ) && (cnt == 0))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Mode");
    lcd.setCursor(0, 1);
    lcd.print("-- Nxt");
    delay(100);
    cnt++;
  }
  if ((button == HIGH ) && (cnt == 1))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Mode");
    lcd.setCursor(0, 1);
    lcd.print("LFR");
    delay(200);
    cnt++;
    button = LOW;
    x = 1;
  }
  if ((button == HIGH ) && (cnt == 2))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Mode");
    lcd.setCursor(0, 1);
    lcd.print("Bluetooth Cont");
    delay(200);
    cnt++;
    button = LOW;
    x = 2;
  }
  if ((button == HIGH ) && (cnt == 3))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Mode");
    lcd.setCursor(0, 1);
    lcd.print("Pattern 3");
    delay(200);
    cnt++;
    button = LOW;
    x = 3;
  }
  if ((button == HIGH ) && (cnt == 4))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Mode");
    lcd.setCursor(0, 1);
    lcd.print("Pattern 4");
    delay(200);
    button = LOW;
    cnt = 1;
    x = 4;
  }
  if ((button == LOW ) && (button1 == HIGH) && (x == 1))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OK");
    lcd.setCursor(0, 1);
    lcd.print("LFR");
    delay(200);
    ir();
    button1 = LOW;
  }
  if ((button == LOW ) && (button1 == HIGH) && (x == 2))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OK");
    lcd.setCursor(0, 1);
    lcd.print("Bluetooth Cont");
    delay(200);
    button1 = LOW;
    blue();
  }
  if ((button == LOW ) && (button1 == HIGH) && (x == 3))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OK");
    lcd.setCursor(0, 1);
    lcd.print("Displaying P3");
    delay(200);
    button1 = LOW;
    p3();
  }
  if ((button == LOW ) && (button1 == HIGH) && (x == 4))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OK");
    lcd.setCursor(0, 1);
    lcd.print("Displaying P4");
    delay(200);
    button1 = LOW;
    p4();
  }
}
