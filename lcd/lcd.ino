#include<LiquidCrystal.h>
String words;

const int rs = 9, en = 10, d0 = 0, d1 = 1, d2 = 2, d3 = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(9, 10, d0, d1, d2, d3, d4, d5, d6, d7);

void setup()
{
    //Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Initialising.");
    delay(1000);
    lcd.clear();
    lcd.print("Initialising..");
    delay(1000);
    lcd.clear();
    lcd.print("Initialising...");
    delay(1000);
    lcd.clear();
    lcd.print("Maker : Techduino");
    delay(2000);
}
void loop()
{
    lcd.clear();
    Serial.print("Enter the line : ");
    while (Serial.available()==0) {
    }
    words = Serial.readString();
    Serial.println(words);
    lcd.setCursor(0,0);
    lcd.print(words);
    delay(5000);
    Serial.println(" ");
}
