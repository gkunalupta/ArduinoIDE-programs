#include <LiquidCrystal.h> 
 
int S = 59; // count seconds 
int M = 05; // count minutes

//initialize the library with the numbers of the interface pins
 const int rs = 8, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
 lcd.begin(16,2);//set up the LCD's number of columns and rows
}
void loop()
{
 lcd.setCursor(1,1); 
 lcd.print(":");
 lcd.setCursor(6,1);
 lcd.print(":");
 lcd.setCursor(12,1);
 lcd.print(":");
 
 S--;
 delay(1000);
  
 if(S<0)
 {
   M--;
   S=59;
 }
 if(M<0)
 {
   M=05;
 }
 if(M>5)
 {
   lcd.setCursor(7,1);
   lcd.print(M);
 }
 else
 {
   lcd.setCursor(7,1);
   lcd.print("0"); 
   lcd.setCursor(8,1);
   lcd.print(M);
   lcd.setCursor(9,1);
   lcd.print(":");
 }
  
 if(S>0)
 {
   lcd.setCursor(10,1);
   lcd.print(S);
 }
 else
 {
   lcd.setCursor(10,1);
   lcd.print("0"); 
   lcd.setCursor(11,1);
   lcd.print(S);
   lcd.setCursor(12,1);
   lcd.print(" ");
 }
  
}
