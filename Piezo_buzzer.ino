#define piezo 3
int del = 500;
void setup() {
    pinMode(piezo, OUTPUT);

}

void loop() {
  analogWrite(piezo, 256);
  delay(del);
  analogWrite(piezo, LOW);
  delay(del);

}
