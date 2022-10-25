#include "Shell.h"

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