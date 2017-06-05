int ledPin = 2; //internal led
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("START");
}

void loop() {
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  Serial.println("Internal LED ON");
  delay(1000); // wait for a second
  digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
  Serial.println("Internal LED OFF");
  delay(1000); // wait for a second
}
