

/*
 * ESP8266 NodeMCU Real Time Graphs Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//#include "index.h" //Our HTML webpage contents with javascripts
 
#define LED 2  //On board LED
 
//SSID and Password of your WiFi router
const char* ssid = "JioFiber 2.4ghz";
const char* password = "Mansi5481";
 
ESP8266WebServer server(80); //Server on port 80
const char index_page[] = "<!DOCTYPE HTML><html> <head>   <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">   <script src=\"https://code.highcharts.com/highcharts.js\"></script>   <style>     body {       min-width: 310px;       max-width: 800px;       height: 400px;       margin: 0 auto;     }     h2 {       font-family: Arial;       font-size: 2.5rem;       text-align: center;     }   </style> </head> <body>   <h2>ESP8266 Distance Plot</h2>   <div id=\"chart-distance\" class=\"container\"></div> </body> <script> var chartT = new Highcharts.Chart({   chart:{ renderTo : 'chart-distance' },   title: { text: 'HC-SR04 Distance' },   series: [{     showInLegend: false,     data: []   }],   plotOptions: {     line: { animation: false,       dataLabels: { enabled: true }     },     series: { color: '#059e8a' }   },   xAxis: { type: 'datetime',     dateTimeLabelFormats: { second: '%H:%M:%S' }   },   yAxis: {     title: { text: 'Distance (CM)' }   },   credits: { enabled: false } }); setInterval(function ( ) {   var xhttp = new XMLHttpRequest();   xhttp.onreadystatechange = function() {     if (this.readyState == 4 && this.status == 200) {       var x = (new Date()).getTime(),           y = parseFloat(this.responseText);       //console.log(this.responseText);       if(chartT.series[0].data.length > 40) {         chartT.series[0].addPoint([x, y], true, true, true);       } else {         chartT.series[0].addPoint([x, y], true, false, true);       }     }   };   xhttp.open(\"GET\", \"/distance\", true);   xhttp.send(); }, 3000 ) ; </script> </html>";

const char MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script src="https://code.highcharts.com/highcharts.js"></script>
  <style>
    body {
      min-width: 310px;
      max-width: 800px;
      height: 400px;
      margin: 0 auto;
    }
    h2 {
      font-family: Arial;
      font-size: 2.5rem;
      text-align: center;
    }
  </style>
</head>
<body>
  <h2>ESP8266 Distance Plot</h2>
  <div id="chart-distance" class="container"></div>
</body>
<script>
var chartT = new Highcharts.Chart({
  chart:{ renderTo : 'chart-distance' },
  title: { text: 'HC-SR04 Distance' },
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#059e8a' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Distance (CM)' }
  },
  credits: { enabled: false }
});
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);
      //console.log(this.responseText);
      if(chartT.series[0].data.length > 40) {
        chartT.series[0].addPoint([x, y], true, true, true);
      } else {
        chartT.series[0].addPoint([x, y], true, false, true);
      }
    }
  };
  xhttp.open("GET", "/distance", true);
  xhttp.send();
}, 3000 ) ;
</script>
</html>)rawliteral";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
//const char signMessage[] PROGMEM = {"I AM PREDATOR,  UNSEEN COMBATANT. CREATED BY THE UNITED STATES DEPART"};
const char signMessage[]= {"Kunal"};
void handleRoot() {
 String s = signMessage; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleADC() {
 int a = analogRead(A0);
 String adcValue = String(a);
 digitalWrite(LED,!digitalRead(LED)); //Toggle LED on data request ajax
 server.send(200, "text/plane", adcValue); //Send ADC value only to client ajax request
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
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
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  //server.on("/distance", handleADC); //This page is called by java Script AJAX
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
