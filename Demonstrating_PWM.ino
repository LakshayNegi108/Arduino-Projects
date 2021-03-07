int d =5;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  analogWrite(10, 20);
  delay(500);
  for(int a = 0; a < 256; a++){
    analogWrite(3, a);
    delay(d);
  }

  for(int a =255; a >= 0; a--){
    analogWrite(3, a);
    delay(d);
  }
  delay(1000); 

}
