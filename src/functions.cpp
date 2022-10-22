#include "functions.h"

float get_FloatUART(){
  float data;
  data = (Serial.available()) ? Serial.parseFloat() : data;
  return data;
}


float* get_cmdValues(String cmd, String separator){
  String aux = cmd.substring(0, cmd.indexOf(separator));
  int numParameters = aux.toInt();
  Serial.print("numParameters: "); Serial.println(numParameters);
  cmd = cmd.substring(cmd.indexOf(separator)+1);

  float* data = (float*) malloc(numParameters*sizeof(float));

  for (int i=0; cmd.indexOf(separator)>0; i++){
    aux = cmd.substring(0, cmd.indexOf(separator));
    data[i]= aux.toFloat();
    cmd = cmd.substring(cmd.indexOf(separator)+1);
  }
  
  return data;
}


results_t mathFun(float* data){
  int i=0;
  
  int degree = data[i++];
  Serial.print("degree: "); Serial.println(degree);

  float coeffi[degree+1];

  for (int j=0; j<=degree; j++){
    coeffi[j] = data[i++];
    Serial.print("C"); Serial.print(j); Serial.print(" :"); Serial.println(coeffi[j]);
  }

  float inc = data[i++];
  float x = inc;
  Serial.print("inc:"); Serial.println(inc);

  int fx_num = data[i];
  Serial.print("fx_num:"); Serial.println(fx_num);

  float* fx_results = (float*) malloc(fx_num*sizeof(float));


  for(int n=0; n<fx_num; n++){
    fx_results[n]=0;
  }

  fx_results[0]=coeffi[0];

  for(int j=1; j<fx_num; j++){
    for (int i=0; i<=degree; i++){
      fx_results[j] += (i==0) ? coeffi[0] : coeffi[i]*pow(x,i);
    }
    x+=inc;
  }
  
  return {fx_results, fx_num};
                                     
}

results_t get_ImagFunctions(){
  String cmd =Serial.readString();
  
  float* data = get_cmdValues(cmd, "-");
  return mathFun(data);
}