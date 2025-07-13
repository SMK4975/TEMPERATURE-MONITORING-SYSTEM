#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp Monitor");
  delay(1000);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(sensorPin);
  float voltage = analogValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C   ");

  delay(1000);
}
