 
#define AVR_BUILD

#include <Zumo32U4.h>
#include <Wire.h>
#include "model.hpp"

using namespace robo_utils;
using namespace robotieee;

L3G gyro;
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
model zumo_model = model{10, 10};

void setup() {

  //Hardware initialization
  Wire.begin();
  lcd.init();
  gyro.init();
  gyro.setTimeout(1000);
  gyro.enableDefault();

  //Gyroscope calibration
  lcd.print(F("Setup OK"));
  buttonA.waitForButton();
  lcd.clear();
  delay(1000);
  lcd.print(F("Wait..."));
  zumo_model.zumo_robot.calibrateGyroscope();

  //Rotation test
  lcd.clear();
  lcd.print(F("Reset"));
  lcd.gotoXY(0, 1);
  lcd.print(F("position"));
  buttonA.waitForButton();
  delay(1000);

  zumo_model.zumo_robot.rotate(180);
  zumo_model.zumo_robot.rotate(-180);

  lcd.clear();
  lcd.print(F("**DONE**"));
}

void loop() {
  
}
