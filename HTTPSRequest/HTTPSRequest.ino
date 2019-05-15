/*
    HTTP over TLS (HTTPS) example sketch

    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp8266/Arduino project continuous integration
    build.

    Limitations:
      only RSA certificates
      no support of Perfect Forward Secrecy (PFS)
      TLSv1.2 is supported since version 2.4.0-rc1

    Created by Ivan Grokhotkov, 2015.
    This example is in public domain.
*/

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#ifndef STASSID
#define STASSID "Merchant24G"
#define STAPSK  "Masumeen14"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "myasir.ca";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char fingerprint[] PROGMEM = "7A F4 D8 FD 54 6B 33 75 8A DD D5 AD 17 E5 53 A5 9C 8F B0 6A";

void setup() 
{
  pinMode(2, OUTPUT);
//  pinMode(9, OUTPUT);

//  digitalWrite(3, LOW);
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
//
//  // Use WiFiClientSecure class to create TLS connection
//  WiFiClientSecure client;
//  Serial.print("connecting to ");
//  Serial.println(host);
//
//  Serial.printf("Using fingerprint '%s'\n", fingerprint);
//  client.setFingerprint(fingerprint);
//
//  if (!client.connect(host, httpsPort)) {
//    Serial.println("connection failed");
//    return;
//  }
//
//  String url = "/api/api.php?temp=24&humidity=35";
//  Serial.print("requesting URL: ");
//  Serial.println(url);
//
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" +
//               "User-Agent: BuildFailureDetectorESP8266\r\n" +
//               "Connection: close\r\n\r\n");
//
//  Serial.println("request sent");
//  while (client.connected()) {
//    String line = client.readStringUntil('\n');
//    if (line == "\r") {
//      Serial.println("headers received");
//      break;
//    }
//  }
//  String line = client.readStringUntil('\n');
//  if (line.startsWith("{\"state\":\"success\"")) {
//    Serial.println("esp8266/Arduino CI successfull!");
//  } else {
//    Serial.println("esp8266/Arduino CI has failed");
//  }
//  Serial.println("reply was:");
//  Serial.println("==========");
//  Serial.println(line);
//  Serial.println("==========");
//  Serial.println("closing connection");
}

void loop() 
{
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
}
