#include "ESP8266WiFi.h"

  #include "Wire.h"

  
  #include "RTC_DS1307.h"
  
  RTC_DS1307 rtc;
  
  void setup() {
    Serial.begin(115200);
    Serial.println("");
    Serial.println("START");
    
    Wire.begin();
  
   // rtc.SQW( f32768hz );
 rtc.SetTime( 00, 40, 13, 1, 06, 03, 17 );
  
  }
  
  void loop() {
//Read time from DS1307 and display (You must be connected to the serial port to see results) 
  rtc.DisplayTime();
  //Convert time to unix timestamp
  long uts = rtc.UnixTimestamp();
  Serial.println( uts );
  delay(1000);
    
  }
