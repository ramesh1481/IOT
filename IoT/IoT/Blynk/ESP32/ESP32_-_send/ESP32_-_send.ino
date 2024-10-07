/*
 * Title  - IoT Code for ESP32 - Blynk cloud send
 * Author - Vijay B 
 * Date   - 15/06/2024
 */

// Library initializations
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h>
char auth[] = "2GjgAHAWqRqq9VYXbMTzihpM9vsR_Lku"; // Paste your Blynk API authentication token here
char ssid[] = "Rajesh";                           // Enter your WiFi SSID here
char pass[] = "rajesh1810";                       // Enter your WiFi Password here
BlynkTimer timer;                                 // Timer function initialization

// Timer function to send data to IoT
void myTimer() {
  int data = 0;
  Blynk.virtualWrite(V0, data);                   // Assign data to Virtual pin V0
}

// Arduino setup function
void setup() {
  Serial.begin(115200);                           // Start Serial Communication
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); // WiFi and Blynk cloud connected here
  timer.setInterval(1000L, myTimer);              // Callback timer function here, 1000L = 1 second
}

// Arduino main function
void loop() { 
  Blynk.run();                                    // Blynk function
  timer.run();                                    // Timer loop 
}
