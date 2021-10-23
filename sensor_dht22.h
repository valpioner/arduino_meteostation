// http://edurobots.ru/2015/02/arduino-dlya-nachinayushhix-urok-9-podklyuchenie-datchika-temperatury-i-vlazhnosti-dht11-i-dht22/

#include "DHT.h"

#define DHTPIN 2 // номер пина, к которому подсоединен датчик

// Раскомментируйте в соответствии с используемым датчиком
// Инициируем датчик

DHT dht(DHTPIN, DHT22);
//DHT dht(DHTPIN, DHT11);

void initDHT22() {
  dht.begin();
}

void logDHT22() {
  float humd = dht.readHumidity();
  float temp = dht.readTemperature();
  
  // Проверка удачно прошло ли считывание.
  if (isnan(humd) || isnan(temp)) {
    Serial.println("ERROR: Can't read DHT22 values");
    return;
  }

  Serial.print("DHT Temperature: ");
  Serial.print(temp);
  Serial.println(" *C ");
  Serial.print("DHT Humidity: ");
  Serial.print(humd);
  Serial.print(" %\t");
  Serial.println();
}
