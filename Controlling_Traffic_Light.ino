#define U_Button 13
#define N_Button 7
#define U_Red 12
#define U_Yellow 11
#define U_Green 10
#define N_Red 2
#define N_Yellow 1
#define N_Green 0

#define yellowBlinkTime 250
boolean N_Traffic = false; // Upar = false Niche = true
int flowtime = 5000;  //amt of time to let traffic flow
int changeDelay = 1000; // amt of time between colour change

void setup(){
  pinMode(U_Button, INPUT);
  pinMode(N_Button, INPUT);
  pinMode(U_Red, OUTPUT);
  pinMode(U_Yellow, OUTPUT);
  pinMode(U_Green,OUTPUT);
  pinMode(N_Red,OUTPUT);
  pinMode(N_Yellow, OUTPUT);
  pinMode(N_Green, OUTPUT);

  //Initial condition of lights
  digitalWrite(U_Red, LOW);
  digitalWrite(U_Yellow, LOW);
  digitalWrite(U_Green, HIGH);
  digitalWrite(N_Red, LOW);
  digitalWrite(N_Yellow, LOW);
  digitalWrite(N_Green, HIGH);
  }
void loop(){
  if(digitalRead(N_Traffic == HIGH)){
    if(N_Traffic != true){
      N_Traffic = true;
      delay(flowtime);
      digitalWrite(U_Green, LOW);
      digitalWrite(U_Yellow, HIGH);
      delay(changeDelay);
      digitalWrite(U_Yellow,LOW);
      digitalWrite(U_Red, HIGH);
      delay(changeDelay);
      for(int a =0; a < 5; a++){
        digitalWrite(N_Yellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(N_Yellow, HIGH);
        delay(yellowBlinkTime);
      }
      digitalWrite(N_Red, LOW);
      digitalWrite(N_Yellow, LOW);
      digitalWrite(N_Green, HIGH);
    }
  }

  if(digitalRead(U_Button == HIGH)){
    if(N_Traffic == true){
      N_Traffic = false;
      delay(flowtime);
      digitalWrite(N_Green, LOW);
      digitalWrite(N_Yellow, HIGH);
      delay(changeDelay);
      digitalWrite(N_Yellow, LOW);
      digitalWrite(N_Red, HIGH);
      delay(changeDelay); 
      for(int a=0;a < 5;a++){
        digitalWrite(U_Yellow,LOW);
        delay(yellowBlinkTime);
        digitalWrite(U_Yellow, HIGH);
        delay(yellowBlinkTime);
      }
      digitalWrite(U_Red, LOW);
      digitalWrite(U_Yellow, LOW);
      digitalWrite(U_Green, HIGH);
    }
  }
 }
  
