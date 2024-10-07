/*
 * Title  - IoT Code for NodeMCU - Ubidots http network protocol
 * Author - Vijay B
 * Date   - 15/06/2024
 */

#include "Ubidots.h"  // library for ubidots esp8266 and nodemcu 
const char* UBIDOTS_TOKEN = "BBUS-Qk9w8nxF5Ilj51g3o2xo0WhiSoaslv";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Firmware";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "Solutions@12345";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);       //HTTP protocol used

//Arduino setup function
void setup() {
  Serial.begin(9600);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);    // WiFi Connection Initialization
}

//Arduino main function
void loop() {
    int val1,val2,val3; //variables to send data
   // below lines are crucial for send data to ubidots
    ubidots.add("data1", val1.toInt());           // in this line ubidots.add( variable name , data to be stored ) .toInt() means typecast data into integer
    ubidots.add("data2", val2.toFloat());         //.toFloat() means typecast data into float
    ubidots.add("data3", val3.toInt());
    bool bufferSent = false;
    bufferSent = ubidots.send(); 
    delay(500);
}
 
