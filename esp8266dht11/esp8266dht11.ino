#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin D5
DHT dht(dht_dpin, DHTTYPE); 
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  //Serial1.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}
void loop()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();         

    Serial.print("temperature = ");
    Serial.println(t); 
   // Serial1.write(t);
  delay(1000);
}
