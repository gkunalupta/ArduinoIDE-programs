/*DTMF (mobile) based Home automation
 Author : Jithin T; DEBUT LABS (jithin.1005@gmail.com)
 Authored on : 01 March 2017
 This Arduino Sketch is part of DTMF and GSM Based Home Automation tutorial.
 this sketch will do all what is necessary to answer an incomming call (from any number), receive keypad number dials (from remote caller) and operate relays as per instruction.
 Here we have intrerfaced only two relays. First keytone will deceive the relay ('1' for Relay 1 -connected to D8- and '2' for Relay 2 -connected to D9-)
 Second key tone will decide the status of the Relay ('1' for relay 'ON' and '2' for Relay 'OFF') any other key strokes will be neglected.
 Circuit Necessary
 > Arduino Uno
 > GSM module - with SIM800
 >Relays
 
**************************************************************/


#include <SoftwareSerial.h>
// defining communicationion pins for Software Serial
# define GSM_RX 2 // Connect TX of GSM module
# define GSM_TX 3 // Connect RX of GSM module


// Defining interfacing pins for Relay board
# define RELAY_1 8
# define RELAY_2 9

SoftwareSerial gsm_board(GSM_RX,GSM_TX);

boolean call_flag=0, relay_flag=0;
int i=0,j=0,x=-1;
char n[3];
void gsm_initilaize();// used to inilitize the gsm and chk all its parameters

void setup() {
  // put your setup code here, to run once:
  gsm_board.begin(9600);
  Serial.begin(9600);
  pinMode(RELAY_1,OUTPUT);
  pinMode(RELAY_2,OUTPUT);
  digitalWrite(RELAY_1,HIGH);
  digitalWrite(RELAY_2,HIGH);
// gsm_initilaize();

}

//////////////////////////////setup ends/////////////////////////////

/////////////////////loop begins///////////////////////////
void loop() 
{ 
  char data ;
   String gsm_data; // to hold incomming communication from GSM module
   //gsm_board.println();
  while(gsm_board.available())
  {
    char c = gsm_board.read();
    gsm_data+=c;
     if (c>=48 && c<=59)
   {
     data = c;
    delay(10);
   //Serial.println(gsm_data);
   }
  }Serial.println(gsm_data);
   delay(1000);
                           
  /*
   * 1 2 3
   * 4 5 6 
   * 7 8 9
   *   0 
   */
  switch (data){
    case 48 :{
               Serial.println (data);
              
    }
              
              break;
    case 49 : {
                 Serial.println (data);
                digitalWrite(RELAY_2,HIGH);
                digitalWrite(RELAY_1,LOW);
                }
              break;
    case 50 : {
      Serial.println (data);
    digitalWrite(RELAY_1,HIGH);
                digitalWrite(RELAY_2,LOW);
                }break;
    case 51 : Serial.println (data);break;
    case 52 : Serial.println (data);break;
    case 53 : Serial.println (data);break;
    case 54 : Serial.println (data);break;
    case 55 : Serial.println (data);break;
    case 56 : Serial.println (data);break;
    case 57 : Serial.println (data);break;
    default : Serial.println (data);   

    }
 /* Serial.println(data);
  switch(data){
    case 
    }
  Serial.println(gsm_data);
  //read serial data and store it to gsm_data STRING instance;
 */
  //delay(100);
  if(!call_flag) // if call is not in connected, checking for ring
  {
    x=gsm_data.indexOf("RING");
    if(x>-1)
    {
      delay(5000);
      gsm_board.println("ATA");
      call_flag=1;
    }
  }  // ring test over, call flag high if sim rings
  if(call_flag) // if call is connected
  {
    x=gsm_data.indexOf("DTMF"); //checkinh dtmf and storing approprietly
    if(x>-1)
    {
      n[j]=gsm_data[x+6];
      Serial.println(n[j]);
      j++;
    }
    x=gsm_data.indexOf("NO CARRIER"); // Checking whether call is still connected or not
    if(x>-1)
    {
      gsm_board.println("ATH");
      relay_flag=1;
      call_flag=0;
      j=0;
    }
  }

 
  
}
//////////////////////////////loop ends/////////////////////////////

/////////////////////gsm inilitize begins///////////////////////////
/*void gsm_initilaize()
{
  boolean gsm_Ready=1;
  Serial.println("initializing GSM module");
  while(gsm_Ready>0)
  {
   gsm_board.println("AT");
  Serial.println("AT");
   while(gsm_board.available())
   {
     if(gsm_board.find("OK")>0)
     {  gsm_Ready=0;
   Serial.println("OK");
   }
   }
   delay(2000);
  }
  Serial.println("AT READY");
  // GSM MODULE REPLIED 'OK' TO 'AT' INPUT, INDICAING THE MODULE IS OK AND FUNCTIONING
  
  boolean ntw_Ready=1;
  Serial.println("finding network");
  while(ntw_Ready>0)
  {
   gsm_board.println("AT+CPIN?");
   Serial.println("AT+CPIN?"); 
   while(gsm_board.available())
   {Serial.println(gsm_board.read());
     if(gsm_board.find("+CPIN: READY")>0)
      {
        ntw_Ready=0;
        Serial.println("+CPIN: READY");
      }
      }
   delay(2000);
  }
  Serial.println("NTW READY");
  
// GSM MODULE REPLIED '+CPIN:READY' TO 'AT+CPIN?' INPUT, INDICAING THE NETWORK IS OK AND FUNCTIONING
  
  boolean DTMF_Ready=1;
  Serial.println("turning DTMF ON");
  while(DTMF_Ready>0)
  {
   gsm_board.println("AT+DDET=1");
   Serial.println("AT+DDET=1"); 
   while(gsm_board.available())
   {
     if(gsm_board.find("OK")>0)
       DTMF_Ready=0;
   Serial.println("ok"); }
   delay(2000);
  }
  Serial.println("DTMF READY");// GSM MODULE REPLIED '+OK' TO 'AT+DDET=1?' INPUT, INDICAING THE DTMF IS ON;

}
//////////////////////////////gsm inilitization ends/////////////////////////////
*/
