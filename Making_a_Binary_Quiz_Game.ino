#define DATA 6
#define LATCH 8
#define CLOCK 10

int number = 0;
int answer = 0;
void setup() {
 pinMode(DATA ,OUTPUT);
 pinMode(LATCH ,OUTPUT);
 pinMode(CLOCK ,OUTPUT);
 Serial.begin(9600);
 randomSeed(analogRead(3));
 display_Number(0);
}
  void display_Number(byte a){
    digitalWrite(LATCH ,LOW);
    shiftOut(DATA,CLOCK,MSBFIRST,a);
    digitalWrite(LATCH, HIGH);
  }
  void get_Answer(){
    int z = 0;
    Serial.flush();
    while(Serial.available() == 0){
    
    }
    while(Serial.available() > 0){
      answer = answer*10;
       z = Serial.read() - '0';
      answer = answer + z;
      delay(500);
    }
    Serial.print("You entered: ");
    Serial.println(answer);
    }
    void check_Answer(){
      if(answer == number){
        Serial.print("Correct!");
        Serial.print(answer,BIN);
        Serial.print(" equals ");
        Serial.println(number);
        }
      else{
        Serial.print("Incorrect!");
        Serial.print(answer,BIN);
        Serial.print(" equals ");
        Serial.println(number);
      }
      answer = 0;
      delay(10000);
    }
void loop() {
  number = random(256);
  display_Number(number);
  Serial.println("What is the binary number in base-10? ");
  get_Answer();
  check_Answer();

}
