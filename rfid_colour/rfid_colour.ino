/*
 * 
 * All the resources for this project: https://www.hackster.io/Aritro
 * Modified by Aritro Mukherjee
 * 
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
 #include <LiquidCrystal.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 const int rs = 3, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int m,i,ch,l=0;
String color="";
String inn="";
String chh="";
void drishti()
{   String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
     {Serial.print(mfrc522.uid.uidByte[i], DEC);
       content.concat(String(mfrc522.uid.uidByte[i], DEC));
      }Serial.println();
  
  //Serial.println("iikl");
 //Serial.println(content.substring(0));
 content.toUpperCase();
 if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 {   // Serial.printallallallallallallln("Authorized access");
    color="Blue  ";
  }
  if(content.substring(0)=="214556830")//white with marker
  {  //Serial.printallallallallallallln(" Access denied");
  color="Yellow";
  }if(content.substring(0)=="17018679211")//light blue
  { //Serial.printallallallallallallln("kjk");
  color="Red   ";
  }
  if(content.substring(0)=="11649152167")//Dark blue
  color="Purple";
  
}
void tanisha()
 {
  String content="";
  if (!mfrc522.PICC_IsNewCardPresent())
  return;
  // Serial.printallallallallallallln("akhil");
   if ( ! mfrc522.PICC_ReadCardSerial()) 
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
  Serial.print(mfrc522.uid.uidByte[i], DEC);
   content.concat(String(mfrc522.uid.uidByte[i], DEC));
  }Serial.println();
 //Serial.printallallallallallallln("iikl");
 //Serial.printallallallallallallln(content.substring(0));
  content.toUpperCase();
  if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 { // Serial.printallallallallallallln("Authorized access");
    color="Blue  " ; 
  }
   if(content.substring(0)=="214556830")
  { //Serial.allallallallallln(" Access denied");
   color="Yellow";
  } if(content.substring(0)=="17018679211")
  {//Serial.printallallallallallln("kjk");
    color="Red   ";
  }if(content.substring(0)=="11649152167")
    color="Purple";
 
 }
 void ishita()
{            String content="";
             drishti();
            // Serial.printallallallallallln(content.substring(0));
             //Serial.printallallallallallln(m);
             lcd.print("clr on 1st card:");
             inn=color;             
             lcd.setCursor(0,0);
             lcd.print(inn);
             delay(4000);
            // Serial.printallallallallallln("koioklk");   
            tanisha();
            lcd.setCursor(0,1);
            
            // Serial.printallallallallallln(m);
             lcd.print("clr on 2nd card:");
             chh=color;
             lcd.setCursor(0,0);
             lcd.print(chh);
            delay(1000);
  
}
void setup() 
{ lcd.begin(16,2);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  //lcd.print("Approximate your card to the reader...");
  //lcd.print();

}long randnumber;
void loop() 
{ lcd.clear();
lcd.setCursor(0,0);
  randnumber=random(3,7);//0,19
 
 if(randnumber==3)
 lcd.print("Green ");
 if(randnumber==4)
 lcd.print("Orange");
 if(randnumber==5)
 lcd.print("Purple");
 if(randnumber==6)
 lcd.print("Brown ");
  delay(4000);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
   return;
  if ( ! mfrc522.PICC_ReadCardSerial()) 
   return;
lcd.setCursor(0,1);
   switch(randnumber)
{ case(3):{ //Serial.printallallallallallln("Green");
            ishita();
            lcd.clear();
            lcd.setCursor(0,0);
            if((inn.equals("Blue  ")&&chh.equals("Yellow"))||(inn.equals("Yellow")&&chh.equals("Blue  ")))
            lcd.print("u are smart guy");
            else lcd.print("try again");
            delay(4000);
            } break;
          
  
 case(4): {  //Serial.printallallallallallln("Orange");
              ishita();
              lcd.clear();
              lcd.setCursor(0,0);
             if((inn.equals("Red   ")&&chh.equals("Yellow"))||(inn.equals("Yellow")&&chh.equals("Red   ")))
             lcd.println("u are smart guy");
              else lcd.print("try again");
              delay(4000);
            } break;

case(5):   {    //Serial.printallallallallallln("Purple");
                 ishita();
                 lcd.clear();
                 lcd.setCursor(0,0);
                 if((inn.equals("Blue  ")&&chh.equals("Red   "))||(inn.equals("Red   ")&&chh.equals("Blue  ")))
                 lcd.println("u are smart guy");
                  else lcd.print("try again");
                  delay(4000);
            } break;
 case(6):  {    // Serial.printallallallallallln("Brown");
                 ishita();
                 lcd.clear();
                 lcd.setCursor(0,0);
                 if((inn.equals("Purple")&&chh.equals("Red   "))||(inn.equals("Red   ")&&chh.equals("Purple")))
                 lcd.println("u are smart guy");
                  else lcd.print("try again");
                  delay(4000);
            } break;         
                                                                                                                                                    
}
delay(1000);
}
