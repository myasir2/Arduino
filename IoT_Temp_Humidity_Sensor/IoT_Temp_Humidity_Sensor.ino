#include <DHT.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
//#include <LiquidCrystal.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11
#define RED_LED 2
#define GREEN_LED 9

const char *host = "myasir.ca";
const int port = 443;
const char fingerprint[] PROGMEM = "7A F4 D8 FD 54 6B 33 75 8A DD D5 AD 17 E5 53 A5 9C 8F B0 6A";

//const int switchPin = 6;
const char *ssid = "Yasir's iPhone";       
const char *password = "mrflukey"; 

String tempMessage = "Temp: ";
String humidityMessage = "Humidity: ";
float temp = 0.0;
float humidity = 0.0;

bool connectedToWifi = false;

DHT dht(DHT_PIN, DHT_TYPE);
WiFiClientSecure client;
//SoftwareSerial esp8266(RX,TX);
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  connectToWifi();

  dht.begin();
}

void loop()
{
    temp = dht.readTemperature();
    humidity = dht.readHumidity();

    Serial.println("Reading sensor data");
    
    if(!isnan(temp) && !isnan(humidity))
    {
  //    lcd.setCursor(tempMessage.length(), 0);
  //    lcd.print(String(temp) + " *C");
  //
  //    lcd.setCursor(humidityMessage.length(), 1);
  //    lcd.print(String(humidity) + "%");
  
      if(!client.connect(host, port)) 
      {
        Serial.println("connection failed");
    
        delay(1000);

        return;
      }

      Serial.println(String(temp) + " *C");
      Serial.println(String(humidity) + "%");

      String url = "/api/api.php?temp=" + String(temp) + "&humidity=" + String(humidity);
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "User-Agent: BuildFailureDetectorESP8266\r\n" +
                "Connection: close\r\n\r\n");

      Serial.println("request sent");
      while (client.connected()) 
      {
        String line = client.readStringUntil('\n');
        
        if (line == "\r") 
        {
          Serial.println("headers received");
          
          break;
        }
      }

      Serial.println("closing connection");
      
    }

    delay(5000);
}

void connectToWifi()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Setting fingerprint");
  client.setFingerprint(fingerprint);

  connectedToWifi = true;
}

//bool sendCommand(String command, int maxTime, char readReplay[]) 
//{
//  Serial.print(countTrueCommand);
//  Serial.print(". at command => ");
//  Serial.print(command);
//  Serial.print(" ");
//  while(countTimeCommand < (maxTime*1))
//  {
//    esp8266.println(command);
//    
//    if(esp8266.find(readReplay))
//    {
//      return true;
//    }
//  }
//  
//  return false;
//}
