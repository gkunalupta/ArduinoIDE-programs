/*
 * 
 * All the resources for this project: http://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */
 #include<LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 const int rs = 8, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{lcd.begin(16,2);
lcd.print("hello world");
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("BusA");
lcd.setCursor(6,0);
lcd.print("BusB");
lcd.setCursor(12,0);
lcd.print("BusC");


}
int timerAA()
 {int S = 59; // count seconds 
int M = 5; // count minutes

 S--;
 delay(1000);
  
 if(S<0)
 {
   M--;
   S=59;
 }
 if(M<0)
 {
   M=5;
 }
 if(M>5)
 {
   lcd.setCursor(0,1);
   lcd.print(M);
 }
 else
 {
   lcd.setCursor(0,1);
   lcd.print("0"); 
   lcd.setCursor(1,1);
   lcd.print(M);
   lcd.setCursor(2,1);
   lcd.print(":");
 }
  
  
 if(S>0)
 {
   lcd.setCursor(3,1);
   lcd.print(S);
 }
 else
 {
   lcd.setCursor(3,1);
   lcd.print("0"); 
   lcd.setCursor(4,1);
   lcd.print(S);
   
 }
 return (M--);
 }
void loop() 
{ int i,f,g,h;
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
   // Serial.print(mfrc522.PICC_IsNewCardPresent());
  // Serial.println("hello");
   // delay(1000);
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {  
    //Serial.println(mfrc522.PICC_ReadCardSerial());
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();
  if (content.substring(1) == "D9 93 31 8D")//AAAAred
  {
    Serial.println("bus route A");
   // Serial.println();
    i=1;
    timerAA();
    delay(1000);
  }
    if (content.substring(1) == "39 81 E9 8C")//AAAA
  {
    Serial.println("bus route A");
    Serial.println();
    i=1;
    timerAA();
    delay(3000);
  }  if (content.substring(1) == "59 60 A5 8B")//AAAA
  {
    Serial.println("bus route A");
    Serial.println();
    i=1;
    timerAA();
    delay(3000);
  }  if (content.substring(1) == "39 54 CD 8B")//BBBlue
  {
    Serial.println("bus route B");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "59 45 41 8D")//BBBB
  {
    Serial.println("bus route BBBBB");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "49 90 F2 8C")//BBB
  {
    Serial.println("bus route BBBB");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "6A B8 8D 15")//CCCC
  {
    Serial.println("bus route c");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "DA B3 2B 15")//ccc
  {
    Serial.println("bus route c");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "49 28 F1 8B")//ccc
  {
    Serial.println("bus route c");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "49 64 EE 8B")//ccc
  {
    Serial.println("bus route c");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "5A B8 87 16")//ddd
  {
    Serial.println("bus route d");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "BA 20 39 16")//ddd
  {
    Serial.println("bus route d");
    Serial.println();
    delay(3000);
  }  if (content.substring(1) == "EA 24 77 15")//ddd
  {
    Serial.println("bus route d");
    Serial.println();
    delay(3000);
  }  
  
  while(i=1)
  {
   int min =timerAA();
   if(min==-1)
   i=0;  
  }
  
  }  
