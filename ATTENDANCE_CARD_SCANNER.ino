#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 7  // Buzzer is now on pin 7

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Your specific UID
byte authorizedUID[] = {0x73, 0x15, 0x21, 0x06}; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();
  
  pinMode(BUZZER_PIN, OUTPUT); // Buzzer on pin 7
  pinMode(4, OUTPUT);          // Green LED
  pinMode(5, OUTPUT);          // Red LED
  
  lcd.setCursor(0, 0);
  lcd.print("Attendance Sys");
  lcd.setCursor(0, 1);
  lcd.print("Scan your card");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  bool match = true;
  for (byte i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != authorizedUID[i]) {
      match = false;
      break;
    }
  }

  lcd.clear();
  if (match) {
    lcd.print("Welcome Gyebi!");
    digitalWrite(4, HIGH);        // Green LED ON
    tone(BUZZER_PIN, 2000, 500);  // Buzzer on pin 7
    delay(2000);
    digitalWrite(4, LOW);         // Green LED OFF
  } else {
    lcd.print("Access Denied");
    digitalWrite(5, HIGH);        // Red LED ON
    tone(BUZZER_PIN, 200, 1000);  // Buzzer on pin 7
    delay(2000);
    digitalWrite(5, LOW);         // Red LED OFF
  }
  
  lcd.clear();
  lcd.print("Attendance Sys");
  lcd.setCursor(0, 1);
  lcd.print("Scan your card");
  
  mfrc522.PICC_HaltA();
}