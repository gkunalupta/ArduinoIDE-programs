#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "JioFiber 2.4ghz"; //Enter Wi-Fi SSID
const char* password =  "Mansi5481"; //Enter Wi-Fi Password


 IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);



const char signMessage[] PROGMEM = {"I AM PREDATOR,  UNSEEN COMBATANT. CREATED BY THE UNITED STATES DEPART"};

void setup() 
{
  Serial.begin(9600); //Begin Serial at 115200 Baud
  WiFi.begin(ssid, password);  //Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
      delay(500);
      Serial.println("Waiting to connect...");
  }

  // tells which mode is selected 
 int n = WiFi.getMode();
 if(n==1)Serial.println("esp8266 is selected as Access Point(Server)");
 else if(n==2)Serial.println("Esp8266 is selected as Station Mode(client)");
 else if(n==3)Serial.println("Esp8266 is selected as Station + Access Point(client=server)");
 else if(n==4)Serial.println("WiFi Off"); 
 
 //IP address of station mode
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
  
  //Sets ssid and password for softAP
  WiFi.softAP("Kunal","12345678");

  WiFi.softAPConfig(local_IP, gateway, subnet);

  
  Serial.println(WiFi.hostname());
  
  // prints ssid of wifi connected
  Serial.println(WiFi.SSID());

  //IP adress of soft-ap
  Serial.println("IP address of SoftAP");
  Serial.println(WiFi.softAPIP());

  

  
  server.on("/", handle_index); //Handle Index page
  
  server.begin(); //Start the server
  Serial.println("Server listening");

    //Number of stations connected
  WiFi.softAPgetStationNum();
}

void loop() {
  //Serial.println(signMessage);
  server.handleClient(); //Handling of incoming client requests
}

void handle_index() {
  String s = signMessage;
  //Print Hello at opening homepage
  //server.send(200, "text/italic", "Hello! This is an index.");
server.send(200, "text/italic", s);

}
