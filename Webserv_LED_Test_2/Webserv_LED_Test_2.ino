#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0x09, 0xFE };
IPAddress ip(192,168,2,127);
EthernetServer server(80);

String HTTP_req;          // stores the HTTP request
boolean LED2_status = 0;   // state of LED, off by default
boolean LED3_status = 0;
boolean LED4_status = 0;

void setup()
{
    Ethernet.begin(mac, ip);  // initialize Ethernet device
    server.begin();           // start to listen for clients
    Serial.begin(9600);       // for diagnostics
    pinMode(2, OUTPUT);       // LED on pin 2
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop()
{
    EthernetClient client = server.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                HTTP_req += c;  // save the HTTP request 1 char at a time
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<head>");
                    client.println("<title>Arduino LED Control</title>");
                    client.println("</head>");
                    client.println("<body>");
                    client.println("<h1>LED</h1>");
                    client.println("<p>Click to switch LED on and off.</p>");
                    client.println("<form method=\"get\">");
                    ProcessCheckbox1(client);                    
                    client.println("</form>");
                    client.println("<form method=\"get\">");
                    ProcessCheckbox2(client);                    
                    client.println("</form>");
                    client.println("<form method=\"get\">");
                    ProcessCheckbox3(client);                    
                    client.println("</form>");
                    client.println("</body>");
                    client.println("</html>");
                    Serial.print(HTTP_req);
                    HTTP_req = "";    // finished with request, empty string
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}

// switch LED and send back HTML for LED checkbox
void ProcessCheckbox1(EthernetClient cl)
{
    if (HTTP_req.indexOf("LED2=2") > -1) {  // see if checkbox was clicked
        // the checkbox was clicked, toggle the LED
        if (LED2_status) {
            LED2_status = 0;
        }
        else {
            LED2_status = 1;
        }
    }
    
    if (LED2_status) {    // switch LED on
        digitalWrite(2, HIGH);
        // checkbox is checked
        cl.println("<input type=\"checkbox\" name=\"LED2\" value=\"2\" \
        onclick=\"submit();\" checked>LED2");
    }
    else {              // switch LED off
        digitalWrite(2, LOW);
        // checkbox is unchecked
        cl.println("<input type=\"checkbox\" name=\"LED2\" value=\"2\" \
        onclick=\"submit();\">LED2");
    }
}    

void ProcessCheckbox2(EthernetClient cl)
{
    
    if (HTTP_req.indexOf("LED3=3") > -1) {  // see if checkbox was clicked
        // the checkbox was clicked, toggle the LED
        if (LED3_status) {
            LED3_status = 0;
        }
        else {
            LED3_status = 1;
        }
    }
    
    if (LED3_status) {    // switch LED on
        digitalWrite(3, HIGH);
        // checkbox is checked
        cl.println("<input type=\"checkbox\" name=\"LED3\" value=\"3\" \
        onclick=\"submit();\" checked>LED3");
    }
    else {              // switch LED off
        digitalWrite(3, LOW);
        // checkbox is unchecked
        cl.println("<input type=\"checkbox\" name=\"LED3\" value=\"3\" \
        onclick=\"submit();\">LED3");
    }
    
}
    
void ProcessCheckbox3(EthernetClient cl)
{
    
    if (HTTP_req.indexOf("LED4=4") > -1) {  // see if checkbox was clicked
        // the checkbox was clicked, toggle the LED
        if (LED4_status) {
            LED4_status = 0;
        }
        else {
            LED4_status = 1;
        }
    }
    
    if (LED4_status) {    // switch LED on
        digitalWrite(4, HIGH);
        // checkbox is checked
        cl.println("<input type=\"checkbox\" name=\"LED4\" value=\"4\" \
        onclick=\"submit();\" checked>LED4");
    }
    else {              // switch LED off
        digitalWrite(4, LOW);
        // checkbox is unchecked
        cl.println("<input type=\"checkbox\" name=\"LED4\" value=\"4\" \
        onclick=\"submit();\">LED4");
    }
}
