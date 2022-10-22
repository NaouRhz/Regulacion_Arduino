// #include "functions.h"

// float get_FloatUART(){
//   float data;
//   data = (Serial.available()) ? Serial.parseFloat() : data;
//   return data;
// }


// float* get_cmdValues(String cmd, String separator){
//   float *data, *data_cpy;
//   int doOnce=true;
//   int numElem;
//   int i=0;

//   String aux = cmd.substring(0, cmd.indexOf(separator));
//   int numParameters = aux.toInt();
//   cmd = cmd.substring(cmd.indexOf(separator)+1);

//   float data[numParameters];

//   for (int i=0; cmd.indexOf(separator)>0; i++){
//     aux = cmd.substring(0, cmd.indexOf(separator));
//     data[i]= aux.toInt();
//     cmd = cmd.substring(cmd.indexOf(separator)+1);
//   }
//     /*if (doOnce){
//       int degree = aux.toInt();
//       Serial.print("aux-degree: "); Serial.println(degree);
//       numElem = degree+1+3;
//       Serial.print("numElem: "); Serial.println(numElem);
//       data = (float*)malloc(numElem*sizeof(float));
//       data_cpy = data;
//       doOnce=false;
//     }*/

    
//     Serial.print("*(data++): "); Serial.println(data[i]);
//     data[i] = aux.toFloat();
//     i++;
//     cmd = cmd.substring(cmd.indexOf(separator)+1);
    
//     if(cmd.indexOf(separator)<0){
//       *(data_cpy) = cmd.toFloat();
//       Serial.print("*(data++): "); Serial.println(*(data_cpy));
//     }   
  

//   return data;
// }


// results_t mathFun(float* ptrParameters){
//   float* ptrParameters_cpy = ptrParameters;

//   int degree = *(ptrParameters_cpy++);
//   Serial.print("Degree:"); Serial.println(degree);
  
//   float coeffi[degree];

//   for (int i=0; i<=degree; i++){
//     coeffi[i] = *(ptrParameters_cpy++);
//     Serial.print("C"); Serial.print(i); Serial.print(" :"); Serial.println(coeffi[i]);
//   }

//   float inc = *(ptrParameters_cpy++);
//   float x = inc;
//   Serial.print("inc:"); Serial.println(inc);

//   int y_num = *(ptrParameters_cpy);
//   Serial.print("y_num:"); Serial.println(y_num);

//   float* ptr_y = (float*) malloc(y_num*sizeof(float));


//   for(int n=0; n<y_num; n++){
//     ptr_y[n]=0;
//   }

//   ptr_y[0]=coeffi[0];

//   for(int j=1; j<y_num; j++){
//     for (int i=0; i<=degree; i++){
//       ptr_y[j] += (i==0) ? coeffi[0] : coeffi[i]*pow(x,i);
//     }
//     x+=inc;
//   }
  
//   return {ptr_y, y_num};
                                     
// }

// results_t get_ImagFunctions(){
//   String cmd =Serial.readString();
  
//   float*  ptrParameters = get_cmdValues(cmd, "-");
//   return mathFun(ptrParameters);
// }