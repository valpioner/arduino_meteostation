#include "SparkFunHTU21D.h"

HTU21D htu;

void initHTU21D() {
  htu.begin();
}

void logHTU21D()
{
  float humd = htu.readHumidity();
  float temp = htu.readTemperature();
  
  Serial.print("HTU Temperature: ");
  Serial.print(temp, 1);
  Serial.println(" *C");
  
  Serial.print("HTU Humidity: ");
  Serial.print(humd, 1);
  Serial.println(" %");
  Serial.println();
}
