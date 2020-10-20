#include<SoftwareSerial.h>
SoftwareSerial gettobyte(2,3); //rx, tx
void setup() 
{
 Serial.begin(9600);
 Serial.println("****************Welcome to Gettobyte************************");
}

void loop()
{ 
  
  //Simple UART Transmission 
 int a = 23;
 
  Serial.println("Firmware development");
  delay(1000);
  Serial.println("Gettobyte");
  delay(1000);
/*
char inByte;
String rec;
  while(!Serial.available());
  {
    //****For single character*******
    //inByte = Serial.read();
   //Serial.println(inByte);


       //******for string**********
    rec = Serial.readString();
    //Serial.print(rec);
   }
Serial.println(rec);

}






/*
 * 
 * 
 * 
 * String rec;
  while(!Serial.available());
  {
    //****For single character*******
    //float inByte = Serial.read();
    //Serial.println(inByte);
    
    
    
    //******for string**********
    rec = Serial.readString();
    Serial.print(rec);
    //
    Serial.write(45);
   }
  //Serial.println(rec);
 // delay(1000);






 
  int c[5];
  int d[5] = {107,117,110,97,108};//kunal
  int f[5]={071,117,112,116,97};//Gupta
  while(Serial.available()>0)
    {        int  c[5]={0,0,0,0,0};
                 
                 Serial.println("received signal from bluetooth");
                for ( int i = 0; i< 5 ; i++)
                c[i] = (Serial.read());
                for ( int i = 0; i< 5 ; i++)
                Serial.println(c[i]);}      
                for ( int i = 0; i<5 ; i++)
            {    if(c[i]==d[i])
              { 
                  digitalWrite(RELAY_PIN, LOW);
                  Serial.println("relay is off");
               }else if (c[i]==f[i])
               {
                digitalWrite(RELAY_PIN,HIGH);
               Serial.println(" relay is on");
               }
            }// put your main co
            */
