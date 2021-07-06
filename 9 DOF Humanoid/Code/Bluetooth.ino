void read_serial(){
  if(bluetooth.available()){
    serial_updated = true;
    
    data = bluetooth.readStringUntil('\n');
    Serial.print("Received : "); Serial.println(data);

    if(data == "lock\r")
      bluetooth.println("-> Locking!\n");
    else if(data == "forward\r")
      bluetooth.println("-> Going forward!\n");
    else if(data == "back\r")
      bluetooth.println("-> Going back!\n");
    else if(data == "left\r")
      bluetooth.println("-> Going left!\n");
    else if(data == "right\r")
      bluetooth.println("-> Going right!\n");
    else if(data == "namaste\r")
      bluetooth.println("-> Doing Namaste!\n");
    else if(data == "gym\r")
      bluetooth.println("-> Gymming!\n");
    else if(data == "no\r")
      bluetooth.println("-> Saying no!\n");
  }
  else
    serial_updated = false;

  if(Serial.available()){
    bluetooth.println(Serial.readStringUntil('\n'));
  }
}
