int light  = 0;
int inPin = 25;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode (inPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  
  //light = digitalRead(inPin);
  light = REG_PIOD_PDSR & 0x1;
  
  digitalWrite(13,light);
}
