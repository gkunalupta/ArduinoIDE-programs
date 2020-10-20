#include <dht.h>

dht DHT;

#define DHT11_PIN 6
int digitalPin = 6;
int PWM = 3;
int PWMVal;
int pos=7;
int neg=8;

void setup(){
  Serial.begin(9600);
// put your setup code here, to run once:
  pinMode(digitalPin, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(pos,OUTPUT);
  pinMode(neg,OUTPUT);
}
void loop()
{  delay(2000);
  int chk = DHT.read11(DHT11_PIN);
  int temp=DHT.temperature;
  
  if(temp>25&&temp<=30)
{  Serial.print("temp is ");
Serial.println(temp);
 //PWMVal=map(DHT.temperature,20,45,850,1023);
//Serial.print("temperature between 25-30 ");
//Serial.println(PWMVal);
Serial.println(" fan speed is 30 percent");
analogWrite(PWM,77);
digitalWrite(pos,HIGH);
digitalWrite(neg,LOW);
delay(10000);  
 }
 if(temp>30&&temp<=35)
 {Serial.print("temp is ");
 Serial.println(temp);
  //PWMVal=map(DHT.temperature,20,45,450,1023);
 //Serial.print("temperature between 30-35 ");
 //Serial.println(PWMVal);
 Serial.println("fan speed is 60 percent");
 analogWrite(PWM,159);
 digitalWrite(pos,HIGH);
 digitalWrite(neg,LOW);
delay(10000); 
 }
 if(temp>35&&temp<=40)
 {Serial.print("temp is ");
 Serial.println(temp);
  //PWMVal=map(DHT.temperature,20,45,450,1023);
 //Serial.print("temperature between 30-35 ");
 //Serial.println(PWMVal);
 Serial.println("fan speed is 100 percent");
 analogWrite(PWM,253);
 digitalWrite(pos,HIGH);
 digitalWrite(neg,LOW);
delay(10000); 
}
if(temp>40)
{Serial.print("temp is ");
 Serial.println(temp);
  //PWMVal=map(DHT.temperature,20,45,450,1023);
 //Serial.print("temperature between 30-35 ");
 //Serial.println(PWMVal);
 Serial.println("fan speed is 100 percent");
 analogWrite(PWM,255);
 digitalWrite(pos,HIGH);
 digitalWrite(neg,LOW);
delay(10000); 
}
}
