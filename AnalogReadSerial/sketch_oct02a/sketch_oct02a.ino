#include <SoftwareSerial.h>

int led=3;
void setup() {
  Serial.begin(9600);
Serial.print("hjhkj");
  delay(1000);

  // put your setup code here, to run once:

}

void loop() 
{   
if(Serial.available()>1);
{
Serial.print(Serial.available());
Serial.println(Serial.read());
delay(1000);
}
}
