#include "clock.h"            // MicroDS3231 rtc;
#include "lcd.h"              // LiquidCrystal_I2C lcd
#include "sensor_bme280.h"    // BME280 sensor
#include "sensor_htu21d.h"    // HTU21D sensor
#include "sensor_dht22.h"     // DHT22 sensor

#define SOME_PIN 13



void setup() {
  Serial.begin(9600);

  initClock();
  initLCD();

  initBME280(); // Temp + Pressure
  initHTU21D(); // Temp + Humidity
  initDHT22(); // Temp + Humidity
}

void loop() {
  setInterval(&updateOutput, 1000);
}

void updateOutput(){
  updateDisplay();
  
  Serial.println(rtc.getTimeString());
  logBME280();
  logHTU21D();
  logDHT22();
  Serial.println();
}

void updateDisplay(){
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeString());
  
  lcd.setCursor(0, 1);
  lcd.print(bme.readTemperature());
  lcd.setCursor(6, 1);
  lcd.print("*C");  
}

void setInterval(void (*cb)(), int interval) {
    static const unsigned long REFRESH_INTERVAL = interval; // ms
    static unsigned long lastRefreshTime = 0;

    if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
    {
        lastRefreshTime += REFRESH_INTERVAL;
        (*cb)();
    }
}
