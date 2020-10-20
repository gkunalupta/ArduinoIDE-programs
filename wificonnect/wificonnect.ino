#include "ESP8266WiFi.h"

const char* ssid = "JioFiber 2.4ghz"; //Enter SSID
const char* password = "Mansi5481"; //Enter Password

void setup(void)
{ 
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("kdjkd");
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
}

void loop() 
{
}
