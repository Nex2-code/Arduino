int PulseSensorPin = A0;
int LED = D5;  //
int Signal;
int Threshold = 550;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
// The Main Loop Function
void loop() {
  Signal = analogRead(PulseSensorPin);
  Serial.println(Signal);
  if (Signal > Threshold) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  delay(10);
}
