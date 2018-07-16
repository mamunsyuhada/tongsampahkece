void srf() {
  Serial.print("Sensor 01: ");
  organik = srf1.distanceRead(CM);
  Serial.print(organik);
  Serial.println("cm");
  Serial.print("Sensor 02: ");
  logam = srf2.distanceRead(CM);
  Serial.print(logam);
  Serial.println("cm");
  Serial.print("Sensor 03: ");
  anorganik = srf3.distanceRead(CM);
  Serial.print(anorganik);
  Serial.println("cm");
}
