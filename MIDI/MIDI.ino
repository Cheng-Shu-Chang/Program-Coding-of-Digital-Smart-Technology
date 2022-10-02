void sing(String song, String beat);

void setup() {
  // put your setup code here, to run once:
  for(int i = 0;i<10;i++){
    pinMode(i+2,INPUT);
  }
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

int pinch[7] = {60,62,64,65,67,69,71};
String song = "671.71.3.736561.534341.31.74#4#77671.71.3.7336561.5341.71.2.3.1.1.7676b6";
String beat = "11312262312262311362312261131226113122622132215112226";

void loop() {
  float N  = 1;
  int note = -1;
  if(digitalRead(2)==HIGH){
    sing(song,beat);
  }
  if(digitalRead(12)==HIGH){
      N=2;
  }else if(digitalRead(10)==HIGH){
      N=0.5;
  }
  for(int i = 9;i>=3;i--){
    if(digitalRead(i)==HIGH){
      note = 9-i;
    }
  }
  if(note==-1){
      noTone(11);
  }else{
      tone(11,440*pow(2,(pinch[note]-69)/12.0)*N,110);
  }
  Serial.print(note);
  Serial.print("\t");
  Serial.println(440*pow(2,(pinch[note]-69)/12.0)* N);
  delay(100);
}

void sing(String song, String beat){
  int buzzer = 11;
  float oneBeat = 60000/87;
  int j = 0;
  delay(100);
  Serial.print('\n');
  //Serial.print(beat.length());
  Serial.print('\n');
  String note = "";
  for(int i=0;i<song.length();i++){
    if(song[i+1]=='.' || song[i+1]=='#'|| song[i+1]=='b'){
      note = song.substring(i,i+2);
      i++;
    }else{
      note = song.substring(i,i+1);
    }
    
    int p=0;
    if(note=="1"){
      p = 60;
    }else if(note=="2"){
      p = 62;
    }else if(note=="3"){
      p = 64;
    }else if(note=="4"){
      p = 65;
    }else if(note=="4#"){
      p = 66;
    }else if(note=="5"){
      p = 67;
    }else if(note=="6b"){
      p = 68;
    }else if(note=="6"){
      p = 69;
    }else if(note=="7"){
      p = 71;
    }else if(note=="1."){
      p = 72;
    }else if(note=="2."){
      p = 74;
    }else if(note=="3."){
      p = 76;
    }

    
    float duration;
    duration = oneBeat/2*(beat[j]-'0');
    /*
    Serial.print(i);
    Serial.print(" ");
    Serial.print(note);
    Serial.print(" ");
    Serial.print(j);
    Serial.print(" ");
    Serial.print(duration);
    Serial.print("\n");
    */
    tone(buzzer, int(pow(2,(p-69)/12.0)*440), long(duration*0.9));
    delay(duration);
    
    j++;
  }
  noTone(buzzer);
  delay(1000);
}
