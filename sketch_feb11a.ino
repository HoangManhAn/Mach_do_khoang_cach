#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h> Library

LiquidCrystal_I2C lcd(0x27,16,2); 
const int trigPin = 9;
const int echoPin = 10;
long duration;
float distanceCm;

void setup() {
  
  lcd.init();                    
  lcd.backlight();
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  lcd.setCursor(0, 0); 
  lcd.print("Distance(cm):"); 
  lcd.setCursor(11, 1);
  lcd.print(distanceCm);
  delay(1000);
}
