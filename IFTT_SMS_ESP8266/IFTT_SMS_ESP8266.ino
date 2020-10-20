/*Program to send SMS from ESP8266 via IFTTT.
 * For complete detials visit: www.circuitdigest.com
 * EXAMPLE URL: (do not use This)
 *  https://maker.ifttt.com/trigger/ESP/with/key/b8h22xlElZvP27lrAXS3ljtBa0092_aAanYN1IXXXXX
 *  
 */

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "KG";
const char* password = "12345678";

const char* host = "maker.ifttt.com";
const int httpsPort = 443;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "trigger/ESP_EVENT/with/key/n5zpnMlr_aIxTvwH0DQhl0GNt_q6ZUN8wUi-KxYLi57";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');

  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}

void loop() {
}
