#include <Arduino.h>

#include <ESP8266WiFi.h>
// #include <WiFiClient.h>

const char *wifiSSID = "Orang";
const char *wifiPASS = "lenina2431";

WiFiEventHandler gotIpEventHandler, disconnectedEventHandler;

bool ledState;

void setup()
{

  Serial.begin(9600);

  pinMode(D1, OUTPUT);

  Serial.println();
  Serial.println("DEMO");

  gotIpEventHandler = WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP &event)
                                              {
    Serial.print("Station connected, IP: ");
    Serial.println(WiFi.localIP()); 
    
    // выводим диагностическую инфу про сеть
    WiFi.printDiag(Serial);
    // Serial.println("Prohod 2222");
    
    });

  disconnectedEventHandler =
   WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected &event)
                                                            {
                                                              Serial.println("Station disconnected");
                                                            });

  Serial.printf("Connecting to %s ...\n", wifiSSID);
  WiFi.begin(wifiSSID, wifiPASS);





//  Serial.println("Prohod");
  

  // WiFi.mode(WIFI_AP_STA);
  // WiFi.begin(wifiSSID, wifiPASS);
  // Serial.print("Connections to Wi-Fi AP ");
  // Serial.print(wifiSSID);
  // Serial.print(" ");

  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   Serial.print(".");
  //   delay(500);
  // };

  // Serial.println(" ok");
  // Serial.print("WiFi connected, obtained IP address: ");
  // Serial.print(WiFi.localIP());
}

void loop()
{
   
  digitalWrite(D1, ledState);
  ledState = !ledState;
  delay(250);
}
