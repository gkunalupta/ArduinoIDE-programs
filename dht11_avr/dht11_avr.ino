#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int digitalPin = 6;
int PWM = 8;
int sensorVal;
int PWMVal;

void setup(){
  Serial.begin(9600);
// put your setup code here, to run once:
  pinMode(digitalPin, INPUT);
  pinMode(PWM, OUTPUT);
digitalWrite(PWM,LOW);
}
void loop()
{  delay(2000);
  
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  sensorVal=DHT.temperature;

  
}
