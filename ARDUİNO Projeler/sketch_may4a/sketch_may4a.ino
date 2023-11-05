int red = 8;
int yellow = 9;
int green = 10;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
 digitalWrite(red, HIGH);
 digitalWrite(yellow, LOW);
 digitalWrite(green, LOW);
 delay(10000);

 digitalWrite(red, LOW);
 digitalWrite(yellow, HIGH);
 digitalWrite(green, LOW);
 delay(1000);

 digitalWrite(red, LOW);
 digitalWrite(yellow, LOW);
 digitalWrite(green, HIGH);
 delay(10000);
 
 digitalWrite(red, LOW);
 digitalWrite(yellow, HIGH);
 digitalWrite(green, LOW);
 delay(1000);
}
