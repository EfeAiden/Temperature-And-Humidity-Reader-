#include "DHTesp.h"

DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(4, DHTesp::DHT22); 
}

void loop() {
  delay(2500);

  TempAndHumidity data = dht.getTempAndHumidity();

  if (isnan(data.temperature)) {
    Serial.println("DHT22 read error");
  } else {
    Serial.print("Temp: ");
    Serial.print(data.temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(data.humidity);
    Serial.println(" %");
  }
}
