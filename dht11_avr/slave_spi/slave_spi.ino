#ifndef F_CPU
#define F_CPU 16000000UL
#endif
 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <SoftwareSerial.h>
 
#define ACK 0x7E
 
void spi_init_slave (void)



{
    DDRB=(1<<6);                                  //MISO as OUTPUT
    SPCR=(1<<SPE);                                //Enable SPI
}
 
//Function to send and receive data
unsigned char spi_tranceiver (unsigned char data)
{
    SPDR = data;                                  //Load data into buffer
    while(!(SPSR & (1<<SPIF) ));                  //Wait until transmission complete
    return(SPDR);                                 //Return received data
}
 
int main(void)
{     Serial.begin(9600);
    
     spi_init_slave();                             //Initialize slave SPI
     char data, buffer[10];

    while(1)
    {
        
        data = spi_tranceiver(ACK);               //Receive data, send ACK
        itoa(data, buffer, 10);                   //Convert integer into string
        Serial.print(buffer);
    }
}
