#include <dht.h>

dht DHT;


int digitalPin = 8;


void setup(){
  Serial.begin(9600);
// put your setup code here, to run once:
  pinMode(digitalPin, INPUT);
 
}
void loop()
{  delay(2000);
  
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  

  
}
