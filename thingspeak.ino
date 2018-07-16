void thingspeak() {
  if (client.connect(server, 80)) {

    String data;
    data += "&field1="        + String(organik);
    data += "&field2="        + String(logam);
    data += "&field3="        + String(anorganik);
    data += "&field4="        + String(longitude);
    data += "&field5="        + String(latitude);
    data += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data.length());
    client.print("\n\n");
    client.print(data);
    client.stop();
  }
  delay(5000);
}
