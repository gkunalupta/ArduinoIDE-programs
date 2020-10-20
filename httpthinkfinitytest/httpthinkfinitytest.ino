/*
 GET /test/comm/sens.php?key=f46fa009d3c6902ea2a805567c7ed4&val1=01&val2=02&val3=03&val4=04&Stat=1 HTTP/1.1\r\nHOST:162.214.80.6\r\n\r\n\r\n

GET /test/comm/sens.php?key=f46fa009d3c6902ea2a805567c7ed4&val1=01&val2=02&val3=03&val4=04
GET update?api_key=1J2QROTV6JS6UZ25&field1=98 HTTP/1.1

GET /test/comm/sens.php?key=f46fa009d3c6902ea2a805567c7ed4&val1=01&Stat=1 
GET / HTTP/1.1
GET /update?api_key=K86PTN9OPANWW8MF&field1=988
GET /test/comm/sens.php?key=f46fa009d3c6902ea2a805567c7ed4&val1=01&val2=02&val3=03&val4=04&Stat=1 HTTP/1.1




GET /test/comm/sens.php?Help=TRUE
*/
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "JioFiber 2.4ghz";
const char* password = "Mansi5481";
 
void setup () {
 
Serial.begin(9600);
WiFi.begin(ssid, password);
 Serial.println("KunalGupta");
  while (WiFi.status() != WL_CONNECTED)
  {
 
delay(1000);
Serial.print("Connecting..");
 
}

}
 
void loop() 
{

  
 int c=0;
if (WiFi.status() == WL_CONNECTED)
{ //Check WiFi connection status
 c++;
HTTPClient http;  //Declare an object of class HTTPClient
//http.begin("http://innovations.thinkfinitylabs.com/test/comm/sens.php?Help=TRUE"); 
//http.begin("http://jsonplaceholder.typicode.com/users/1");  //Specify request destination
//http.begin("http://innovations.thinkfinitylabs.com/test/comm/sens.php?key=f46fa009d3c6902ea2a805567c7ed4&val1=01&val2=02&val3=03&val4=04&Stat=1");
//http.begin("http://innovations.thinkfinitylabs.com/test/comm/sens.php?key=f46fa009d3c6902ea2a805567c7ed4&val1=71");
//http.begin("http://api.thingspeak.com/update?api_key=K86PTN9OPANWW8MF&field1=90");
//http.begin("http://innovations.thinkfinitylabs.com/test/comm/sens.php?Help=TRUE");
//http.begin("https://maker.ifttt.com/trigger/ESP_EVENT/with/key/n5zpnMlr_aIxTvwH0DQhl0GNt_q6ZUN8wUi-KxYLi57");
//Serial.println("4");
http.begin("https://api.openweathermap.org/data/2.5/weather?q=delhi&appid=885e9149105e8901c9809ac018ce8658");
int httpCode = http.GET();                                                                  //Send the request
 //Serial.println("5");
if (httpCode > 0) { //Check the returning code
 //Serial.println("6");
String payload = http.getString();   //Get the request response payload
Serial.println(payload);                     //Print the response payload
 
}
 
http.end();   //Close connection
 
}
 
delay(3000);    //Send a request every 30 seconds
 
 Serial.println("kljhgc");
}
