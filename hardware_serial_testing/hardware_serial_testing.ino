void setup() 
{
  Serial.begin(115200);
  // put your setup code here, to run once:
Serial.println("kunal");
}

void loop() 
  {
    //Serial.println("kunal");
    while (Serial.available()) 
   {
    char c = Serial.read();
    Serial.print(c);
  }
  }
  

  // put your main code here, to run repeatedly:
