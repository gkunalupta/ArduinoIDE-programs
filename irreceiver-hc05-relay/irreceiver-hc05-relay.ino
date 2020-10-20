/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include<SoftwareSerial.h>
SoftwareSerial kunal(2,3);
int RECV_PIN = 4;
int RELAY_PIN =11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void dump(decode_results *results)
{    
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN){
  kunal.println("unknown protocol");}
   else
  {
    if (results->decode_type == NEC) 
    kunal.print("Decoded NEC: "); 
    else if (results->decode_type == SONY) 
    kunal.print("Decoded SONY: ");
    else if (results->decode_type == RC5)
    kunal.print("Decoded RC5: ");
    else if (results->decode_type == RC6)
    kunal.print("Decoded RC6: ");
   }
   kunal.println(results->value);
    //kunal.print("(");
   // kunal.println(results->bits, DEC);
    //kunal.println(" bits)");  
 

}
   void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(13, OUTPUT);
    Serial.begin(9600);
  irrecv.enableIRIn();
   kunal.begin(9600);
}  unsigned long last = millis();
void loop() 
{   delay(1000);
  kunal.println(digitalRead(RELAY_PIN));   
  //delay(10);
  int c[5]={0,0,0,0,0};
  int d[5] = {107,97,110,97,108};//kanal
  int f[5]={071,117,112,116,97};//Gupta
  int count=0;
  if (irrecv.decode(&results))                                     //For ir sensor
        {//delay(1000);
          Serial.print("for ir receiver");
         Serial.println(irrecv.decode(&results));
        kunal.println(" received signal from ir receiver");
         count=1;
         dump(&results);
        }else
        { 
         Serial.println("no signal fromn ir sensor");
         count=2;
         }
   if(count==2&&count!=1)                                                   //For bluetooth
         {//delay(1000);
               //Serial.print("for bluetooth ");
               //Serial.println(kunal.available());   
               //for ( int i = 0; i< 5 ; i++)
               //Serial.println(c[i]);
           while(kunal.available()>0)
            {         
               //Serial.println(kunal.available());  
                //for ( int i = 0; i< 5 ; i++)
              // Serial.println(c[i]); 
               kunal .println("received signal from bluetooth");
               for ( int i = 0; i< 9 ; i++)
               c[i] = (kunal.read());
              // for ( int i = 0; i< 5 ; i++)
               //Serial.println(c[i]);
            }
         }  
    if (millis()-last>5)
    {          Serial.println(count);
               switch (count)
           {
               case(1): {    // while(ch=='y')
                                 if (results.value==33444015)  // mi remote home button
                               { 
                                 digitalWrite(RELAY_PIN, LOW);
                                 kunal.println("relay is off");
                                }  
                                 else if( results.value==33478695)// mi remote straight button
                               { 
                                 digitalWrite(RELAY_PIN, HIGH);
                                 kunal.println("relay is on");
                               }
                                 irrecv.resume(); // Receive the next value
                                // else if (kunal.available())
                                 //ch=='n';
                                 //continue();
                            }     break;
               
              case(2):{    int s=0;
                              for ( int i = 0; i<5 ; i++)
                              if(c[i] == d[i])           //kanal
                             {kunal.println("kunal");
                              digitalWrite(RELAY_PIN, LOW);
                              kunal.println("light is off");
                             }else if (c[i]==f[i])       //Gupta
                            {kunal.println("Gupta");
                             digitalWrite(RELAY_PIN,HIGH);
                             kunal.println(" lights is on");
                        
                      }break;
        }
      last = millis();
    }  
    }}
