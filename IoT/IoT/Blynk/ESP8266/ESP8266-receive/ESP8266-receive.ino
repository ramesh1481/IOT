  // Include the library files
  #define BLYNK_TEMPLATE_ID "TMPL3wkIDWRE6"
  #define BLYNK_TEMPLATE_NAME "Online Remote"
  #define BLYNK_AUTH_TOKEN "YKT2L8CNTFo5OqvAa9O0rznnfzxlfG5d"
  #define BLYNK_PRINT Serial // Library for Blynk
  #include <ESP8266WiFi.h>   // Library for Wi-Fi configuration
  #include <BlynkSimpleEsp8266.h> // Library for simple coding interface on Blynk
  char auth[] = BLYNK_AUTH_TOKEN;
  char ssid[] = "anandh"; // Enter your WIFI name
  char pass[] = "123456789"; // Enter your WIFI password
  int data=0;    //variable to store data from virtaul pin

  //funciton to get data from particular virtaulpin
  BLYNK_WRITE(V0) {
    data = param.asInt();         //store data from virtual pin to data variable
  }


// Arduino setup function
void setup() {
  Serial.begin(9600);                                 //Start Serial Communication here
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);   //Wifi connected and device connected to blynk here
}


// Arduino main function
void loop() {
  Blynk.run();
  Serial.println(data);
}
