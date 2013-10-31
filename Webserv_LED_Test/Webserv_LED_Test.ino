#include <SPI.h>
#include <Ethernet.h>

boolean incoming = 0;
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0x09, 0xFE };
IPAddress ip(192,168,2,127);
EthernetServer server(80);

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  tone(5,100,100);
  delay(150);
  tone(5,140,100);
  delay(150);
  tone(5,180,100);
  delay(150);
  Serial.begin(9600);
}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        
        //reads URL string from $ to first blank space
        if(incoming && c == ' '){ 
          incoming = 0;
        }
        if(c == '$'){ 
          incoming = 1; 
        }
        
        //Checks for the URL string $1 or $2
        if(incoming == 1){          
          if(c == '1'){
            setColor(255, 0, 0);
//            digitalWrite(2, HIGH);
            tone(5,250,100);
          }
          if(c == '2'){
            setColor(0, 0, 0);
//            digitalWrite(2, LOW);
            tone(5,150,100);
            delay(100);
            tone(5,100,100);
          }        
        }
        
        if(incoming == 1){          
          if(c == '3'){
            setColor(0, 255, 0);
//            digitalWrite(3, HIGH);
            tone(5,250,100);
          }
          if(c == '4'){
            setColor(0, 0, 0);
//            digitalWrite(3, LOW);
            tone(5,150,100);
            delay(100);
            tone(5,100,100);
          }        
        }
        
        if(incoming == 1){          
          if(c == '5'){
            setColor(0, 0, 255);
//            digitalWrite(4, HIGH);
            tone(5,250,100);
          }
          if(c == '6'){
            setColor(0, 0, 0);
//            digitalWrite(4, LOW);
            tone(5,150,100);
            delay(100);
            tone(5,100,100);
          }        
        }

        if (c == '\n' && currentLineIsBlank) 
        { 
         // send a standard http response header 
          client.println("HTTP/1.1 200 OK"); 
          client.println("Content-Type: text/html"); 
          client.println("Connnection: close"); 
          client.println(); 
          client.println(""); 
          client.println(""); 
          client.println(""); 
          client.println(""); 
          currentLineIsBlank = true; 
          break; 
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(2, red);
  analogWrite(3, green);
  analogWrite(4, blue);
}

