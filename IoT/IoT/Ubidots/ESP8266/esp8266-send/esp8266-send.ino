/*
 * Title  - IoT Code for ESP8266 - Ubidots http network protocol
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
 //receive serial(uart) data from other controllers like arduino,stm32,pic,8051
 if (Serial.available() > 0)
  {
   String myString = Serial.readString();         //store uart serial data to myString variable
   String val1=  getValue(myString, ':', 0);      //store first data by split function
   String val2=  getValue(myString, ':', 1);      //store second data by split function
   String val3=  getValue(myString, ':', 2);      //store third data by split function

   // below lines are crucial for send data to ubidots
    ubidots.add("data1", val1.toInt());           // in this line ubidots.add( variable name , data to be stored ) .toInt() means typecast data into integer
    ubidots.add("data2", val2.toFloat());         //.toFloat() means typecast data into float
    ubidots.add("data3", val3.toInt());
    bool bufferSent = false;
    bufferSent = ubidots.send(); 
    delay(500);
}
}

// function to split up string data as per the character seperator (like - ':')
 String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
} 
