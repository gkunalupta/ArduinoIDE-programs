int pir=7;
int led=3;
int val;



void setup() 
{ Serial.begin(9600);
pinMode(pir,INPUT);
pinMode(led,OUTPUT);

  // put your setup code here, to run once:

}

void loop()
{  if(pir==HIGH);
 {
   {
 
  digitalWrite(led,HIGH);
    }
 else
   { 
    digitalWrite(led,LOW);
   }
 }
  Serial.println(digitalRead(pir));
  Serial.println(digitalRead(led));
  // put your main code here, to run repeatedly:
delay(1000);
}
