#define E1 3  // Enable Pin for motor 1
//#define E2 11  // Enable Pin for motor 2
 
#define pos 7  // Control pin 1 for motor 1
#define neg 8  // Control pin 2 for motor 1
//#define I3 12  // Control pin 1 for motor 2
//#define I4 13  // Control pin 2 for motor 2
 int pwm;
void setup() {
 Serial.begin(9600);
    pinMode(E1, OUTPUT);
 
    pinMode(pos, OUTPUT);
    pinMode(neg, OUTPUT);
    
}
 
void loop() {
    //pwm=map(45,20,45,0,1023);
    analogWrite(E1, 255); // Run in half speed
    Serial.print("hellow"); 
  Serial.println(analogRead(E1));
    digitalWrite(pos, HIGH);
    digitalWrite(neg, LOW);
                                                              
                
    delay(1000);
 
    
}
