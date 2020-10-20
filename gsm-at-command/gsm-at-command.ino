char phone_no[]="9654066928";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(2000);
Serial.println("AT");
Serial.print("ATD");
Serial.print(phone_no);
Serial.println(";");
delay(10000);
Serial.println("ATH");
}


void loop() {
  // put your main code here, to run repeatedly:
}
