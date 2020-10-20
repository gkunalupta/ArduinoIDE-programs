void setup() {
  pinMode(6, INPUT);
  pinMode(14,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //if (digitalRead(6) == HIGH)
  { digitalWrite(14,HIGH);}
 // else
  //{ digitalWrite(10,LOW);}
   
    Serial.println(digitalRead(6));
 
}
