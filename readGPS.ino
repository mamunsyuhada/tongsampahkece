void readGPS() {
  Serial.println("Read GPS");
  gps.f_get_position(&latitude, &longitude); // lintang, bujur
  saveLatitude = latitude;
  saveLongitude = longitude;
  gpslat = String(latitude, 7);
  gpslon = String(longitude, 7);
  smartdelay(1000);
  Serial.println(gpslat);
  Serial.println(gpslon);
}

void smartdelay(unsigned long ms) {
  unsigned long start = millis();
  do
  {
    while (gpsSerial.available())
      gps.encode(gpsSerial.read());
  } while (millis() - start < ms);
}
