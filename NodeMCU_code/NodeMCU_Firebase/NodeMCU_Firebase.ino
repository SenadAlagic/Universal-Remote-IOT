#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

// Set these to run example.
#define FIREBASE_HOST "irremoteiot-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "q97lAwNUMIOBWhFK6zvszMw9sqUkDS4Twp1kIR1q"
#define WIFI_SSID "Senco"                 //provide ssid (wifi name)
#define WIFI_PASSWORD "kucabezbroja0602"  //wifi passwordvoid setup()
void setup()
{
  // Debug console
  Serial.begin(9600);  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WIFI_SSID);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed()) {
    Serial.print(Firebase.error());
  } else {

    Serial.println("Firebase Connected");
  }
}

void loop() {
  delay(1500);
  String poruka=Firebase.getString("hexCode")+",";
  //int poruka=Firebase.getInt("hexCode");
  if(Firebase.getString("hexCode")!="0")
  {
    //Serial.println("HexCode:" + Firebase.getString("hexCode"));

    char* cString = (char*) malloc(sizeof(char)*(poruka.length() + 1));
    poruka.toCharArray(cString, poruka.length() + 1);
    Serial.println(cString);
    Serial.write(cString);
    //Serial.write("Haha,");
    //Serial.write(Firebase.getString("hexCode"));

    Firebase.setString("hexCode", "0");
    // Serial.println("HexCode: "+ poruka);
    // Firebase.setInt("hexCode", 0);
  }
}