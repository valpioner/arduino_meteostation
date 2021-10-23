#include <GyverBME280.h>
 
GyverBME280 bme;           
 
void initBME280()
{ 
  bme.begin();
  if (!bme.begin(0x76)) Serial.println("Error: BME280 was not found at 0x76");
}
 
void logBME280()
{  
  Serial.print("BME Temperature: ");
  Serial.print(bme.readTemperature());        // Выводим темперутуру в [*C]
  Serial.println(" *C");

  Serial.print("BME Humidity: ");
  Serial.print(bme.readHumidity());           // Выводим влажность в [%]
  Serial.println(" %");

  float pressure = bme.readPressure();        // Читаем давление в [Па]
  Serial.print("BME Pressure: ");
  Serial.print(pressure / 100.0F);            // Выводим давление в [гПа]
  Serial.print(" hPa , ");
  Serial.print(pressureToMmHg(pressure));     // Выводим давление в [мм рт. столба]
  Serial.println(" mm Hg");
  Serial.print("BME Altitude: ");
  Serial.print(pressureToAltitude(pressure)); // Выводим высоту в [м над ур. моря]
  Serial.println(" m");
  Serial.println();
}
