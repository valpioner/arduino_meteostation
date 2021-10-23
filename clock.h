#include <microDS3231.h>
MicroDS3231 rtc;

void initClock() {
  // проверка наличия модуля на линии i2c
  // вызов rtc.begin() не обязателен для работы
  if (!rtc.begin()) {
    Serial.println("DS3231 not found");
    for(;;);
  }

  if (rtc.lostPower()) {            // выполнится при сбросе батарейки
    Serial.println("lost power!");
    // тут можно однократно установить время == времени компиляции
  }

  Serial.print(rtc.getTimeString());
  Serial.println(" - Clock initialized");
  Serial.println();
}

  /* rtc API: 

    DateTime now = rtc.getTime();
    rtc.setTime(now);

    rtc.getHours()    now.hour
    rtc.getMinutes()  now.minute
    rtc.getSeconds()  now.second
    rtc.getDay()      now.day
    rtc.getDate()     now.date
    rtc.getMonth()    now.month
    rtc.getYear()     now.year


    rtc.getTemperatureFloat()   // вывод температуры чипа
    rtc.getTimeString()         // вывод времени готовой строкой String
    rtc.getDateString()         // вывод даты готовой строкой String


    // вывод времени через char array
    char time[8];
    rtc.getTimeChar(time);
    Serial.println(time);


    // вывод даты через char array
    char date[10];
    rtc.getDateChar(date);
    Serial.println(date);
    

    // ======== УСТАНОВКА ВРЕМЕНИ АВТОМАТИЧЕСКИ ========
    // rtc.setTime(COMPILE_TIME);     // установить время == времени компиляции
    // визуально громоздкий, но более "лёгкий" с точки зрения памяти способ установить время компиляции
    // rtc.setTime(BUILD_SEC, BUILD_MIN, BUILD_HOUR, BUILD_DAY, BUILD_MONTH, BUILD_YEAR);

    // ======== УСТАНОВКА ВРЕМЕНИ ВРУЧНУЮ ========    
    // установить время вручную можно двумя способами (подставить реальные числа)
    //rtc.setTime(SEC, MIN, HOUR, DAY, MONTH, YEAR);
    //rtc.setHMSDMY(HOUR, MIN, SEC, DAY, MONTH, YEAR);
  */
