int led = 4;
int led1=7;
int led2=8;

int threshold = 600; //Change This
int volume=A0;

void setup()
{                
  Serial.begin(9600); // Serial port begin
  pinMode(led, OUTPUT); 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);    
}

void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
 
    //Serial print level
    
    Serial.println(volume);
    delay(100);

  if(volume>=threshold)
  {
    
  digitalWrite(led1,LOW);
  delay(100);
  digitalWrite(led1,HIGH);
  delay(100);
  }  
  else{
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1,LOW);
    delay(100);
    //3digitalWrite(led2,HIGH);// Turn OFF Led
  }

}
