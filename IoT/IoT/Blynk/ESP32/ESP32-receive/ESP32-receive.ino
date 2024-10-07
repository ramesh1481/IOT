/*
 * Title  - IoT Code for ESP32 - Blynk cloud receive
 * Author - Vijay B 
 * Date   - 15/06/2024
 */

// Library initializations
#define ledpin 2
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3l21v0PCS"
#define BLYNK_TEMPLATE_NAME "anything"
#include <WiFi.h>
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h>
char auth[] = "WpQzOrNC5yqUhw4HvYBG1UEBnXha-zJN"; // Paste your Blynk API authentication token here
char ssid[] = "Firmware";                           // Enter your WiFi SSID here
char pass[] = "Solutions@12345";                       // Enter your WiFi Password here
int data=0;  //variable to store data from blynk cloud
//funciton to get data from particular virtaulpin
  BLYNK_WRITE(V0) {
    data = param.asInt();
    
    if(data==1)
    {
      digitalWrite(ledpin,HIGH);
    }
    else
    {
      digitalWrite(ledpin,LOW);
    }         //store data from virtual pin to data variable
  }

  
// Arduino setup function
void setup() 
{
  Serial.begin(115200);                           // Start Serial Communication
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); // WiFi and Blynk cloud connected here
}

// Arduino main function
void loop() { 
  Blynk.run();                                    // Blynk function
  Serial.println(data);
}
