#include<LiquidCrystal.h>
const int rs = 8, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() 
{
  lcd.begin(16,2);
lcd.print("hello world");
  Serial.begin(9600);   // Initiate a serial communication
lcd.clear();
lcd.setCursor(0,0);
lcd.print("BusA");
lcd.setCursor(6,0);
lcd.print("BusB");
lcd.setCursor(12,0);
lcd.print("BusC");
}
int timer(int x,int r,int r1,int r2,int r3,int r4)
 { 
int S = 59; // count seconds 
int M = x; // count minutes

 S--;
 delay(1000);
  
 if(S<0)
 {
   M--;
   S=59;
 }
 if(M<0)
 {
   M=x;
 }
 if(M>5)
 {
   lcd.setCursor(r,1);
   lcd.print(M);
 }
 else
 {
   lcd.setCursor(r,1);
   lcd.print("0"); 
   lcd.setCursor(r1,1);
   lcd.print(M);
   lcd.setCursor(r2,1);
   lcd.print(":");
 }
  
 if(S>0)
 {
   lcd.setCursor(r3,1);
   lcd.print(S);
 }
 else
 {
   lcd.setCursor(r3,1);
   lcd.print("0"); 
   lcd.setCursor(r4,1);
   lcd.print(S);
   
 }
}
void loop()
{
  Serial.println("lcd timer");
  timer(5,0,1,2,3,4);
}
