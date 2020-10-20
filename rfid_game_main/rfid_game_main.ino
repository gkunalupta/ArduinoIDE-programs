/*
 * 
 * All the resources for this project: https://www.hackster.io/Aritro
 * Modified by Aritro Mukherjee
 * 
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
int m,i,ch,l=0;

void rfidfirstcard()
{   String content= "";                            // string to store decoded code from rfid tag
  for (byte i = 0; i < mfrc522.uid.size; i++) 
     {
      Serial.print(mfrc522.uid.uidByte[i], DEC);
       content.concat(String(mfrc522.uid.uidByte[i], DEC)); 
      }//Serial.println();
  
  //Serial.println("iikl");
 //Serial.println(content.substring(0));
 content.toUpperCase();
 if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 {   // Serial.println("Authorized access");
    m=1;                                               // here we can assign anyvalue to m whtcher numer ,colour or anything to a particular card
  }
  if(content.substring(0)=="214556830")//white with marker
  {  //Serial.println(" Access denied");
  m=2;
  }if(content.substring(0)=="17018679211")//blue
  { //Serial.println("kjk");
  m=3;
  }
  if(content.substring(0)=="")
  m=4;
  if(content.substring(0)=="")
  m=5;
  if(content.substring(0)=="")
  m=6;
  if(content.substring(0)=="")
  m=7;
  if(content.substring(0)=="")
  m=8;
  if(content.substring(0)=="")
  m=9;
}
void rfidsecondcard()
 { String content="";
  

  if (!mfrc522.PICC_IsNewCardPresent())
  return;
  // Serial.println("akhil");
   if ( ! mfrc522.PICC_ReadCardSerial()) 
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
  Serial.print(mfrc522.uid.uidByte[i], DEC);
   content.concat(String(mfrc522.uid.uidByte[i], DEC));
  }//Serial.println();
 //Serial.println("iikl");
 //Serial.println(content.substring(0));
  content.toUpperCase();
  if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 { // Serial.println("Authorized access");
    m=1; 
  }
   if(content.substring(0)=="214556830")
  { //Serial.println(" Access denied");
  m=2;
  } if(content.substring(0)=="17018679211")
  {//Serial.println("kjk");
  m=3;
  }if(content.substring(0)=="")
  m=4;
  if(content.substring(0)=="")
  m=5;
  if(content.substring(0)=="")
  m=6;
  if(content.substring(0)=="")
  m=7;
  if(content.substring(0)=="")
  m=8;
  if(content.substring(0)=="")
  m=9;
 }
 void rfidcolour()
{       boolen x;     
             String content="";
             rfidfirstcard();
            // Serial.println(content.substring(0));
             //Serial.println(m);
             Serial.print(" number on card u placed :");
             i=m;
             Serial.println(i);
             delay(7000);
            // Serial.println("koioklk");   
            rfidsecondcard();
            // Serial.println(m);
             Serial.print("number on second  card u placed :");
             ch=m;
             Serial.println(ch);
            delay(1000);
  
}
void setup() 
{ lcd.begin(16,2);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  lcd.println("Approximate your card to the reader...");
  lcd.println();

}long randnumber;
void loop() 
{ 
  randnumber=random(3,6);//0,19
 // randnumber=5;
  lcd.println(randnumber);
  delay(10000);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
   return;
  if ( ! mfrc522.PICC_ReadCardSerial()) 
   return;

   switch(randnumber)
{ case(3):{  rfidcolour();
            if(i+ch==3)
            lcd.println("You are smart guy");
             break;
          }
  
 case(4): {  rfidcolour();
             if(i+ch==4)
             lcd.println("You are smart guy");
            } break;

case(5):   {    rfidcolour();
                 if(i+ch==5)
                 Serial.println("You are smart guy");
            } break;
 case(1):  {    rfidcolour();
                 if(i+ch==1)
                 lcd.println("You are smart guy");
            } break;         
 case(2):  {    rfidcolour();
                 if(i+ch==2)
                 Serial.println("You are smart guy");
            } break;   
case(6):   {    rfidcolour();
                 if(i+ch==6)
                 Serial.println("You are smart guy");
            } break;
case(7):   {    rfidcolour();
                 if(i+ch==7)
                 Serial.println("You are smart guy");
            } break;
case(8):    {    rfidcolour();
                 if(i+ch==8)
                 Serial.println("You are smart guy");
            } break;
case(9):    {    rfidcolour();
                 if(i+ch==9)
                 Serial.println("You are smart guy");
            } break;
case(10):  {    rfidcolour();
                 if(i+ch==10)
                 Serial.println("You are smart guy");
            } break;
case(11): {    rfidcolour();
                 if(i+ch==11)
                 Serial.println("You are smart guy");
            } break;
case(12):   {    rfidcolour();
                 if(i+ch==12)
                 Serial.println("You are smart guy");
            } break;
case(13):  {    rfidcolour();
                 if(i+ch==13)
                 Serial.println("You are smart guy");
            } break;  
case(14):   {    rfidcolour();
                 if(i+ch==14)
                 Serial.println("You are smart guy");
            } break;
case(15):   {    rfidcolour();
                 if(i+ch==15)
                 Serial.println("You are smart guy");
            } break;
case(16):  {    rfidcolour();
                 if(i+ch==16)
                 Serial.println("You are smart guy");
            } break;
case(17):   {    rfidcolour();
                 if(i+ch==17)
                 Serial.println("You are smart guy");
            } break;
case(18):  {    rfidcolour();
                 if(i+ch==18)
                 Serial.println("You are smart guy");
            } break;


                                                                                                                                                                                  
}
delay(1000);
}
