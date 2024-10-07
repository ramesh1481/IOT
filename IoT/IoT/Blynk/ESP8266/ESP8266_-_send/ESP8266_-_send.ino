  /*
   * Title  - IoT Code for ESP8266  - Blynk IoT 
   * Author - Vijay B
   * Date   - 15/06/2024
   */
  
  //define Authentications from blynk
  #define BLYNK_TEMPLATE_ID "TMPL3RVTtsiZ-"
  #define BLYNK_TEMPLATE_NAME "Smart Dustbin"
  #define BLYNK_AUTH_TOKEN "PrkdERaYCiSTaB4f4Q_6-suv5v3WGuAu"
  #define BLYNK_PRINT Serial                             //library for blynk 
  #include <ESP8266WiFi.h>                               //library for Wi-Fi Configure
  #include <BlynkSimpleEsp8266.h>                        //library for simple coding interface on blynk  
  // Connection Configuration
  char auth[] = BLYNK_AUTH_TOKEN;
  char ssid[] = "Iot";                                   //Enter your WIFI name
  char pass[] = "iot12345";                              //Enter your WIFI password
  BlynkTimer timer;                                      //Timer function

  //user defined function for send data to iot using timer
  void sendSensor()
  {
    //read serial data from uart from other microcontrollers
    if (Serial.available() > 0)
  {
   String myString = Serial.readString();                 //store serial data as sttring
   String val1=  getValue(myString, ':', 0);              //split string and store first data to variable
   String val2=  getValue(myString, ':', 1);              //split string and store second data to variable
   String val3=  getValue(myString, ':', 2);              //split string and store third data to variable
    Blynk.virtualWrite(V0, val1.toInt()) ;                  //Assign first val1 to Virtual pin 0                   
    Blynk.virtualWrite(V1, val2.toFloat());               //Assign second val2 to Virtual pin 1    
    Blynk.virtualWrite(V2, val3.toInt());                 //Assign third val3 to Virtual pin 2    
  }
  }

// Arduino setup function
void setup() {
  Serial.begin(9600);
  timer.setInterval(1L, sendSensor);
  //Initialize Blynk function from library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);       //WiFi get Connected here to Blynk cloud
}


//Arduino main funciton
void loop() {
  Blynk.run();                                           //run blynk instructions
  timer.run();                                           //Timer function runs looped here
}

//function to split a string using character seperator
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
