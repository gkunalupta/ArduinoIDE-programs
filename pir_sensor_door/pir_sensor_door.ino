int pir=7;
int led=13;
int pos=4;
int neg=2;


void setup() 
{ Serial.begin(9600);
pinMode(pir,INPUT);
pinMode(pos,OUTPUT);
pinMode(neg,OUTPUT);
pinMode(led,OUTPUT);
digitalWrite(pos,LOW);
digitalWrite(neg,LOW);
digitalWrite(led,LOW);

  // put your setup code here, to run once:

}

void loop()
{ Serial.println(digitalRead(pir));
   
  if(digitalRead(pir)==HIGH)
  {
    Serial.print("DOOR is OPENING ");
   digitalWrite(pos,HIGH);
   digitalWrite(neg,LOW);
   digitalWrite(led,HIGH);
   Serial.print(digitalRead(pos));
   Serial.println(digitalRead(neg));
   delay(1000);
   Serial.print("door is open ");
   //delay(2000);
   //digitalWrite(pos,LOW);
  // digitalWrite(neg,LOW);
   Serial.print(digitalRead(pos));
   Serial.println(digitalRead(neg));
   delay(1000);
   Serial.print("door is closing");
   digitalWrite(pos,LOW);
   digitalWrite(neg,HIGH);
   digitalWrite(led,LOW);
   Serial.print(digitalRead(pos));
   Serial.println(digitalRead(neg));
   delay(1000);
   Serial.print("door is closed");
   digitalWrite(pos,LOW);
   digitalWrite(neg,LOW);
     Serial.print(digitalRead(pos));
   Serial.println(digitalRead(neg));
  }

   
}
