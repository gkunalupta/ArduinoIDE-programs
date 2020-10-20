/* 
 * ESP8266 NodeMCU DHT11 - Humidity Temperature Data logging Example
 * https://circuits4you.com
 * 
 * Referances
 * https://circuits4you.com/2017/12/31/nodemcu-pinout/
 * 
 * 
 * https://circuits4you.com/2019/01/25/esp8266-dht11-humidity-temperature-data-logging/
 */

#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <ESP8266WebServer.h>


 #include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
//#include "index.h" //Our HTML webpage contents with javascripts
#include "DHT.h"  //DHT11 Library for ESP
  
#define LED 2        //On board LED
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin D8
DHT dht(dht_dpin, DHTTYPE); 

//SSID and Password of your WiFi router
const char* ssid = "KG";
const char* password = "12345678";

AsyncWebServer server(80);
//ESP8266WebServer server(80); //Server on port 80


 
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
/*
void handleRoot()
{
 //String s = MAIN_page; //Read HTML contents
// server.send(200, "text/html", s); //Send web page
     server.send(SPIFFS, "/index.html");
}
*/
float humidity, temperature;
String handleADC() 
{
    int a = analogRead(A0);
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
 
    Serial.print(humidity);
    Serial.print(temperature);
  
    String data = "{\"ADC\":\""+String(a)+"\", \"Temperature\":\""+ String(temperature) +"\", \"Humidity\":\""+ String(humidity) +"\"}";
    Serial.println(data);
    return data;
    
    //server.send(200, "text/plane", data); //Send ADC value, temperature and humidity JSON to client ajax request
}

//==============================================================
//                  SETUP
//==============================================================
void setup()
{
  dht.begin();
  Serial.begin(115200);
  Serial.println();
if (! SPIFFS.begin ()) {
    Serial.println ("An Error has occurred while mounting SPIFFS");
    return;
  }
  //Ref 3: https://circuits4you.com/2019/01/25/interfacing-dht11-with-nodemcu-example/
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  //Onboard LED port Direction output
  pinMode(LED,OUTPUT); 
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP


       server.on ("/", HTTP_GET, [] (AsyncWebServerRequest * request) 
       {
         request-> send (SPIFFS, "/dht11.html");
        });


  
 // server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  //server.on("/readADC", handleADC); //This page is called by java Script AJAX
  server.on ("/readADC", HTTP_GET, [] (AsyncWebServerRequest * request) 
  {
  request-> send_P (200, "text / plain", handleADC().c_str());
  });
  server.begin();                  //Start server
  Serial.println("HTTP server started");
    humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  Serial.println(humidity);
  Serial.println(temperature);
}

//==============================================================
//                     LOOP
//==============================================================
void loop()
{
 // server.handleClient();          //Handle client requests
}
