#include <SPI.h>
#include <RFID.h>
#include "buzzerSong.h"
#define buzzer 13

RFID rfid(10, 9);

int sifre[5] = {
  51, 67, 254, 6, 136
};
int sifre2[5] = {
  51, 109, 226, 18,174
};



void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  pinMode(buzzer,OUTPUT);
}

void loop() {

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      Serial.print("Kart ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(" ");
      Serial.print(rfid.serNum[1]);
      Serial.print(" ");
      Serial.print(rfid.serNum[2]);
      Serial.print(" ");
      Serial.print(rfid.serNum[3]);
      Serial.print(" ");
      Serial.println(rfid.serNum[4]);

      if (rfid.serNum[0] == sifre[0] and rfid.serNum[1] == sifre[1] and rfid.serNum[2] == sifre[2] and rfid.serNum[3] == sifre[3] and rfid.serNum[4] == sifre[4]) {
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);

      } else {
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);
      }
            if (rfid.serNum[0] == sifre2[0] and rfid.serNum[1] == sifre2[1] and rfid.serNum[2] == sifre2[2] and rfid.serNum[3] == sifre2[3] and rfid.serNum[4] == sifre2[4]) {
            muzikcal();     
      } 
    }
    rfid.halt();
  }
}
