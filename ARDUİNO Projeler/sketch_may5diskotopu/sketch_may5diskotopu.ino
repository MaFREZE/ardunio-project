int red = 9;
int green = 10;
int blue = 11;
int bekleme = 1000;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
/*
  analogWrite(red, 255); // 9 numaralı pvm pini 255 değerine eşitledik
  analogWrite(green, 255);// 10 numaralı pvm pini 255 değerine eşitledik
  analogWrite(blue, 255);// 11 numaralı pvm pini 255 değerine eşitledik
  delay(bekleme);
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 0);
  delay(bekleme);
    analogWrite(red, 255); 
  analogWrite(green, 0);
  analogWrite(blue, 255);
  delay(bekleme);
    analogWrite(red, 0); 
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(bekleme);
  */
    analogWrite(red, random(0,255)); 
  analogWrite(green, random(0,255));
  analogWrite(blue, random(0,255));
  delay(bekleme);

}
