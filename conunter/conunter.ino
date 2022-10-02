void sing(String, String);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.print("Current Number\tCounter\n");
}

int lower = 0, upper = 100, count, _max = 150, preSwitch=0, _switch,voltage;
String song = "671.71.3.736561.534341.31.74#4#77671.71.3.7336561.5341.71.2.3.1.1.7676b6";
String beat = "11312262312262311362312261131226113122622132215112226";

void loop() {
  _switch = digitalRead(2);
  // put your main code here, to run repeatedly:
  if((preSwitch != _switch) && (preSwitch==0)){
    voltage = analogRead(A0);
    count += (int) ((voltage)/1023.0*(upper-lower)+lower);
    Serial.print((int) ((voltage)/1023.0*(upper-lower)+lower));
    Serial.print("\t\t");
    Serial.print(count);
    Serial.print("\n");
  }
  if(count>=_max){
    sing(song,beat);
    count %= _max;
  }
  preSwitch = _switch;
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
