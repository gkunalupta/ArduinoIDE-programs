int buttonstate, buttonoutput, buttonoutput1;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  

}

void loop() {

  buttonstate = digitalRead(3);
  Serial.println(buttonstate);

  buttonoutput = 9;
  buttonoutput1=10;

  if (buttonstate == 0)
{
    digitalWrite(buttonoutput, HIGH);
    digitalWrite(buttonoutput1,LOW);
}
  if (buttonstate == 1)
   { digitalWrite(buttonoutput, LOW);
   digitalWrite(buttonoutput1,HIGH);
   }
}
