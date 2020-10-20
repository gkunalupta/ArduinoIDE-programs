#define triacPulse 6
#include<SoftwareSerial.h>
SoftwareSerial kunal(2,3);

int x=0;
void setup()
{
   pinMode(8, INPUT);
   digitalWrite(8, INPUT_PULLUP); // pull up
   pinMode(triacPulse, OUTPUT);
  Serial.begin(9600);
kunal.begin(9600);
    }

void loop() {
   Serial.println(kunal.read());
   delay(100);
   
  if (kunal.available()>0)
{ 
    x=map(kunal.read(),0,255,7000,10);
    attachInterrupt(0, acon, FALLING); // attach Interrupt at PIN2
    
}  
  else if (kunal.available()<0)
{ 
       detachInterrupt(0); // Detach Interrupt
     } 
  } 

void acon()  
   {
    delayMicroseconds(x);
    digitalWrite(triacPulse, HIGH);
    delayMicroseconds(50);  //delay 50 uSec on output pulse to turn on triac  
    digitalWrite(triacPulse, LOW);
   } 
