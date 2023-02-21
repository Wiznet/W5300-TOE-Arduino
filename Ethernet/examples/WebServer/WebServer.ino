/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi
 
 */

#include <Arduino.h>
#include "Ethernet.h"
#include "HardwareSerial.h"

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 11, 111); //TO use your local IP address bandwidth

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(5000);

void setup() {
  //STM32F429ZI's Serial port changed from default Serial Port
  Serial3.setRx(PC11);
  Serial3.setTx(PC10);  
  delay(50);
  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet
  //Ethernet.init(17);  // WIZnet W5100S-EVB-Pico W5500-EVB-Pico

  // Open serial communications and wait for port to open:
  Serial3.begin(9600);
  while (!Serial3) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial3.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial3.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial3.print("server is at ");
  Serial3.println(Ethernet.localIP());
}

#define USE_BROWSER
#ifdef USE_BROWSER  //using chrome, ms edge, etc. --> http://192.168.11.111:5000
void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial3.println("new client");
    // an http request ends with a blank line
    bool currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial3.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
#else //When test by using Hercules TCP Client
void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial3.println("new client");
    // an http request ends with a blank line
    bool currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        //Serial3.write(c);
        //server.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        //if (c == '\n' && currentLineIsBlank) {
        if (currentLineIsBlank) {
          //send a standard http response header
          server.write("HTTP/1.1 200 OK");
          server.write("Content-Type: text/html");
          server.write("Connection: close");  // the connection will be closed after completion of the response
          server.write("Refresh: 5");  // refresh the page automatically every 5 sec
          server.write({"\n"});
          server.write("<!DOCTYPE HTML>");
          server.write("<html>");          
          //output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel); //anlogRead() is own your function.
            server.write("analog input ");
            server.write(analogChannel);
            server.write(" is ");
            server.write(sensorReading);
            server.write("<br />");            
          }
          server.write("</html>");

          break;
        }

        // if (c == '\n') {
        //   // you're starting a new line
        //   currentLineIsBlank = true;
        // } else if (c != '\r') {
        //   // you've gotten a character on the current line
        //   currentLineIsBlank = false;
        // }

      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial3.println("client disconnected");
  }
}
#endif