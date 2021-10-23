#include <LiquidCrystal_I2C.h>

// адрес дисплея 0x3f или 0x27
// размер дисплея 16x2 (поддерживаются и другие, например 20x4)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void initLCD() {
  lcd.init();           // инициализация
  lcd.clear();          // очистить
  
  lcd.backlight();      // включить подсветку
  //lcd.noBacklight();  // выключить подсветку

  //lcd.setCursor(0, 0);  // установить курсор (x, y)
  //lcd.home();         // установить курсор в (0, 0)
  
  Serial.print(rtc.getTimeString());
  Serial.println(" - LCD initialized");
  Serial.println();
}
