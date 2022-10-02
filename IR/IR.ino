void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Time(ms)\t");
  Serial.print("Velocity(cm/s)\t");
  //Serial.print("State\t");
  //Serial.print("Count\t");
  Serial.print("\n");
  delay(1000);
}
float spacing = 12.7/27;
bool IRState,preIRState;
int count=0,now,past=0;
void loop() {
  // put your main code here, to run repeatedly:
  IRState = digitalRead(2);
  
  if(preIRState-IRState){
    now = millis();
    count+=1;
    digitalWrite(13,IRState);
    Serial.print(millis());
    Serial.print("\t\t");
    Serial.print(spacing/(now-past)*1000);
    //Serial.print("\t");
    //Serial.print(IRState);
    //Serial.print("\t");
    //Serial.print(count);
    Serial.print("\n");
  }
  past = now;
  preIRState = IRState;
}
