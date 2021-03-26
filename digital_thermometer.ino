// Project 20 - Creating a Digital Thermometer
#define DATA 6 // connect to pin 14 on the 74HC595
#define LATCH 8 // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595
int temp = 0;
float voltage = 0;
float celsius = 0;
float sensor = 0;
int digits[]={
 252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};
void setup()
{
 pinMode(LATCH, OUTPUT);
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, OUTPUT);
}
void displayNumber(int n)
{
 int left, right = 0;
 if (n < 10)
 {
 digitalWrite(LATCH, LOW);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[n]);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[0]);
 digitalWrite(LATCH, HIGH);
 }
 if (n >= 10)
 {
 right = n % 10;
 left = n / 10;
 digitalWrite(LATCH, LOW);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[right]);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[left]);
 digitalWrite(LATCH, HIGH);
 }
}
void loop()
{
 sensor = analogRead(0);
 voltage = (sensor * 5000) / 1024; // convert raw sensor value to millivolts
 voltage = voltage - 500; // remove voltage offset
 celsius = voltage / 10; // convert millivolts to Celsius
 temp = int(celsius); // change the floating point temperature to an int
 displayNumber(temp);
 delay(500);
} 


/* // Project 19 - Controlling Two Seven-Segment LED Display Modules
// set up the array with the segments for 0 to 9, A to F (from Table 6-2)
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156,
122, 158, 142};

void setup()
{
 pinMode(LATCH, OUTPUT);
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, OUTPUT);
}



void displayNumber(int n)
{
 int left, right=0;
if (n < 10)
 {
 digitalWrite(LATCH, LOW);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[n]);
 shiftOut(DATA, CLOCK, LSBFIRST, 0);
 digitalWrite(LATCH, HIGH);
 }
 else if (n >= 10)
 {
 right = n % 10; // remainder of dividing the number to display by 10
 left = n / 10; // quotient of dividing the number to display by 10
 digitalWrite(LATCH, LOW);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[right]);
 shiftOut(DATA, CLOCK, LSBFIRST, digits[left]);
 digitalWrite(LATCH, HIGH);
 }
}


void loop()
{
 int i;
 for ( i = 0 ; i < 100 ; i++ )
 {
 displayNumber(i);
 delay(100);
 }
} */
