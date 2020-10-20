#include<SoftwareSerial.h>
//int lir=8;
int out=4;
SoftwareSerial kunal(2,3);
char c[10];
char d=' ';
void setup() 
{
  Serial.begin(9600);//communication between computer and arduino
  kunal.begin(9600);
pinMode(out,OUTPUT);
//digitalWrite(lir,HIGH);
//pinMode(lir,INPUT);s
String inputstring;
kunal.println("start");
}
void loop() 
{     //dump(&results);
unsigned long last = millis();
int c[5];
int d [5] = {107,
117,
110,
97,
108
};
//Serial.println(kunal.available());
while(kunal.available())
{   //Serial.println(Serial.available());
    kunal.println(kunal.available());
    for ( int i = 0; i< 5 ; i++)
      c[i] = (kunal.read());
    
     for ( int i = 0; i< 5 ; i++)
      Serial.println(c[i]);
    
 //kunal.println(c);

  for ( int i = 0; i< 5 ; i++)
      if(c[i] == d[i])
        kunal.println("Done");
      
    }
 
 
 
 }
 
 
