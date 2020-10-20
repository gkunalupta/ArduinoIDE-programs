#include "IFTTTESP8266.h"
#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11  

#define EVENT  "ESP_EVENT"  // Put here your Maker Event Name
#define KEY  "n5zpnMlr_aIxTvwH0DQhl0GNt_q6ZUN8wUi-KxYLi57"  // Put here your IFTTT key
#define WIFISSID "JioFiber 2.4ghz"
#define PASSWORD "Mansi5481"

IFTTT client(KEY);
DHT dht(DHTPIN, DHTTYPE);
int c=0;
void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
   // dht.begin();
    
}
void loop()
{
 Serial.println("*********************IFTTT DHT11 SMS *******************************");
   
    float t = dht.readTemperature();
    String value = String(25);
    delay(1000);
    if(c<1)
   {
    client.add(value); // specifies the args of type "String"
    client.sendAll(EVENT);
    c++;
    delay(2000);
    Serial.println(c);
   }
}
