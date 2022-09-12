#include<string.h>
#include<math.h>

int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

char song[] = "671.71.3.736561.534341.31.74#4#77";
char beat[] = "884.8442.44.8442.44.884.2.44.842.";
unsigned int oneBar = 60000/40*4;

void loop() {
  // put your main code here, to run repeatedly:
  int j = 0;
  for(int i=0;i<strlen(song);i++){
    char note[3]={0};
    if(song[i+1]=='.' || song[i+1]=='#'){
      note[0]=song[i];
      note[1]=song[i+1];
      i++;
    }else{
      note[0]=song[i]; 
    }
    
    int p=0;
    if(strcmp(note,"1")==0){
      p = 60;
    }else if(strcmp(note,"2")==0){
      p = 62;
    }else if(strcmp(note,"3")==0){
      p = 64;
    }else if(strcmp(note,"4")==0){
      p = 65;
    }else if(strcmp(note,"4#")==0){
      p = 66;
    }else if(strcmp(note,"5")==0){
      p = 67;
    }else if(strcmp(note,"6")==0){
      p = 69;
    }else if(strcmp(note,"7")==0){
      p = 71;
    }else if(strcmp(note,"1.")==0){
      p = 72;
    }else if(strcmp(note,"2.")==0){
      p = 74;
    }else if(strcmp(note,"3.")==0){
      p = 76;
    }
  
    float duration;
    if(beat[j+1]=='.'){
      duration = 1./int(beat[j]-'0')+1./2/int(beat[j]-'0');
      duration *= oneBar;
      j++;
    }else{
      duration = 1./int(beat[j]-'0');
      duration *= oneBar;
    }
    
    tone(buzzer, int(pow(2,(p-69)/12.0)*440), int(duration));
    delay(oneBar/4*0.2);
    j++;
  }
}
