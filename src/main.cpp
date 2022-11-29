#include <Arduino.h>
#include "PolynomFun/PolynomFun.h"
#include "tools/tools.h"

//><


void setup() {
  Serial.begin(9600);
  Serial.println(IntroducingText);
}

void loop() {
  if(Serial.available()>0) 
    Serial.println(get_FloatUART());
  
}  








