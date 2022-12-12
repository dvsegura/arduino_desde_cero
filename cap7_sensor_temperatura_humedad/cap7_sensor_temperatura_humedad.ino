#include <DHT.h>
#include <DHT_U.h>

#define SENSOR 2
int TEMPERATURA;
int HUMEDAD; 

DHT dht(SENSOR, DHT22); //DHT22 O DHT11

/*
Sensor DHT22 
  -> se requiere una resistencia de PULL UP
  -> instalación DHT Sensosr Library y Adafruit Unified Sensor 
*/
void setup() {
  Serial.begin(9600);
  delay(10);
  dht.begin();
}

void loop() {
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();
  Serial.print("TEMPERATURA: ");
  Serial.print(TEMPERATURA);
  Serial.print(" HUMEDAD: ");
  Serial.println(HUMEDAD);
  delay(500);
}
