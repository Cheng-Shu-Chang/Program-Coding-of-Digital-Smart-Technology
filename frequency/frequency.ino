void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int voltage,_switch;

void loop() {
  // put your main code here, to run repeatedly:
  _switch = digitalRead(2);
  if(_switch==1){
    voltage = analogRead(A0);
    tone(11, voltage/1023.*(523-261)+261);
  }else{
    noTone(11);
  }
  delay(10);
}
