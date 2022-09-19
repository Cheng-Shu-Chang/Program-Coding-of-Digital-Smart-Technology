void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
bool IRState,preIRState;
int count=0,now,pre=0;
void loop() {
  // put your main code here, to run repeatedly:
  IRState = digitalRead(2);
  
  if(preIRState^IRState){
    now = millis();
    count+=1;
    digitalWrite(13,IRState);
    Serial.print("Time: ");
    Serial.print(millis());
    Serial.print("(ms)\t");
    Serial.print("Velocity: ");
    Serial.print(0.500/(now-pre)*1000);
    Serial.print("(cm/s)\t");
    Serial.print("State: ");
    Serial.print(IRState);
    Serial.print("\tCount: ");
    Serial.print(count);
    Serial.print("\n");
  }
  pre = now;
  preIRState = IRState;
}
