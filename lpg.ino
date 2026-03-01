#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "TECNO";
const char* password = "fathima 29";

//Ultrasonic sensor pins
#define TRIG_PIN 5
#define ECHO_PIN 18
//LED pins
#define RED_LED 19
#define YELLOW_LED 21
#define GREEN_LED 22
#define BUZZER 23

// Distance thresholds (cm)
float thresholdRed = 9.0;
float thresholdYellow = 5.0;
float thresholdEmpty = 12.0;

long duration;
float distance;
String gasStatus = "Unknown";

// Web server on port 80
WebServer server(80);

// ----- Function to Measure Distance -----
void measureDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);  // 30ms timeout

  if (duration == 0) {
    gasStatus = "ERROR";
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW);
    return;
  }

  distance = duration * 0.034 / 2;

  // LOGIC BASED ON DISTANCE
if(distance >= thresholdEmpty) {
  // Empty
    gasStatus = "Empty";
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
}
  else if(distance > thresholdRed && distance < thresholdEmpty) {
  // Low
  gasStatus = "LOW";
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BUZZER, LOW);
}
   
  else if(distance >= thresholdYellow && distance < thresholdRed) {
  // Medium
    gasStatus = "MEDIUM";
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
}
  else {
  // Full
    gasStatus = "HIGH";
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
}

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Status: ");
  Serial.println(gasStatus);
}

//----- HTML Page -----

String HTMLPage() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<title>Smart LPG Monitor</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>body{font-family:Arial;text-align:center;padding:20px;} ";
  html += ".status{font-size:30px;font-weight:bold;margin:20px;} ";
  html += ".distance{font-size:20px;} ";
  html += "</style></head><body>";
  html += "<h1>Smart LPG Cylinder Status</h1>";
  html += "<div class='status'>Status: " + gasStatus + "</div>";
  html += "<div class='distance'>Distance: " + String(distance) + " cm</div>";
  html += "<script>";
  html += "setTimeout(function(){ location.reload(); }, 1000);"; // Auto-refresh every 1s
  html += "</script>";
  html += "</body></html>";
  return html;
}


// ----- Handle Root -----
void handleRoot() {
  measureDistance();           // Update measurement before sending page
  server.send(200, "text/html", HTMLPage());
}

// ----- Setup -----
void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected! IP: " + WiFi.localIP().toString());

  // Start server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

// ----- Loop -----
void loop() {
  server.handleClient();
}
