#include <Arduino.h>
#include "functions.h"

void setup() {
  Serial.begin(9600);
  Serial.println("\nIntroduce:\n\t num_parameters-degree-c0-c1-...-c_n-inc-fx_num-");
}

void loop() {
  if(Serial.available()>0){
    results_t results = get_ImagFunctions();
    for(int i=0; i<results.fx_num; i++){
      Serial.println(results.fx[i]);
    }
}
  

  /*float coefficient[6] = {5, 2};
  float data[DATA_NUM];

  mathFun(1, coefficient, data, 1.0, DATA_NUM);
  if(Serial.available())    
  if(printOnce){
    for (int i=0; i<DATA_NUM; i++){
      Serial.println(data[i]);
    }
    printOnce^=printOnce;
  }*/ 
}

