#include "tools.h"

float get_FloatUART(){
  float data;
  data = Serial.parseFloat();
  return data;
} 