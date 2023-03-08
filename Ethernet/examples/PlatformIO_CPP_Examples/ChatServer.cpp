/*
 Chat Server

 A simple server that distributes any incoming messages to all
 connected clients.  To use, telnet to your device's IP address and type.
 You can see the client's input in the serial monitor as well.
 Using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 */

#include <Arduino.h>
#include "Ethernet.h"
#include "HardwareSerial.h"

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
// gateway and subnet are optional:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 11, 111);
IPAddress myDns(192, 168, 11, 1);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 0, 0);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(5000);

uint8_t alreadyConnected = false; // whether or not the client was connected previously
void setup() {
  //For Serial output
  Serial3.setRx(PC11);
  Serial3.setTx(PC10);
  delay(50);
  Serial3.begin(9600);

  // Open serial communications and wait for port to open:
  while (!Serial3) {
   ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial3.println("Ethernet ChatServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial3.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }

  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start listening for clients
  server.begin();

  Serial3.print("Chat server address:");
  Serial3.println(Ethernet.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      // clear out the input buffer:
      client.flush();
      Serial3.printf("We have a new client\n");
      //client.println("Hello, client!");
      alreadyConnected = true;
    }

    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();
      //Serial3.printf("client read() -->>> %c\r\n", thisChar);
      // echo the bytes back to the client:
      //client.write(thisChar);
      server.write(thisChar);
      // echo the bytes to the server as well:
      Serial3.write(thisChar);
    }
  }
}