#define DPIN 4
#define APIN A0
#define LED 2
int iMeas = 0;
int iFadePoint =5;
bool bSetValue = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DPIN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  iMeas=analogRead(APIN);
  bSetValue=digitalRead(DPIN);
  Serial.println("Analog : "+String((int)iMeas)+", Set max value : "+String((int)bSetValue));
  digitalWrite(LED,bSetValue);
  delay(1000);
}
