int M1_forward=4;
int M1_backward=6;
int M1_left=7;
int M1_right=6;
#include <SoftwareSerial.h>

int x;

SoftwareSerial Bluetooth(2,3);
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(9600);
  {
    for(int i=4;i<=13;i++)
    {
      pinMode(i,OUTPUT);
    }
  }                              
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(Bluetooth.available())
  {
    x=Bluetooth.read();
   Serial.print(x);
   }
    if(x=='F')
    {
           digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      Serial.println("RIGHT");
      }
      if(x=='B')
    {
          digitalWrite(13,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      Serial.println("LEFT");
      }
      if(x=='R')
      {
           digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      Serial.println("RIGHT");
        
      }
      if(x=='L')
      {
          digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      Serial.println("LEFT");
      }
      if(x=='S')
      {
        digitalWrite(13,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      Serial.println("STOP");
      
      }
      
}
