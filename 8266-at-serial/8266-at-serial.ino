#include<SoftwareSerial.h>
//#include<iom328p.h>
char rec[100];
int i=0;
int x=0;
int m=0;
//int c[15]='kunal gupta';
SoftwareSerial esp(2,3);//rx,tx
void atresponse()
{
  memset(rec,'\0',100);
  Serial.println(Serial1.available());
  while(Serial1.available()>0)
 {
  i++;
 //Serial.println(esp.available());
 //Serial.println("receiving command");
  rec[x] =Serial1.read();
  x++;
 //Serial.println("rc");
 //Serial.print(rec[x]); 
 //delay(1000);
 }
 Serial.println(rec);
}

void atnochar()
{
  delay(1000);
Serial.println(" number of characters ");
 Serial.print(i);
 i=0;
 Serial.println(" response is ");
 Serial.println(rec);
}
void atcommand(char *buff)
{
  Serial1.print(buff);
  Serial.print("Command send : ");
  Serial.println(buff);
  atresponse();
  //atnochar();
  //rec[100]="";
  delay(1000);
}
void setup() 
{  Serial1.begin(115200);
  Serial.begin(9600);
  Serial.print("kunal gupta \r\n");
  Serial.println("kunal gupta \n");
  Serial.println("kunal gupta\r");

  // put your setup code here, to run once:

}

void loop()
{
  while(m<1)
  {
//atcommand("AT+CIPSTATUS\r\n");
//atcommand("AT+CIPSTATUS?\r\n");
//delay(2000);
atcommand("AT+CWLAP?\r\n");

atcommand("AT+CIPSTART=\"TCP\",\"api.openweathermap.org\",80\r\n");
atcommand("AT+CIPSEND=70\r\n");
atcommand("GET /data/2.5/weather?q=delhi&appid=885e9149105e8901c9809ac018ce8658\r\n");
m++;
}

}
