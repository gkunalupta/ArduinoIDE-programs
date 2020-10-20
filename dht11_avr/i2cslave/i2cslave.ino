/*
 * i2cslave.cpp
 *
 * Created: 4/7/2020 1:27:48 AM
 * Author : kunal
 */ 
 // if direction bit DDR bit is set to 0 -then it is slave tarnsmitter
 // if direction bit DDR is set to 1 - then it is salve receiver
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <SoftwareSerial.h>
#include "uarts.h"
int8_t a,b;
char c;
 
 
 void i2cinitslave( uint8_t slA)
 { 
  Serial.println("njnn,");
  
 // set twi slave address (skip over TWGCE bit)
  TWAR = 0b11110010;
  //TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); //init,twi module
  }
  /*
   * Listen to bus

Slave device always need to listen to TWI bus to check whether it get addressed by any Master.
When it is addressed, TWINT bit get set. So need to monitor TWINT bit.
I2C_Slave_Listen function

Input argument : - it has no any input argument.

Return                 : - it returns event status.
   */
int8_t i2clisten()
{
  while(1)
     {
      Serial.println("0990");
  uint8_t status;     /* Declare variable */
  Serial.println(TWCR,BIN);
  while((TWCR&(1<<TWINT)));  /* Wait to be addressed */
  Serial.println("0990");
  Serial.println(TWSR,BIN);
  status=TWSR&0xF8;   /* Read TWI status register */
  if(status==0x60||status==0x68)  /* Own SLA+W received &ack returned */
  return 0;     /* Return 0 to indicate ack returned */
  if(status==0xA8||status==0xB0)  /* Own SLA+R received &ack returned */
  return 1;     /* Return 0 to indicate ack returned */
  if(status==0x70||status==0x78)  /* General call received &ack returned */
  return 2;     /* Return 1 to indicate ack returned */
  else
  Serial.println(TWSR,BIN);     /* Else continue */
     }
  }

  void testlisten()
{     a=i2clisten();
  switch(b)
  {
    
    case 0:  Serial.println(" Own SLA+W received &ack returned  \n");
    break;
    case 1:  Serial.println(" Own SLA+R received &ack returned \n ");
    break;
    case 2:  Serial.println(" General call received &ack returned \n");
    break;
    
  }
  
}
  /*
   * Transmit data

After getting addressed by the master with SLA+R address, then slave must send the requested data.
Data to be send need to write in TWDR register.
After data write, enable TWI with acknowledgement and clear interrupt flag.
If acknowledgement not received frommaster,then slave device will clear TWINT flag and again listen to bus.
Also if REPEATED START/STOP received,then slave device will clear TWINT flag and again listen to bus.
I2C_Slave_Transmit function

Input argument : - it has input argument of character data to be send.

Return                 : - it returns event status.
   */
  
  int8_t i2cslavetransmit( char data)
  {
    uint8_t status;
    TWDR=data;      /* Write data to TWDR to be transmitted */
    TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);/* Enable TWI & clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));  /* Wait until TWI finish its current job */
    status=TWSR&0xF8;   /* Read TWI status register */
    if(status==0xA0)    /* Check for STOP/REPEATED START received */
     {
  TWCR|=(1<<TWINT); /* Clear interrupt flag & return -1 */
  return -1;
     }
    if(status==0xB8)    /* Check for data transmitted &ack received */
    return 0;      /* If yes then return 0 */
    if(status==0xC0)    /* Check for data transmitted &nack received */
     {
  TWCR|=(1<<TWINT); /* Clear interrupt flag & return -2 */
  return -2;
     }
    if(status==0xC8)    /* Last byte transmitted with ack received */
    return -3;      /* If yes then return -3 */
    else      /* else return -4 */
    return -4;
  }
  void testslavetransmit(char data )
{     
  b=i2cslavetransmit(data);
  switch(b)
  {
    
    case 0:  Serial.println(" Check for data transmitted &ack received \n");
    break;
    case -1:  Serial.println(" Check for STOP/REPEATED START received \n ");
    break;
    case -2:  Serial.println(" Check for data transmitted &nack received \n");
    break;
    case -3:  Serial.println("  Last byte transmitted with ack received \n");
    break;
    
  }
  
}
  /*
   * Receive data

After getting addressed by the master with SLA+W address,then slave need to receive data sent by the master.
After each byte received, slave need to return acknowledge about it to master.
If REPEATED START/STOP received,then slave device will clear TWINT flag and again listen to bus.
I2C_Slave_Recieve function

Input argument : - it has no input argument.

Return                 : - it returns received data or event status.
   */
  char i2cslavereceive()
  {
    uint8_t status;    /* Declare variable */
    TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI & generation of ack */
    while(!(TWCR&(1<<TWINT)));  /* Wait until TWI finish its current job */
    status=TWSR&0xF8;   /* Read TWI status register */
    if(status==0x80||status==0x90)/* Check for data received &ack returned */
    return TWDR;    /* If yes then return received data */

/* Check for data received, nack returned & switched to not addressed slave mode */
    if(status==0x88||status==0x98)
    return TWDR;    /* If yes then return received data */
    if(status==0xA0)    /* Check wether STOP/REPEATED START */
     {
  TWCR|=(1<<TWINT); /* Clear interrupt flag & return -1 */
  return -1;
     }
    else
    return -2;      /* Else return -2 */
  }
void testslavereceive()
{     
  c = i2cslavereceive();
  switch(c)
  {
    case -1:  Serial.println(" Check for STOP/REPEATED START received \n ");
    break;
    case -2:  Serial.println(" Fuckoff \n");
    break;

    
  }
  
}
char buffer[10];
    char count = 0;
  char x;  
  void setup(void)
  { 
    
    Serial.begin(9600);
    Serial.println("*****************8i2c slave ************************8");
    char x;
   // DDRC =0xff;
    i2cinitslave(0b11110010);
    /*
    i2clisten();
    testlisten();
    x=i2cslavereceive();
    testslavereceive();
   Serial.println(x);
   */
   printString0("klklk");
  }
    void loop()
{
      switch(i2clisten())  /* Check for SLA+W or SLA+R */
   {
      case 0:
    {
      Serial.println("Receiving:      ");
      do
      {
       count = i2cslavereceive();/* Receive data byte*/
       Serial.println(count);
      } while (count != -1);/* Receive until STOP/REPEATED START */
      count = 0;
      break;
    }
      case 1:
    {
      int8_t Ack_status;
      Serial.println("Sending :       ");
      do
      {
        Ack_status = i2cslavetransmit(count);/* Send data byte */
         Serial.println(count);
        count++;
      } while (Ack_status == 0);/* Send until Ack is receive */
      break;
    }
      default:
    break;
    
    }
    
}
