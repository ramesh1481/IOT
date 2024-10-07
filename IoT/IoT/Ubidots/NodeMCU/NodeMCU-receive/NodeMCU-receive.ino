 /*
 * Title  - IoT Code for NodeMCU - Ubidots recieve code
 * Author - Vijay B
 * Date   - 15/06/2024
 */

#include "Ubidots.h"              //library for ubidots for esp8266 & nodemcu
const char* UBIDOTS_TOKEN = "BBUS-LfiFtZZ5zoP0PbaEvMVho6Pov8WngR";            // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Firmware";                                           // Put here your Wi-Fi SSID
const char* WIFI_PASS = "Solutions@12345";                                    // Put here your Wi-Fi password
const char* DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM = "your device";             // Replace with your device label
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM1 = "variable id1";         // Replace with your variable label
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM2 = "variable id2";         // Replace with your variable label
const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM3 = "variable id3";         // Replace with your variable label
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);                                     //HTTP protocol

//Arduino setup function
void setup() {
  Serial.begin(9600);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);                                  //WiFi get Connected here
  // ubidots.setDebug(true); //Uncomment this line for printing debug messages
}

// Arduino Main Function
void loop() {

  //Create variable to store data from iot variables
  int value1 = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM1);  //Store first variable from Iot
  int value2 = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM2);  //Store second variable from Iot
  int value3 = ubidots.get(DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM, VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM3);  //Store third variable from Iot
}
