#include "functions.h"

float get_FloatUART(){
  float data;
  data = (Serial.available()) ? Serial.parseFloat() : data;
  return data;
}


float* get_Shell(String cmd){
  struct{
    int8_t headers_num = 4;
    int8_t data_num;
    char data_type;
    char header_separator = '/';
    char data_separator;
    char endChar;

    int8_t* ptr = &(this->data_num);
  }headers, *p;

  //Getting frame control information
  for(int i=0; i<headers.headers_num; i++){
    String aux = cmd.substring(0, cmd.indexOf(headers.header_separator));
    //headers.ptr[i] = (i==0) ? aux.toInt(): aux;
    cmd = cmd.substring(cmd.indexOf(headers.header_separator)+1);
  }
  /*  Paramteres number getted  */
/*
  float* frame = (float*) malloc(numParameters*sizeof(float));

  for (int i=0; cmd.indexOf(separator)>0; i++){
    aux = cmd.substring(0, cmd.indexOf(separator));
    frame[i]= aux.toFloat();
    cmd = cmd.substring(cmd.indexOf(separator)+1);
  }
  */
 float* frame;
  return frame;
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