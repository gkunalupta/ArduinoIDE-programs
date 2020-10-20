 // if direction bit DDR bit is set to 0 -then it is slave tarnsmitter
 // if direction bit DDR is set to 1 - then it is salve receiver
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
 

#include <avr/interrupt.h>
#include <SoftwareSerial.h>
#include "uarts.h"
// Program for Slave mode
#include<avr/io.h>
#include<util/delay.h>
 
void TWI_init_slave(void);
void TWI_match_read_slave(void);
void TWI_read_slave(void);
void TWI_match_write_slave(void);
void TWI_write_slave(uint8_t );
 
char write_data,recv_data;
 
int main(void)
{  Serial.begin(9600);
   // UART_Init0();
DDRB=0xff;
int a;
//Serial.println("POLKUJ");
TWI_init_slave(); // Function to initilaize slave
//printString0("dknkcd");
while(1)
{  Serial.println("starrt");
   Serial.println(TWSR,BIN);
   TWI_match_read_slave(); //Function to match the slave address and slave dirction bit(read) 
    
      //TWI_match_read_slave(); //Function to match the slave address and slave dirction bit(read) 
      Serial.println(TWSR,BIN);
      TWI_read_slave(); // Function to read data
   Serial.println(TWSR,BIN);
   Serial.println(a);
   
     
     Serial.println("POLKUJ");
  Serial.println(TWSR,BIN);   
write_data=~recv_data; // Togglem the receive data
 
TWI_match_write_slave(); //Function to match the slave address and slave dirction bit(write) 
TWI_write_slave('xyz');       // Function to write data
}
}
 
void TWI_init_slave(void) // Function to initilaize slave
{
TWAR=0x20; // Fill slave address to TWAR
}
 
void TWI_write_slave(uint8_t data) // Function to write data
{
TWDR= data;           // Fill TWDR register whith the data to be sent 
//Serial.println(11111111);
TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag 
while((TWSR & 0xF8) != 0xC0); // Wait for the acknowledgement
}
 
void TWI_match_write_slave(void) //Function to match the slave address and slave dirction bit(write) 
{
while((TWSR & 0xF8)!= 0xA8) // Loop till correct acknoledgement have been received
{
// Get acknowlegement, Enable TWI, Clear TWI interrupt flag
TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT); 
while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
}
}
 
void TWI_read_slave(void)
{  
//    Serial.println("receive");   
//    Serial.println(TWCR,BIN);
//    Serial.println(TWSR,BIN);
// Clear TWI interrupt flag,Get acknowlegement, Enable TWI
TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
//      Serial.println(TWCR,BIN);
//     Serial.println(TWSR,BIN); 
while (!(TWCR & (1<<TWINT))); // Wait for TWINT flag
//   Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
while((TWSR & 0xF8)!=0x80); // Wait for acknowledgement
//   Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
recv_data=TWDR; // Get value from TWDR
Serial.println(recv_data); // send the receive value on PORTB

//if((TWSR & 0xF8)==0x80)
//return 0;   // stay inside do while loop
//else return 1;    // come out from do while loop

}
 
void TWI_match_read_slave(void) //Function to match the slave address and slave dirction bit(read)
{  //Serial.println("jlk");
//   Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknoledgement have been received
{  
//  Serial.println("while");
//     Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
// Get acknowlegement, Enable TWI, Clear TWI interrupt flag
TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT); 
//   Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
//   Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
}
//Serial.println(TWCR,BIN);
//   Serial.println(TWSR,BIN);
}

/*
 uint8_t i2c_readReg( uint8_t* data, uint16_t length)
{
 

  for (uint16_t i = 0; i < (length-1); i++)
  {
    data[i] = TWI_read_slave();
  }
  data[(length-1)] = TWI_read_slave();

  return 0;
}
*/
 
