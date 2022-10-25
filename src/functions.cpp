#include "functions.h"

float get_FloatUART(){
  float data;
  data = (Serial.available()) ? Serial.parseFloat() : data;
  return data;
}


float* get_PolynoImages(int degree, float* coeffi, int images_num, float inc){
  //dynamic array assignment for results or images
  float* fx_results = (float*) malloc(images_num*sizeof(float));
  
  //Initialize results array (or images array)
  for(int n=0; n<images_num; n++){
    fx_results[n]=0;
  }
  
  fx_results[0]=coeffi[0];
  for(int j=1; j<images_num; j++){
    for (int i=0; i<=degree; i++){
      fx_results[j] += (i==0) ? coeffi[0] : coeffi[i]*pow(inc,i);
    }
    inc+=inc;
  }
  
  return fx_results;
                                     
}

results_t get_ImagFunctions(){
  /*String cmd =Serial.readString();
  
  float* data = get_cmdValues(cmd, "-");
  return mathFun(data);*/
}