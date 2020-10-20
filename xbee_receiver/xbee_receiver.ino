/*  ~ Simple Arduino - xBee Receiver sketch ~

  Read an PWM value from Arduino Transmitter to fade an LED
  The receiving message starts with '<' and closes with '>' symbol.

  Dev: Michalis Vasilakis // Date:2/3/2016 // Info: www.ardumotive.com // Licence: CC BY-NC-SA                    */
//Constants
#include<Wire.h>
//#include <Adfruit_GFX.h>

#include<SoftwareSerial.h>
SoftwareSerial xbeerec(2,3);  //rx,tx
//Variables
bool started = false; //True: Message is strated
bool ended  = false; //True: Message is finished
char incomingByte ; //Variable to store the incoming byte
char msg[10];    //Message - array from 0 to 2 (3 values - PWM - e.g. 240)
byte index;     //Index of array

void setup() {
  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
  
  xbeerec.begin(115200);
}

void loop() {

  while (xbeerec.available() > 0)
  {
    //Read the incoming byte
    incomingByte = xbeerec.read();
    //Start the message when the '<' symbol is received
    Serial.println(incomingByte);


  }}



  /*
    if (incomingByte == '<')
    {

      index = 0;
      msg[index] = '\0'; // Throw away any incomplete packet
    }
    //End the message when the '>' symbol is received
    else if (incomingByte == '>')
    {
      msg[index] = '\0';
      break; // Done reading - exit from while loop!
      int j = index;
    }
    //Read the message!
    else
    {
      if (index < 10) // Make sure there is room
      {
        msg[index] = incomingByte; // Add char to array
        index++;
        msg[index] = '\0'; // Add NULL to end
      }
    }


  }

}
*/
