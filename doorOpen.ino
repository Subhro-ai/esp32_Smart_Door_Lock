#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Debdulal Home";
const char* pass = "Baruna@1975";
const int led = 2;
WebServer server(80);   
void setup() {
  Serial.begin(115200);

  // Initialize the LED pin
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 
  // digitalWrite(led, HIGH);

  server.on("/", HTTP_GET, [](){
    String html = "<h1>ESP32 Web Server</h1>";
    html += "<p><a href='/open'>Turn ON LED</a></p>";
    server.send(200, "text/html", html);
  });

  // Handle the '/open' URL route to turn on the LED
  server.on("/open", HTTP_GET, [](){
    digitalWrite(led, HIGH);  // Turn on the LED
    delay(500);
    digitalWrite(led, LOW);
    server.send(200, "text/html", "<h1>LED is ON</h1><p><a href='/'>Back to Home</a></p>");
  });

  // Start the server
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    server.handleClient();


}
