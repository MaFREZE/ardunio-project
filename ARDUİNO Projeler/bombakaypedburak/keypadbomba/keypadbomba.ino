
#include <LiquidCrystal_I2C_AvrI2C.h>

#include <Keypad.h>
#include "buzzerSong.h"
#define buzzer 11

LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);
long patlamaSaniye;
String sifre = "7355608";
String girilenSifre = "";
const byte SatirSayisi = 4; // Satır sayısını gösteren sabiti tanımla
const byte SutunSayisi = 4; // Sütun sayısını gösteren sabiti tanımla
// Tuşları gösteren karakter matrisini tanımla

float kalan_sure_onceki = 0;
char keys[SatirSayisi][SutunSayisi] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte SatirPinleri[SatirSayisi] = {9, 8, 7, 6}; // Sırasıyla keypad satır pinlerinin bağlandığı Arduino pinleri
byte SutunPinleri[SutunSayisi] = {5, 4, 3, 2};    // Sırasıyla keypad sütun pinlerinin bağlandığı Arduino pinleri
// keypad1 adında bir keypad nesnesi tanımla

Keypad keypad1 = Keypad(makeKeymap(keys), SatirPinleri, SutunPinleri, SatirSayisi, SutunSayisi);
bool bombakuruldu = false;
void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin();
}

void loop()
{
 
  lcd.home();
  lcd.print("Sifre:");
  if (not bombakuruldu) {
    lcd.setCursor(0, 1);

  } else {
    float kalan_sure = patlamaSaniye / 1000.0;
    if (String(kalan_sure).length() < String(kalan_sure_onceki).length()) {
      lcd.clear();
      lcd.home();
      lcd.print("Sifre: ");
    }
    lcd.setCursor(0, 1);
    lcd.print("Sure: ");

  }







  char key = keypad1.getKey();


  if (key != NO_KEY) {
    girilenSifre += key;

    lcd.setCursor(7, 0);
    lcd.print(girilenSifre);

    if (not bombakuruldu) {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
    }

  }

  if (girilenSifre.length() == sifre.length()) {
    if (girilenSifre == sifre) {
      if (not bombakuruldu) {
        patlamaSaniye = millis() + 45000;
        bombakuruldu = true;
        Serial.println("bomba kuruldu");
      } else {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        bombakuruldu = false;
      }
      girilenSifre = "";
    } else {
      lcd.clear();
      lcd.home();
      lcd.print("hatali sifre");
      girilenSifre = "";
      digitalWrite(buzzer, HIGH);
      delay(1000);
      lcd.clear();
      digitalWrite(buzzer, LOW);
    }
  }
  if (bombakuruldu) {

    lcd.setCursor(0, 1);
    lcd.print("Sure: ");
    lcd.setCursor(6, 1);
    lcd.print(kalan_sure_onceki);
    long kalan_sure = patlamaSaniye - millis();
    Serial.println(girilenSifre);
    if (kalan_sure > 30000) {

      if (millis() % 1800 < 900) {
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
      }
    }  else if (kalan_sure <= 30000 and kalan_sure > 15000) {

      if (millis() % 1200 < 600) {
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
      }
    }
    else if (kalan_sure <= 15000 and kalan_sure > 3000) {

      if (millis() % 300 < 150) {
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
      }
    }
    else if (kalan_sure <= 3000 and kalan_sure > 0) {

      if (millis() % 100 < 50) {
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
      }
    } else if (kalan_sure < 0) {
      muzikcal();
      girilenSifre = "";
      bombakuruldu = false;


    }
  }
}
