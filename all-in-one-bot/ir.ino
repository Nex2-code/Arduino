void ir()
{
    while (true)
    {
    if((digitalRead(i)==HIGH)&&(digitalRead(i1)==HIGH))
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);      
    }
    if((digitalRead(i)==HIGH)&&(digitalRead(i1)==LOW))
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);      
    }
    if((digitalRead(i)==LOW)&&(digitalRead(i1)==HIGH))
    {
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);      
    }
    if((digitalRead(i)==LOW)&&(digitalRead(i1)==LOW))
    {
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);      
    }
}}
