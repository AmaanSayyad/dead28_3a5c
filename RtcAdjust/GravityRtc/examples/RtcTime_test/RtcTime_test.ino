#include "GravityRtc.h"
#include "Wire.h"  


GravityRtc rtc;     //RTC Initialization

void setup() {
  Serial.begin(9600);
  rtc.setup();

}

void loop() {
  rtc.update();
  //*************************Time********************************
  Serial.print("   Year = ");//year
  Serial.print(rtc.year);
  Serial.print("   Month = ");//month
  Serial.print(rtc.month);
  Serial.print("   Day = ");//day
  Serial.print(rtc.day);
  Serial.print("   Week = ");//week
  Serial.print(rtc.week);
  Serial.print("   Hour = ");//hour
  Serial.print(rtc.hour);
  Serial.print("   Minute = ");//minute
  Serial.print(rtc.minute);
  Serial.print("   Second = ");//second
  Serial.println(rtc.second);
  delay(1000);

}

