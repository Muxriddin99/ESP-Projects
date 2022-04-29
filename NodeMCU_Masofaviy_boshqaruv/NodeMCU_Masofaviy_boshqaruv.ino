//https://github.com/Muxriddin99/ESP-Projects
//26.04.2022 
//NodeMCU yordamida masofaviy boshqaruv 

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
String command;    
const char* ssid = "";//ixtiyoriy nom qo'yish mumkun
const char* s = "";//ixtiyoriy parol
ESP8266WebServer server(80);

char temp[400];
void handleRoot() 
{
  snprintf(temp, 400,
"<html>\
    <body>\ 
       <h1>Boshqaruv oynasi</h1>\
       <a href =\"/1\"> <button style=\"/font-family:century gothic;color:White;font-size:40px;background-color:#195B6A;\">Yoqish</button></a>\
       <a href =\"/0\"> <button style=\"/font-family:century gothic;color:White;font-size:40px;background-color:#77878A;\">O'chirish</button></a>\
       </body>\
</html>");
  server.send(200, "text/html", temp);
}
void ledOn() 
{
  pinMode(D2, OUTPUT);//chiroq ulangan oyoqcha raqami
  digitalWrite(D2, HIGH);
  delay(1000);
  server.send(200, "text/html", temp);
}

void ledOff() 
{
  pinMode(D2, OUTPUT);
  digitalWrite(D2, LOW);
  delay(1000);
  server.send(200, "text/html", temp);
}

void setup() {
  Serial.begin(115200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,s);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  server.on ( "/", handleRoot );    
  server.on("/", handleRoot);
  server.on("/0", ledOff);
  server.on("/1", ledOn);
  server.begin();
}
void loop(void) {
      server.handleClient();
      command = server.arg("State");
}
void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
