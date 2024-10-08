/*
 * Title  - IoT code for esp32 - ubidots receive
 * Author - Vijay B
 * Date   - 15/06/2024
 */
 
#include "Ubidots.h"                                                   // ubidots library 
const char* UBIDOTS_TOKEN = "...";                                     // Put here your Ubidots TOKEN
const char* WIFI_SSID = "...";                                         // Put here your Wi-Fi SSID
const char* WIFI_PASS = "...";                                         // Put here your Wi-Fi password
const char* DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM = "weather-station";  // Replace with your device label
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM = "humidity";       // Replace with your variable label
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true); //Uncomment this line for printing debug messages
}

void loop() {
  /* Obtain last value from a variable as float using HTTP */
  float value = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM);

  // Evaluates the results obtained
  if (value != ERROR_VALUE) {
    Serial.print("Value:");
    Serial.println(value);
  }
  delay(5000);
}
