#include "SPI.h" 
#include "MFRC522.h" 
const int pinRST = 9;
const int pinSDA = 10;
MFRC522 mfrc522(pinSDA, pinRST); 
String content="";
int m;
void surbhi()
{ if (mfrc522.PICC_IsNewCardPresent())
 if(mfrc522.PICC_ReadCardSerial())
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
   //Serial.print(mfrc522.uid.uidByte[i], DEC);// print id as hex values
   content.concat(String(mfrc522.uid.uidByte[i],DEC));
} delay(2000);
       if(content.substring(0)=="1179884197")
    {   m=0;Serial.println(content.substring(0));}
       if(content.substring(0)=="214556830")
      { m=5;Serial.println(content.substring(0));}
       if(content.substring(0)=="17018679211")
      { m=1;Serial.println(content.substring(0));}
       if(content.substring(0)=="")
       m=2;
       if(content.substring(0)=="")
       m=3;
       if(content.substring(0)=="")
       m=4;
       if(content.substring(0)=="")
       m=6;
       if(content.substring(0)=="")
       m=7;
       if(content.substring(0)=="")
       m=8;
       if(content.substring(0)=="")
       m=9;
      }
void setup() 
{
SPI.begin();
mfrc522.PCD_Init();
Serial.begin(9600);
}
long randnumber;
int ch,i;
void loop()
{ //randnumber=random(0,10);
  randnumber=5;
  Serial.println(randnumber);
  byte letter;
 if (mfrc522.PICC_IsNewCardPresent())
 if(mfrc522.PICC_ReadCardSerial())
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
   //Serial.print(mfrc522.uid.uidByte[i], DEC);// print id as hex values
   content.concat(String(mfrc522.uid.uidByte[i],DEC));
} delay(2000);
       if(content.substring(0)=="1179884197")
    {   m=0;Serial.println(content.substring(0));}
       if(content.substring(0)=="214556830")
      { m=5;Serial.println(content.substring(0));}
       if(content.substring(0)=="17018679211")
      { m=1;Serial.println(content.substring(0));}
       if(content.substring(0)=="")
       m=2;
       if(content.substring(0)=="")
       m=3;
       if(content.substring(0)=="")
       m=4;
       if(content.substring(0)=="")
       m=6;
       if(content.substring(0)=="")
       m=7;
       if(content.substring(0)=="")
       m=8;
       if(content.substring(0)=="")
       m=9;
 switch(randnumber)
{ case(5):   {     Serial.println("Show first card on surface");
                   delay(5000);
                  if (mfrc522.PICC_IsNewCardPresent())
                { Serial.print(" number on card u placed :");
                  surbhi();
                  i=m;
                  Serial.println(i);
                }
                 delay(4000);
                 if(mfrc522.PICC_IsNewCardPresent())
                { Serial.print("number on card u placed :");
                  surbhi();
                  ch=m;
                  Serial.println(ch);
                }
                 else
                 Serial.println("time running out place the second card");
                 delay(3000);
                 if(i+ch==5);
                 Serial.println("You are smart card");
            } break;
  
 case(6):     {     Serial.println("Show first card on surface");
                 if (mfrc522.PICC_IsNewCardPresent())
                { Serial.println(m);
                 m=i;
                }
                 else
                 Serial.print("time running out place the card");
                 if(mfrc522.PICC_IsNewCardPresent())
                { Serial.println(m);
                  m=ch;
                }
                 else
                 Serial.print("time running out place the second card");
                 if(i+ch==6);
                 Serial.println("You are smart card");
            } break;

case(1):   {     Serial.println("Show first card on surface");
                 if (mfrc522.PICC_IsNewCardPresent())
                { Serial.println(m);
                 m=i;
                }
                 else
                 Serial.print("time running out place the card");
                 if(mfrc522.PICC_IsNewCardPresent())
                { Serial.println(m);
                  m=ch;
                }
                 else
                 Serial.print("time running out place the second card");
                 if(i+ch==1);
                 Serial.println("You are smart card");
            } break;
           
                 
                  
}
delay(5000);
}
   
