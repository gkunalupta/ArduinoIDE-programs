#include<LiquidCrystal.h>
String words;
LiquidCrystal lcd(12,11,5,4,3,2);//rs enable d4 d5 d6 d7
int trigPin = 9;    // Trigger
int echoPin = 10;    // Echo
long duration, cm, inches;
void setup() 
{
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    
    lcd.print("/////////security system//////////");
   // delay(2000);
   lcd.clear();
  // put your setup code here, to run once:

}

void loop() 
{ lcd.setCursor(0,0);
lcd.print("No one in the sensing range"); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
 Serial.println(cm);
 if(cm<10)
 {
    lcd.clear();
    lcd.print(" object is detected");
    lcd.print(" range of object is: ");
    lcd.println(cm);
  }else
   { 
    lcd.clear();
    lcd.print(" no object is detected");
   }

}
