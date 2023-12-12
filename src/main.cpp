#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebSrv.h>

const char* ssid = "Superonlineeren";
const char* password = "fasulye98";

AsyncWebServer server(80);

String greeting = "Hello, World!";

void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/plain", greeting);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("Connected to the WiFi network");

  server.on("/", HTTP_GET, handleRoot);
  server.begin();
  Serial.println("Server started");
}

void loop() {
}
