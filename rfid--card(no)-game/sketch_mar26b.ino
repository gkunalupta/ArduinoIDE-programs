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
void drishti()
{   String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
     { Serial.print(mfrc522.uid.uidByte[i], DEC);
       content.concat(String(mfrc522.uid.uidByte[i], DEC));
      }Serial.println();
  
  Serial.println("iikl");
 Serial.println(content.substring(0));
 content.toUpperCase();
 if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 {    Serial.println("Authorized access");
    m=0;
  }
  if(content.substring(0)=="214556830")
  {  Serial.println(" Access denied");
  m=5;
  }if(content.substring(0)=="17018679211")
  { Serial.println("kjk");
  m=1;
  }
}
void tanisha()
 { String content="";
  

  if (!mfrc522.PICC_IsNewCardPresent())
    Serial.println("akhil");
   if ( ! mfrc522.PICC_ReadCardSerial()) 
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
   Serial.print(mfrc522.uid.uidByte[i], DEC);
   content.concat(String(mfrc522.uid.uidByte[i], DEC));
  }Serial.println();
  Serial.println("iikl");
  Serial.println(content.substring(0));
  content.toUpperCase();
  if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 {   Serial.println("Authorized access");
    m=0; 
  }
  else if(content.substring(0)=="214556830")
  { Serial.println(" Access denied");
  m=5;
  }else if(content.substring(0)=="17018679211")
  {Serial.println("kjk");
  m=1;
  }
 }
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}long randnumber;
void loop() 
{ 
  //randnumber=random(0,10);
  randnumber=5;
  Serial.println(randnumber);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
   return;
  if ( ! mfrc522.PICC_ReadCardSerial()) 
   return;

   switch(randnumber)
{ case(5):{  String content="";
             
                 drishti();
                 Serial.println(content.substring(0));
                 Serial.println(m);
              
                   Serial.print(" number on card u placed :");
                  i=m;
                   Serial.println(i);
                delay(7000);
              
           {   Serial.println("koioklk");   
            tanisha();
                Serial.println(m);
                 Serial.print("number on second  card u placed :");
                 ch=m;
                 Serial.println(ch);
           } delay(3000);
                 if(i+ch==5)
                 Serial.println("You are smart card");
           
            break;
         }
  
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
           
                 
}}
