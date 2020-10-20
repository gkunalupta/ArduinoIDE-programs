/*

 * Modified by Rui Santos, http://randomnerdtutorialscom

 * based on IRremote Library - Ken Shirriff

*/

 

#include <IRremote.h>

 

int IR_Recv = 11;   //IR Receiver Pin 3

int bluePin = 3;

int greenPin = 9;

int yellowPin = 8;

 

IRrecv irrecv(IR_Recv);

decode_results results;

 

void setup(){

  Serial.begin(9600);  //starts serial communication

  irrecv.enableIRIn(); // Starts the receiver

  pinMode(bluePin, OUTPUT);      // sets the digital pin as output

  pinMode(greenPin, OUTPUT);      // sets the digital pin as output

  pinMode(yellowPin, OUTPUT);      // sets the digital pin as output 



}

 

void loop()
{

  //decodes the infrared input

  if (irrecv.decode(&results)){

    //long int decCode = results.value;

    Serial.println(results.value);

   if( 16679039 ==results.value)
  {
   digitalWrite(bluePin,HIGH);
   digitalWrite(bluePin,LOW);
  }
  
    irrecv.resume(); // Receives the next value from the button you press

  }

  delay(10);

}
