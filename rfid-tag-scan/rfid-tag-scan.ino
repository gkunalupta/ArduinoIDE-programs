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
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}int m;
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
return;
  if (! mfrc522.PICC_ReadCardSerial()) 
  return;
  Serial.println("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], DEC);
    // content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], DEC));
  }
  Serial.println();
  Serial.println(content.substring(0));
  Serial.print("Message : ");
  content.toUpperCase();
 if (content.substring(0) == "1179884197") //change here the UID of the card/cards that you want to give access
 {    Serial.println("Authorized access");
    m=0;
  }
  else if(content.substring(0)=="214556830")
  {  Serial.println(" Access denied");
  m=5;
  }else if(content.substring(0)=="17018679211")
  { Serial.println("kjk");
  m=1;
  } 
  Serial.println(m);
  
}
