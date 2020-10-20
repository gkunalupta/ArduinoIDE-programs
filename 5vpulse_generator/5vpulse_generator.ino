int pin=13;
void setup() 
{ int pin=13;
  pinMode(pin,OUTPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{  int x=67;
 // tone(pin,10);
  Serial.println(pin);
  Serial.println(x);
// delay(1000);
 }
