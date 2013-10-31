int timer = 80;

void setup() {
 for (int thisPin = 1; thisPin <= 7; thisPin++) {
 pinMode(thisPin,OUTPUT);
 }   
}

void loop() {
  
  for (int thisPin = 1; thisPin <= 7; thisPin++) {
   digitalWrite(thisPin, HIGH);
   delay(timer);
   digitalWrite(thisPin, LOW);
  }
  
  for (int thisPin = 7; thisPin >= 1; thisPin--) { 
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  } 
}
