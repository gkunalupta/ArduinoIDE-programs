#include <LiquidCrystal.h>

const int rs = 21, en = 20, d4 = 16, d5 = 17, d6 = 18, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tk1=2,tk2=3,ts11=4,ts12=5,ts21=6,ts22=7,r11=11,r12=10,r21=9,r22=8;
void setup() 
{
 Serial.begin(9600);
 lcd.begin(16,2);
//lcd.print("hello");
pinMode(tk1,INPUT);
pinMode(tk2,INPUT);
pinMode(ts11,INPUT);
pinMode(ts12,INPUT);
pinMode(ts21,INPUT);
pinMode(ts22,INPUT);
pinMode(r11,OUTPUT);
pinMode(r12,OUTPUT);
pinMode(r21,OUTPUT);
pinMode(r22,OUTPUT);
}int point=0, score=0;

void loop() 
{ lcd.setCursor(0,0);
  lcd.print("PL1-");
  lcd.setCursor(0,1);
  lcd.print("PL2-");
  while(digitalRead(tk1)==1)
 {      Serial.println(digitalRead(ts11));
        Serial.println(digitalRead(ts12));
    if(digitalRead(ts11)==1)
      {
       digitalWrite(r11,1);
       Serial.println("r11");
       point=point+1;
       lcd.setCursor(4,0);
       lcd.print(point);
       delay(10000);
       } else digitalWrite(r11,0);
      if(digitalRead(ts12)==1) 
      {
        digitalWrite(r12,1);
       Serial.println("r12");
       point=point+1;
       lcd.setCursor(4,0);
       lcd.print(point);
       delay(10000);
       }else digitalWrite(r12,0);
 }     
   while(digitalRead(tk2)==1)
 {     Serial.println(digitalRead(ts21));
        Serial.println(digitalRead(ts22));
        if(digitalRead(ts21)==1)
     { 
      Serial.println("r21111");
      digitalWrite(r21,1);
       Serial.println("r21");
       score=score+1;
       lcd.setCursor(4,1);
       lcd.print(score);
       delay(10000);
      }else digitalWrite(r21,0);
      if(digitalRead(ts22)==1)
       {
       digitalWrite(r22,1);
      
       Serial.println("r22");
       Serial.println(digitalRead(r22));
       score=score+1;
       lcd.setCursor(4,1);
       lcd.print(score);
       delay(10000);
       } else digitalWrite(r22,0);
 
 }
}
