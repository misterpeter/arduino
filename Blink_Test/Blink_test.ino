/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led_green = 10;
int led_orange = 11;
int led_red = 12;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_red, OUTPUT);
  
  //Serial.begin(9600);           // set up Serial library at 9600 bps   
}

// the loop routine runs over and over again forever:
void loop() {
  
  digitalWrite(led_green, HIGH);
  delay(100);               
  digitalWrite(led_green, LOW);   
  delay(100);
  
  digitalWrite(led_orange, HIGH);  
  delay(100);               
  digitalWrite(led_orange, LOW);
  delay(100);  
  
  digitalWrite(led_red, HIGH);
  delay(100);               
  digitalWrite(led_red, LOW);   
  delay(100);
   
  //Serial.println("Hello world!");  // prints hello with ending line break
  //delay(1000);
}
