volatile int light  = 0;
int intrPin = 53;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode (intrPin,INPUT);
  
  attachInterrupt(intrPin, mISR, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(13,light);
}

void mISR() {
  light = digitalRead(13);
  light = !light;
}
