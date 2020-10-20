#include <SoftwareSerial.h>

int OUT=7;
pinMode(OUT,INPUT);
void setup() {
  myserial.begin(9600);// to establish communication b/w bt module and arduino.
  myserial.print(" Hello World");
  Serial.begin(9600);// to establish communication b/w arduino and ir sensor.
Serial.print("Welcome");
  SoftwareSerial myserial(11,10)//rx and tx pin of myserial

  // put your setup code here, to run once:

}

void loop() 
{
  while(Serial.available())
 {
    if(OUT==HIGH)
        { 
          myserial.write(Serial.read())
          
        }


}
