#define DATA 6
#define LATCH 8
#define CLOCK 10

byte smile[] = {B00000000, B11111111, B11011011, B00011000, B01111110,
B10011001, B01000010, B00100100};
int binary[] = {1, 2, 4, 8, 16, 32, 64, 128};

void setup(){
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop(){
  int a,hold,shift;
  for(shift=0;shift<9;shift++){
    for(hold=0;hold<25;hold++){
      for(a=0;a<8;a++){
        digitalWrite(LATCH, LOW);
        shiftOut(DATA,CLOCK,LSBFIRST,~smile[a]>>shift);
        shiftOut(DATA,CLOCK,MSBFIRST,binary[a]);
        digitalWrite(LATCH,HIGH);
        delay(1);
      }
    }
  }
}
