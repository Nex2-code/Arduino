void p4()
{
  while (true)
  {
    digitalWrite(25, HIGH);
    delay(500);
    digitalWrite(24, HIGH);
    delay(500);
    digitalWrite(23, HIGH);
    delay(500);
    digitalWrite(22, HIGH);
    delay(1000);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(24, LOW);
    digitalWrite(25, LOW);
    delay(1000);
  }
}
