#include <SoftwareSerial.h>
#include <TinyGPS.h>
TinyGPS gps;
SoftwareSerial gpsSerial(D8, D7);
float saveLatitude, saveLongitude;
float latitude, longitude;
String gpslat, gpslon;

#include <Ultrasonic.h>
Ultrasonic srf1(D1, D2);  // organik
Ultrasonic srf2(D3, D4);  // logam
Ultrasonic srf3(D5, D6);  // anorganik
String organik, logam, anorganik;

#include <ESP8266WiFi.h>

String apiKey = "XTC0LN7OONPM4QSF";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "rambutanph";     // replace with your wifi ssid and wpa2 key
const char *pass =  "ahmadpikni";
const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  Serial.begin(115200);

  Serial.println("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  gpsSerial.begin(9600); //gpsInit
  //  readGPS();
  //  while (saveLatitude == 1000 || saveLongitude == 1000) // ok
  //  {
  //    Serial.println("GPS Belum Konek");
  //    readGPS();
  //  }
}

void loop() {
  /*GPS*/
  readGPS();
  /*srf*/
  srf();
  /*kirim data ke thingspeak*/
  thingspeak();
}
