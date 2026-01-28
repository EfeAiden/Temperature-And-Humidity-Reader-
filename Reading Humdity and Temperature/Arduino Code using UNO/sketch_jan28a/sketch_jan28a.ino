
#include <DHT.h>

#define DHTPIN 4 
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);




void setup() {
  // put your setup code here, to run once:

 Serial.begin(115200);   // I use Higher because na ESP32
  delay(1000);
  Serial.println("ESP32 DHT22 Room Temperature Monitor");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);


float humidity = dht.readHumidity();
float temperatureC =dht.readTemperature();
float temperatureF =dht.readTemperature(true);

if (isnan(humidity) || isnan(temperatureC)); {
  Serial.println("Failed to read from DHT22 sensor!");
  return;
  
}
Serial.print("Temperature: ");
Serial.print(temperatureC);
Serial.print(" C | ");

Serial.print("Humidity");
Serial.print(humidity);
Serial.print(" %");

}
