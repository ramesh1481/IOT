/*
 * Title  - IoT Code for ESP32  - Ubidots Send 
 * Author - Vijay B
 * Date   - 15/06/2024
 */


#include "Ubidots.h"                //Library for Ubidots esp32
const char* UBIDOTS_TOKEN = "...";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "...";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "...";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP); // HTTP Protocol

//Arduino setup function
void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);        //WiFi get Connected here
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

//Arduino main function
void loop() {
  
  ubidots.add("Variable_Name_One", var1);  // Change for your variable name here ubidots.add(variable name , Data to be sent)
  ubidots.add("Variable_Name_Two", var2);
  ubidots.add("Variable_Name_Three", var3);

  bool bufferSent = false;
  bufferSent = ubidots.send();  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }
  delay(1000);
}
