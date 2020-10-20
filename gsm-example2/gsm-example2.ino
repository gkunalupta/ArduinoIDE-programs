// libraries
#include <GSM.h>

// PIN Number
#define PINNUMBER ""

// initialize the library instance
GSM gsmAccess;     // include a 'true' parameter for debug enabled

void setup()
{
  // initialize serial communications
  Serial.begin(9600);

  // connection state
  boolean notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while(notConnected)
  {
    if(gsmAccess.begin(PINNUMBER)==GSM_READY){
      notConnected = false;
      Serial.println("Connected to network");
    }
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
}

void loop()
{
  // Nothing here
}
 
